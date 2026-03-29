#ifndef RPN_HPP
#define RPN_HPP
#include <string>


class RPN {
  public:
    static int evaluate(std::string const &expression);

  private:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
};

#endif
