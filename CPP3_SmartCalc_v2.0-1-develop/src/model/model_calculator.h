#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <map>
#include <stack>
#include <vector>

namespace s21 {

class Model {
 private:
  std::map<char, int> operationPriority = {
      {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'m', 3},
      {'^', 3}, {'q', 5}, {'c', 5}, {'s', 5}, {'t', 5}, {'a', 5},
      {'i', 5}, {'n', 5}, {'l', 5}, {'o', 5}, {'~', 4}, {'#', 4}};

 public:
  Model(){};
  ~Model(){};

  std::vector<std::string> InfixToPostfix(std::string infix);
  std::string InfixFunctionToChar(std::string infix);
  double Calculate(std::vector<std::string> postfix);

  std::string EqualBrackets(std::string infix);
  std::string XtoNumber(std::string infix, std::string x);
  double CalcOneOperation(double first, double second, char oper);
  std::string ReplayCovertFunction(std::string infix, std::string func,
                                   char symb);
};
}  // namespace s21

#endif  // MODEL_H
