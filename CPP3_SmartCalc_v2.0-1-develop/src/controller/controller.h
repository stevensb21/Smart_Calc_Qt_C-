#ifndef S21_SMART_CALC_V_2_0_SRC_CONTROLLER_CONTROLLER_H_
#define S21_SMART_CALC_V_2_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model_calculator.h"
#include "../model/model_creditcalc.h"

namespace s21 {

class Controller {
 public:
  Controller(s21::Model *m, s21::CreditDepo *c) : model(m), credit(c){};
  ~Controller() = default;

  void InfixToPostfix();
  double Calculate(std::string infix);
  double Calculate(std::string infix, std::string x);
  void credit_dif(double AmoCredit, int Term, double Interest, double *first,
                  double *Overpayments, double *Total, double *last);
  void credit_amu(double AmoCredit, int Term, double Interest,
                  double *MounPayments, double *Overpayments, double *Total);

 private:
  s21::Model *model;
  s21::CreditDepo *credit;
};
}  // namespace s21

#endif  // S21_SMART_CALC_V_2_0_SRC_CONTROLLER_CONTROLLER_H_
