#include "model_calculator.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace s21;

double Model::Calculate(std::vector<std::string> postfix) {
  for (auto it(postfix.begin()); it != postfix.end(); it++) {
    if (operationPriority[it->back()] < 4 &&
        operationPriority[it->back()] > 0) {
      if (it - postfix.begin() < 2) return NAN;
      auto first = it - 2;
      auto second = it - 1;
      double res =
          CalcOneOperation(std::stold(*first), std::stold(*second), it->back());
      *first = std::to_string(res);
      postfix.erase(it);
      postfix.erase(second);
      it = postfix.begin();

    } else if (operationPriority[it->back()] > 3) {
      if (it - postfix.begin() < 1 || !isdigit((it - 1)->back())) return NAN;
      auto first = it - 1;
      double res = CalcOneOperation(std::stold(*first), 0, it->back());
      *first = std::to_string(res);
      postfix.erase(it);
      it = postfix.begin();
    }
  }

  return std::stod(postfix.front());
}

std::string Model::EqualBrackets(std::string infix) {
  int countOpen = std::count(infix.begin(), infix.end(), '(');
  int countClose = std::count(infix.begin(), infix.end(), ')');
  if (countOpen > countClose) {
    while (countOpen != countClose) {
      infix += ')';
      countClose++;
    }
  } else {
    std::string tmp = "";
    while (countOpen != countClose) {
      tmp += '(';
      countOpen++;
    }
    infix = tmp + infix;
  }
  return infix;
}

double Model::CalcOneOperation(double first, double second, char oper) {
  if (oper == '+') return first + second;
  if (oper == '-') return first - second;
  if (oper == '*') return first * second;
  if (oper == '/') return first / second;
  if (oper == '^') return pow(first, second);
  if (oper == 'm') return int(first) % int(second);
  if (oper == 'q') return sqrt(first);
  if (oper == 'c') return cos(first);
  if (oper == 's') return sin(first);
  if (oper == 't') return tan(first);
  if (oper == 'a') return acos(first);
  if (oper == 'i') return asin(first);
  if (oper == 'n') return atan(first);
  if (oper == 'l') return log(first);
  if (oper == 'o') return log10(first);
  if (oper == '~') return first * (-1);
  if (oper == '#') return first;

  throw("Error");
}

std::string Model::XtoNumber(std::string infix, std::string x) {
  while (infix.find("x") != std::string::npos) {
    infix.replace(infix.find("x"), 1, x);
  }

  return infix;
}

std::string Model::ReplayCovertFunction(std::string infix, std::string func,
                                        char symb) {
  while (infix.find(func) != std::string::npos) {
    std::string c(1, symb);
    infix.replace(infix.find(func), func.size(), c);
  }
  return infix;
}

std::string Model::InfixFunctionToChar(std::string infix) {
  infix = ReplayCovertFunction(infix, "cos", 'c');

  infix = ReplayCovertFunction(infix, "sin", 's');

  infix = ReplayCovertFunction(infix, "tan", 't');

  infix = ReplayCovertFunction(infix, "mod", 'm');

  infix = ReplayCovertFunction(infix, "sqrt", 'q');

  infix = ReplayCovertFunction(infix, "ln", 'l');

  infix = ReplayCovertFunction(infix, "log", 'o');

  infix = ReplayCovertFunction(infix, "ac", 'a');

  infix = ReplayCovertFunction(infix, "as", 'i');

  infix = ReplayCovertFunction(infix, "at", 'n');

  return infix;
}

std::vector<std::string> Model::InfixToPostfix(std::string infix) {
  std::string Postfix = "";
  std::vector<std::string> post;
  std::vector<char> operators;

  for (unsigned long i = 0; i < infix.size(); i++) {
    char c = infix[i];
    unsigned long k = infix.size();
    k -= 1;

    if (isdigit(c)) {
      while (i <= k && (isdigit(infix[i]) || infix[i] == '.')) {
        Postfix += infix[i];
        i++;
      }
      i -= 1;
      post.push_back(Postfix);
      Postfix = "";
    } else if (c == '(') {
      operators.insert(operators.begin(), c);
    } else if (c == ')') {
      while (!operators.empty() && *operators.begin() != '(') {
        std::string tmp;
        tmp += operators.front();
        post.push_back(tmp);
        operators.erase(operators.begin());
      }
      operators.erase(operators.begin());
    } else if (operationPriority.count(c)) {
      char op = c;
      if (op == '-' && (i == 0 || (i >= 1 && infix[i - 1] == '('))) op = '~';
      if (op == '+' && (i == 0 || (i >= 1 && infix[i - 1] == '('))) op = '#';
      while (!operators.empty() &&
             (operationPriority[*operators.begin()] >= operationPriority[op])) {
        std::string tmp;
        tmp += operators.front();
        post.push_back(tmp);
        operators.erase(operators.begin());
      }
      operators.insert(operators.begin(), op);
    }
  }
  while (!operators.empty()) {
    std::string tmp;
    if (operators.front() == '(') operators.erase(operators.begin());
    tmp += operators.front();
    post.push_back(tmp);
    operators.erase(operators.begin());
  }

  operators.clear();
  return post;
}
