#include "mainwindow.h"
#include "ui_creditcalc.h"
using namespace s21;

CreditCalc::CreditCalc(QWidget* parent, s21::Controller* controller)
    : QWidget(parent), ui(new Ui::CreditCalc), controller_(controller) {
  ui->setupUi(this);
  setWindowTitle("Credit");
  setFixedSize(geometry().width(), geometry().height());
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_calculate_clicked() {
  double sum = ui->sum_credit->value();
  int deadline = ui->deadline_credit->value();
  double percent = ui->percent_credit->value();
  double FirstPayments = 0.0;
  double Overpayment = 0.0;
  double Total = 0.0;
  double LastPayments = 0.0;
  if (ui->year_or_month->currentIndex() == YEAR) deadline *= 12;

  if (ui->radioButton_ann->isChecked()) {
    controller_->credit_amu(sum, deadline, percent, &FirstPayments,
                            &Overpayment, &Total);
    ui->label_monthly_pay_result->setText(QString::number(FirstPayments));
  } else {
    controller_->credit_dif(sum, deadline, percent, &FirstPayments,
                            &Overpayment, &Total, &LastPayments);
    ui->label_monthly_pay_result->setText(QString::number(FirstPayments));
  }

  ui->label_overpayment_result->setText(QString::number(Overpayment));
  ui->label_last_pay_result->setText(QString::number(LastPayments));
  ui->label_total_sum_result->setText(QString::number(Total));
}

void CreditCalc::on_year_or_month_activated(int index) {
  if (index == YEAR)
    ui->deadline_credit->setMaximum(50);
  else if (index == MONTH)
    ui->deadline_credit->setMaximum(600);
}
