#include "Replacer.hpp"

int main() {
    std::string inputFile = "test.txt";
    std::string originalText = R"(This is a test file, containing things to be replaced
Including newlines
091231a

asd
is)"; //wrapping in R"(...)" is a simple way to make strings containing newlines. "Raw string literal".

	std::ofstream out(inputFile);
    out << originalText;
    out.close();
    std::cout << "Created input file: " << inputFile << std::endl;

	//create a shell script for testing
	std::string script = R"SH(#!/bin/bash

INPUT="test.txt"
OUTPUT="test.txt.replace"
EXE="./replace"

# A helper function to print results
check_result() {
	local EXIT_CODE=$1
    echo "   [Exit Code]: $EXIT_CODE"
    if [ -f "$OUTPUT" ]; then
        echo "   [Output File Content]:"
        cat "$OUTPUT"
        echo ""
    else
		if [ "$EXIT_CODE" -eq 0 ]; then
	        echo "   [Error]: Output file was not created despite return value 0."
		fi
    fi
    echo "----------------------------------------------------"
}

echo "=== STARTING TESTS ==="
echo ""

# Case 1: Standard replacement
echo "[Test 1] Simple replacement: 'is' -> 'WAS'"
$EXE "$INPUT" "is" "WAS"
CODE=$?
check_result $CODE
rm -f "$OUTPUT"

# Case 2: Newline in target string
echo "[Test 2] Replace newline with space"
$EXE "$INPUT" "
" " "
CODE=$?
check_result $CODE
rm -f "$OUTPUT"

# Case 3: Empty Target
echo "[Test 3] Empty target string"
$EXE "$INPUT" "" "replacement"
CODE=$?
check_result $CODE
rm -f "$OUTPUT"

# Case 4: Empty Replacement
echo "[Test 4] Replace 'is' with empty string"
$EXE "$INPUT" "is" ""
CODE=$?
check_result $CODE
rm -f "$OUTPUT"

# Case 5: No Read Permissions on Input
echo "[Test 5] Input file unreadable"
chmod -r "$INPUT"
$EXE "$INPUT" "is" "WAS"
CODE=$?
check_result $CODE
rm -f "$OUTPUT"
chmod +r "$INPUT" 


# Case 6: No Write Permissions on Output
echo "[Test 6] Output file exists but is not writable"
touch "$OUTPUT"
chmod -w "$OUTPUT"
$EXE "$INPUT" "is" "WAS"
CODE=$?
check_result $CODE
chmod +w "$OUTPUT"
rm -f "$OUTPUT"

echo "=== ALL TESTS COMPLETED ==="
)SH";

	std::ofstream scriptFile("run_tests.sh");
    scriptFile << script;
    scriptFile.close();

	std::cout << "Created script file: run_tests.sh" << std::endl;
	return 0;
}
