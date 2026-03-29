#include "RPN.hpp"
#include <string>
#include <stack>
#include <sstream>

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
    std::istringstream  iss(expression);
    std::string         token;
    std::string         operands = "+-*/";
    std::stack<int>     stack;

    while (iss >> token) { //'>>' on a stringstream reads until the next whitespace, skipping any leading whitespace.
        if (token.length() > 1) {
            throw std::runtime_error("Error: invalid token '" + token + "'");
        }
        char c = token[0];
        if (std::isdigit(c)) {
            int value = c - '0';
            stack.push(value);
        } else if (operands.find(c) != std::string::npos){ //c is one of the implemented operands
            if (stack.size() < 2) {
                throw std::runtime_error("Error: ran out of values to operate on");
            }
            int rightArg = stack.top(); stack.pop();
            int leftArg = stack.top(); stack.pop();
            int result;
            switch (c){
                case '+': result = leftArg + rightArg; break;
                case '-': result = leftArg - rightArg; break;
                case '*': result = leftArg * rightArg; break;
                case '/':
                    if (rightArg == 0) { throw std::runtime_error("Error: division by zero"); }
                    result = leftArg / rightArg;
                    break;
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
