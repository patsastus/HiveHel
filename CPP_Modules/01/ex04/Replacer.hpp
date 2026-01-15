#ifndef REPLACER_HPP
#define REPLACER_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

class Replacer {
	public:
		static void searchAndReplace(std::ifstream& infile, std::ofstream& outfile, const std::string& target, const std::string& replacement);
		static int run(int argc, char *argv[]);
	private:
		Replacer() = delete;
};
#endif // REPLACER_HPP
