#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const std::string &dataPath) {
    std::ifstream dataFile(dataPath.c_str());
    if (!dataFile.is_open()) {
        throw std::runtime_error("Failed to open data file: " + dataPath);
    }
    parseDataBaseFile(dataFile);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void    BitcoinExchange::parseDataBaseFile(std::ifstream& File){
    std::string Line;
    if (!std::getline(File, Line) || Line != "date,exchange_rate") {
        throw std::runtime_error("Error: invalid database header.");
    }

    while (std::getline(File, Line)) {
        if (Line.empty()) continue;

        size_t Delim = Line.find(',');
        if (Delim == std::string::npos) continue;

        std::string_view DatePart(Line.data(), Delim);
        std::string_view RatePart(Line.data() + Delim + 1, Line.size() - Delim - 1);

        Date Ymd = parseDate(DatePart);
        if (!Ymd.ok()) {
            std::cerr << "Warning: invalid date in database: " << DatePart << std::endl;
            continue;
        }

        float Rate;
        auto ReturnStruct = std::from_chars(RatePart.data(), RatePart.data() + RatePart.size(), Rate);
        if (ReturnStruct.ec != std::errc{} || !std::isfinite(Rate) || Rate < 0.0f) {
            std::cerr << "Warning: invalid rate for date " << DatePart << ": " << RatePart << std::endl;
            continue;
        } else {
            dataBase_[Ymd] = Rate;
        }
    }
}

Date    BitcoinExchange::parseDate(const std::string_view& date){
    if (date.size() < 10 || date[4] != '-' || date[7] != '-') {
        return {}; // Invalid date
    }

    int Y;
    unsigned int M, D;

    //from_chars converts char sequences to numeric values. Takes startpointer, endpointer, and target var.
    auto ResY = std::from_chars(date.data(), date.data() + 4, Y); //the auto type is a struct that from_chars returns, we use the error code
    auto ResM = std::from_chars(date.data() + 5, date.data() + 7, M);
    auto ResD = std::from_chars(date.data() + 8, date.data() + 10, D);

    //std::errc{} is the default-constructed error code, which represents no error.
    if (ResY.ec != std::errc{} || ResM.ec != std::errc{} || ResD.ec != std::errc{}) {
        return {}; // Invalid date
    }

    return Date{ //Numeric date, might still be wrong (e.g. month 13, day 42)
        std::chrono::year{Y},
        std::chrono::month{M},
        std::chrono::day{D}
    };
}

void    BitcoinExchange::parseInputFile(std::ifstream& File){
    std::string Line;
    if (!std::getline(File, Line) || Line != "date | value") {
        throw std::runtime_error("Error: invalid file header.");
    }

    while (std::getline(File, Line)) {
        if (Line.empty()) {
            std::cerr << "Error: empty line." << std::endl;
            continue;
        }
        size_t Delim = Line.find(" | ");
        if (Delim == std::string::npos) {
            std::cerr << "Error: invalid line format: " << Line << std::endl;
            continue;
        }
        std::string_view DatePart(Line.data(), Delim);
        std::string_view AmountPart(Line.data() + Delim + 3, Line.size() - Delim - 3);

        Date Ymd = parseDate(DatePart);
        if (!Ymd.ok()) {
            std::cerr << "Error: invalid date: " << DatePart << std::endl;
            continue;
        }

        float Amount;
        auto ReturnStruct = std::from_chars(AmountPart.data(), AmountPart.data() + AmountPart.size(), Amount);
        if (ReturnStruct.ec != std::errc{} || ReturnStruct.ptr !=  AmountPart.data() + AmountPart.size()
            || !std::isfinite(Amount) || Amount < 0.0f || Amount > 1000.0f) {
            std::cerr << "Error: invalid amount for date " << DatePart << ": " << AmountPart << std::endl;
            continue;
        } else {
            if (Ymd < dataBase_.begin()->first) { //first date in database
                std::cerr << "Error: earlier than earliest date in database: " << DatePart << std::endl;
                continue;
            } else if (Ymd > dataBase_.rbegin()->first) { //last date in database
                std::cerr << "Error: later than latest date in database: " << DatePart << std::endl;
                continue;
            }
            float Cost = rateLookup(Ymd);
            std::cout << DatePart << " => " << Amount << " = " << std::format("{:.2f}",(static_cast<double>(Amount) * Cost)) << std::endl;
        }
    }
}

float   BitcoinExchange::rateLookup(const Date &d) const{
    auto It = dataBase_.upper_bound(d); //first entry > d, could be end()
    --It; // Move back to the largest date <= d
    return It->second;
}
