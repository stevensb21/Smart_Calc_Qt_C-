#include "controller.h"
using namespace s21;

double Controller::Calculate(std::string infix) {
  std::string r = model->InfixFunctionToChar(infix);
  r = model->EqualBrackets(r);
  std::vector<std::string> res = model->InfixToPostfix(r);

  double result = model->Calculate(res);
  return result;
}

double Controller::Calculate(std::string infix, std::string x) {
  std::string r = model->InfixFunctionToChar(infix);
  if (r[0] == ' ') r.erase(r.begin());
  r = model->EqualBrackets(r);
  r = model->XtoNumber(r, x);
  std::vector<std::string> res = model->InfixToPostfix(r);
  double result = model->Calculate(res);

  return result;
}

void Controller::credit_dif(double AmoCredit, int Term, double Interest,
                            double *first, double *Overpayments, double *Total,
                            double *last) {
  credit->CalcCreditDif(AmoCredit, Term, Interest, first, Overpayments, Total,
                        last);
}

void Controller::credit_amu(double AmoCredit, int Term, double Interest,
                            double *MounPayments, double *Overpayments,
                            double *Total) {
  credit->CalcCreditAmu(AmoCredit, Term, Interest, MounPayments, Overpayments,
                        Total);
}
