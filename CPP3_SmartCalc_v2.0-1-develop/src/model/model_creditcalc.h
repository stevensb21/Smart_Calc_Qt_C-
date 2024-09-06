#ifndef S21_SMART_CALC_V_2_0_SRC_MODEL_CREDITCALC_H_
#define S21_SMART_CALC_V_2_0_SRC_MODEL_CREDITCALC_H_

#include <math.h>

#include <iostream>

namespace s21 {

class CreditDepo {
 public:
  CreditDepo(){};
  ~CreditDepo() = default;

  void CalcCreditDif(double AmoCredit, int Term, double Interest, double *first,
                     double *Overpayments, double *Total, double *last);

  void CalcCreditAmu(double AmoCredit, int Term, double Interest,
                     double *MounPayments, double *Overpayments, double *Total);
};
}  // namespace s21

#endif  // S21_SMART_CALC_V_2_0_SRC_MODEL_CREDITCALC_H_