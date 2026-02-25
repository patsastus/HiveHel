#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <map>
#include <fstream>
#include <chrono>
#include <string>
#include <cmath>
#include <cmath>
#include <format>
#include <stdexcept>
#include <iostream>


typedef typename std::chrono::year_month_day Date;

class BitcoinExchange {
  public:
    BitcoinExchange(const std::string &dataPath);
    ~BitcoinExchange();
    void    parseInputFile(std::ifstream& inputFile);

  private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    std::map<Date, float>   dataBase_;

    Date    parseDate(const std::string_view& dateStr);
    void    parseDataBaseFile(std::ifstream& dataFile);
    float   rateLookup(const Date &d) const;
};

#endif
