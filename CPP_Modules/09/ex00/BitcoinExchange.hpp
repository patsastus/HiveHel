#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <map>
#include <fstream>
#include <chrono>
#include <string>

typedef typename std::chrono::year_month_day Date;

class BitcoinExchange {
  public:
    BitcoinExchange(const std::string &dataPath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(BitcoinExchange other);
    ~BitcoinExchange();
    void    parseInputFile(std::ifstream& inputFile);

  private:
    BitcoinExchange();
    std::map<Date, float>   dataBase_;

    Date    parseDate(const std::string_view& dateStr);
    void    parseDataBaseFile(std::ifstream& dataFile);
    float   rateLookup(const Date &d) const;
};

#endif
