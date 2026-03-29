#include <iostream>
#include <string>
#include "RPN.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

void testCases(){
    std::string tests[] = {
        "3 4 +", // (3 + 4) = 7
        "5 1 2 + 4 * + 3 -", // ((5 + ((1 + 2) * 4)) - 3) = 14
        "2 3 * 5 4 * +", // ((2 * 3) + (5 * 4)) = 22
        "7 2 /", // (7 / 2) = 3
        "8 0 /", // Error: division by zero
        "1 2 + +", // Error: ran out of values to operate on
        "9 x +", // Error: invalid token 'x'
        "4 5", // Error: too many values left on the stack
        "40 5" // Error: invalid token '40'
    };

    for (const auto &test : tests) {
        try {
            std::cout << COLOR_GREEN << test << COLOR_RESET << std::endl;
            int result = RPN::evaluate(test);
            std::cout << result << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cerr << COLOR_GREEN << "Running predetermined tests, provide one argument string to skip" << COLOR_RESET << std::endl;
    //    testCases();
        return 0;
    }
    try {
        std::string expression = argv[1];
        int result = RPN::evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
