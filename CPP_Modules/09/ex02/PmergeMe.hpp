#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <charconv>
#include <cstddef>
#include <list>
#include <stdexcept>
#include <string_view>
#include <unordered_set>
#include <vector>

extern size_t gComparisons; // for tracking the number of comparisons

struct vectorNode {
  unsigned int value;
  std::vector<vectorNode> losers;

  bool operator<(const vectorNode &other) const;
};

struct listNode {
  unsigned int value;
  std::list<listNode> losers;

  bool operator<(const listNode &other) const;
};

class PMergeMe {
public:
  template <typename Container = std::vector<unsigned int>>
  static Container parseInput(int argc, char *argv[]) {
    Container results;
    std::unordered_set<unsigned int> seenValues;
    // If the container supports it, reserve the needed space
    if constexpr (requires { results.reserve(1); }) {
      results.reserve(argc - 1);
    }
    seenValues.reserve(argc - 1);

    for (int i = 1; i < argc; ++i) {
      unsigned int value = 0;
      std::string_view arg = argv[i];

      auto [ptr, ec] =
          std::from_chars(arg.data(), arg.data() + arg.size(), value);
      if (ec == std::errc() && ptr == arg.data() + arg.size() &&
          value > 0 && seenValues.insert(value).second) { //input was a valid number, > 0, and not seen before
        // inserting into set returns pair<iterator, bool>,
        // so .second==true <=> value was not already in set
        results.push_back(value);
      } else {
        std::string m = "Invalid input: " + std::string(arg);
        throw std::invalid_argument(m);
      }
    }
    return results;
  }
  static std::vector<vectorNode> vectorMergeSort(std::vector<vectorNode> &input);
  static std::list<listNode> listMergeSort(std::list<listNode> &input);

private:
  PMergeMe();
  PMergeMe(const PMergeMe &other);
  PMergeMe &operator=(const PMergeMe &other);
  ~PMergeMe();
};

#endif
