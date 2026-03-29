#include <iostream>
#include <optional>
#include "BitcoinExchange.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

int main(int argc, char *argv[]){

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::optional<BitcoinExchange> btc; // Use std::optional to handle potential initialization failure
    try {
        btc.emplace("../data.csv"); //emplace constructs the BitcoinExchange object in-place, allowing us to catch exceptions if the constructor fails
    } catch (const std::exception &e) {
        std::cerr << "Error initializing BitcoinExchange: " << e.what() << std::endl;
        return 1;
    }

    try {
        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Failed to open input file: " + std::string(argv[1]));
        }
        btc->parseInputFile(inputFile);
    } catch (const std::exception &e) {
            std::cerr << "Error running BitcoinExchange: " << e.what() << std::endl;
            return 1;
    }
    std::cout << "" << std::endl;
	return 0;
}
