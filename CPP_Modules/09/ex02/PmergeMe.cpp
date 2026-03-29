#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>
#include <optional>

size_t gComparisons = 0;

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &other) { *this = other; }

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
  if (this != &other) {
  }
  return *this;
}

PMergeMe::~PMergeMe() {}

bool PMergeMe::vectorNode::operator<(vectorNode const &other) const{
     ++gComparisons;  //count comparisons
     return this->value < other.value;
}

PMergeMe::vectorNode::vectorNode() : value(0)   {}  ;

PMergeMe::vectorNode::vectorNode(unsigned int val, std::vector<vectorNode> los) : value(val), losers(los) {};

bool PMergeMe::listNode::operator<(const listNode& other) const{
     ++gComparisons;  //count comparisons
     return this->value < other.value;
 }

 PMergeMe::listNode::listNode() : value(0) {};

 PMergeMe::listNode::listNode(unsigned int val, std::list<listNode> los) : value(val), losers(los) {};


static size_t getJacobstahl(size_t n) {
  if (n <= 1)
    return n; // 0 -> 0, 1 -> 1
  size_t a = 0, b = 1, c;
  for (size_t i = 2; i <= n;
       ++i) { // Jacobstahl: J_n = J_(n-1) + 2*J_(n-2) <=> c = b + 2*a
    c = b + 2 * a;
    a = b;
    b = c;
  }
  return b;
}

static std::vector<size_t> getInsertSequence(size_t vectorSize) {
  if (vectorSize <= 1)
    return {}; // the first loser is inserted outside sequence, so nothing to do
               // if vectorSize == 1
  std::vector<size_t> sequence;
  sequence.reserve(vectorSize - 1);

  // pair 1 (k == 2) is handled in main loop, so we start at k == 3
  for (size_t k = 3; sequence.size() < vectorSize - 1; ++k) {
    size_t stop = getJacobstahl(k - 1);
    size_t start = getJacobstahl(k);
    for (size_t j = std::min(start, vectorSize);
         j > stop && sequence.size() < vectorSize - 1; --j) {
      sequence.push_back(j - 1); // jacobstahl numbers are 1-starting, this
                                 // converts it to 0-starting indices
    }
  }
  return sequence;
}

std::vector<PMergeMe::vectorNode> PMergeMe::vectorMergeSort(std::vector<PMergeMe::vectorNode> &input) {
  if (input.size() < 2)
    return input;

  //split into pairs
  size_t numPairs = input.size() / 2;
  std::vector<PMergeMe::vectorNode> pairs;
  pairs.reserve(numPairs);
  for (size_t i = 0; i < numPairs; ++i) { //std::move everywhere so we don't do deep copies
    PMergeMe::vectorNode t1 = std::move(input[2 * i]), t2 = std::move(input[2 * i + 1]);
    if (t1 < t2) {
      t2.losers.push_back(std::move(t1));
      pairs.push_back(std::move(t2));
    } else {
      t1.losers.push_back(std::move(t2));
      pairs.push_back(std::move(t1));
    }
  }
  pairs = vectorMergeSort(pairs); // use this same function to sort winners

  // make the return vector
  std::vector<PMergeMe::vectorNode> mainChain;
  mainChain.reserve(input.size());

  // lookup table to avoid comparisons
  std::vector<size_t> posLookup;
  posLookup.reserve(pairs.size());

  // insert first loser and all winners
  mainChain.push_back(std::move(pairs[0].losers.back()));
  pairs[0].losers.pop_back();
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(std::move(pairs[i])); //std::move means pairs[i] is undefined after this
    posLookup.push_back(i + 1); // the winners start at i+1 because first loser is at 0
  }

  //check for a straggler not included in pairs
  std::optional<PMergeMe::vectorNode> straggler;
  if (input.size() % 2) {
      straggler = std::move(input.back());
      input.pop_back();
  }

  // generate insert sequence and insert losers
  // if there is a straggler, treat it as another loser, at last index
  size_t numLosers = pairs.size() + (straggler.has_value() ? 1 : 0);
  std::vector<size_t> seq = getInsertSequence(numLosers);
  for (size_t index : seq) {
      PMergeMe::vectorNode loser;
      size_t rangeEnd;

     if (index == pairs.size() && straggler.has_value()){
         loser = std::move(*straggler); //need to dereference an optional to get the value
         rangeEnd = mainChain.size();
     } else {
        rangeEnd = posLookup[index];//"vectorNode at index in pairs now lives at rangeEnd of mainChain"
        loser = std::move(mainChain[rangeEnd].losers.back());
        mainChain[rangeEnd].losers.pop_back();
        // could instead do std::find(mainChain.begin(), mainChain.end(), pairs[index].value)
        // but that would involve re-comparisons
     }

    // std::upper_bound performs a binary search, and returns an iterator to insert at
    auto it = std::upper_bound(mainChain.begin(), mainChain.begin() + rangeEnd, loser);
    size_t insertedAt = std::distance(mainChain.begin(), it);
    mainChain.insert(it, std::move(loser));

    // Update the table: everything at or after insertedAt shifted right by 1
    for (size_t &p : posLookup) {
      if (p >= insertedAt)
        p++;
    }
  }
 return mainChain;
}

 std::list<PMergeMe::listNode> PMergeMe::listMergeSort(std::list<PMergeMe::listNode> &input) {
    if (input.size() < 2)
      return input;
    //split into pairs
    size_t numPairs = input.size() / 2;
    std::list<PMergeMe::listNode> pairs;
    for (size_t i = 0; i < numPairs; ++i) {
      PMergeMe::listNode t1 = std::move(input.front());
      input.pop_front();
      PMergeMe::listNode t2 = std::move(input.front());
      input.pop_front();
      if (t1 < t2) {
          t2.losers.push_back(std::move(t1));
          pairs.push_back(std::move(t2));
      } else {
          t1.losers.push_back(std::move(t2));
          pairs.push_back(std::move(t1));
      }
    }
    pairs = listMergeSort(pairs); // use this same function to sort winners;

    std::list<PMergeMe::listNode> mainChain;
    std::vector<std::list<PMergeMe::listNode>::iterator> winnerIterators;
    winnerIterators.reserve(numPairs);

    //add first loser and all winners to mainChain, store winner iterators
    mainChain.push_back(std::move(pairs.front().losers.back()));
    pairs.front().losers.pop_back();
    for (auto it = pairs.begin(); it != pairs.end(); ++it){
        mainChain.push_back(std::move(*it));
        winnerIterators.push_back(std::prev(mainChain.end())); //iterator to the last listNode
    }

    std::optional<PMergeMe::listNode> straggler;
    if (input.size() % 2) {
        straggler = std::move(input.back());
        input.pop_back();
    }

    // generate insert sequence and insert losers
    size_t numLosers = pairs.size() + (straggler.has_value() ? 1 : 0); //if there is a straggler,
    //treat it as another loser, at last index
    std::vector<size_t> seq = getInsertSequence(numLosers);
    for (size_t index : seq){
        PMergeMe::listNode loser;
        std::list<PMergeMe::listNode>::iterator rangeEnd;

       if (straggler.has_value() && index == pairs.size()){
           loser = std::move(*straggler); //need to dereference an optional to get the value
           rangeEnd = mainChain.end();
       } else {
          rangeEnd = winnerIterators[index];//With std::list, iterators remain valid always, so no updating
          loser = std::move(rangeEnd->losers.back());
          rangeEnd->losers.pop_back();
       }
      // std::upper_bound performs a binary search, even on a linked list
      auto it = std::upper_bound(mainChain.begin(), rangeEnd, loser);
      mainChain.insert(it, std::move(loser));
    }
    return mainChain;
 }
