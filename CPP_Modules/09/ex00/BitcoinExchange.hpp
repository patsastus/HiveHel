#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <map>
#include <algorithm>
#include <chrono>
#include <string>


typedef typename std::chrono::system_clock::time_point Date;

class BitcoinExchange {
  public:
    BitcoinExchange(std::string dataPath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

  private:
    BitcoinExchange();
    std::map<Date, int>   dataBase_;

    void    readDataBase(std::string path);
    int     lookup(const Date &d) const;
};

#endif
