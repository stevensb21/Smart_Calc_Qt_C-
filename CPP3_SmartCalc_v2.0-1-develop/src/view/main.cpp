#include <QApplication>
#include <clocale>

#include "../controller/controller.h"
#include "../model/model_calculator.h"
#include "../model/model_creditcalc.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  std::setlocale(LC_NUMERIC, "POSIX");

  s21::Model calc;
  s21::CreditDepo model_credit;
  s21::Controller controller(&calc, &model_credit);
  MainWindow w(nullptr, &controller);
  w.show();
  return a.exec();
}
