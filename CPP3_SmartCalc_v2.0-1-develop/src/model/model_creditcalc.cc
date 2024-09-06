#include "model_creditcalc.h"

using namespace s21;

void CreditDepo::CalcCreditDif(double AmoCredit, int Term, double Interest,
                               double *first, double *Overpayments,
                               double *Total, double *last) {
  double MouPay = 0;

  Interest /= 100;
  MouPay = AmoCredit / (double)Term;
  *first = MouPay + (AmoCredit - (MouPay * (double)0)) * Interest / 12;

  for (int i = 0; i < Term; i++) {
    *Total += MouPay + (AmoCredit - (MouPay * (double)i)) * Interest / 12;
    *last = MouPay + (AmoCredit - (MouPay * (double)i)) * Interest / 12;
  }
  *Overpayments = *Total - AmoCredit;
}

void CreditDepo::CalcCreditAmu(double AmoCredit, int Term, double Interest,
                               double *MounPayments, double *Overpayments,
                               double *Total) {
  Interest /= 100;
  double p = Interest / 12;

  *MounPayments = AmoCredit * (p / (1 - pow((1 + p), (double)-Term)));

  *Total = *MounPayments * (double)Term;
  *Overpayments = *Total - AmoCredit;
}