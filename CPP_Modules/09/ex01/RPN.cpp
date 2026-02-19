#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN &other) {
  *this = other;
}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
  }
  return *this;
}

RPN::~RPN() {
}

int RPN::evaluate(std::string const &expression){
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> stack;

    while (iss >> token) { //'>>' on a stringstream reads until the next whitespace, skipping any leading whitespace.
        if (token.length() > 1) {
            throw std::runtime_error("Error: invalid token '" + token + "'");
        }
        if (std::isdigit(token[0])) {
            int value = token[0] - '0';
            stack.push(value);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: ran out of values to operate on");
            }
            int rightArg = stack.top(); stack.pop();
            int leftArg = stack.top(); stack.pop();
            int result;

            if (token == "+") result = leftArg + rightArg;
            else if (token == "-") result = leftArg - rightArg;
            else if (token == "*") result = leftArg * rightArg;
            else if (token == "/") {
                if (rightArg == 0) {
                    throw std::runtime_error("Error: division by zero");
                }
                result = leftArg / rightArg;
            }
            stack.push(result);
        } else {
            throw std::runtime_error("Error: invalid token '" + token + "'");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: too many values left on the stack");
    }
    return stack.top();
}
