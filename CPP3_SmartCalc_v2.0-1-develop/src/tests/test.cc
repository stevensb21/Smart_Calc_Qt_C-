#include "../controller/controller.h"
#include "../model/model_calculator.h"
#include "../model/model_creditcalc.h"
#include "gtest/gtest.h"
#include "stdlib.h"
using namespace s21;

TEST(S21_Smart_Calc, test_1) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2+2*2-2";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 4, 1e-7);
}

TEST(S21_Smart_Calc, test_2) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "sin(5)^2+cos(5)^2";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 0.99999899999999997, 1e-7);
}

TEST(S21_Smart_Calc, test_3) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "acos(-1)*2^2^2";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 50.265487999999998, 1e-7);
}

TEST(S21_Smart_Calc, test_4) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2/6*5mod3+10-9";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 1.666666, 1e-7);
}

TEST(S21_Smart_Calc, test_5) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "-5+cos(10)*sin(1)/tan(1)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, -5.4533529999999999, 1e-7);
}

TEST(S21_Smart_Calc, test_6) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "((ln(10)*2)+2)/2";
  double res = controller.Calculate(input_str);

  EXPECT_NEAR(res, 3.3025850, 1e-7);
}

TEST(S21_Smart_Calc, test_7) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "5mod3*10/15+6+atan(5)";
  double res = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res), "8.706734");
}

TEST(S21_Smart_Calc, test_8) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "sin()";
  double res = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res), "nan");
}

TEST(S21_Smart_Calc, test_9) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "sin(5";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, -0.958924, 1e-7);
}

TEST(S21_Smart_Calc, test_10) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "asin(1)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 1.5707960000000001, 1e-7);
}

TEST(S21_Smart_Calc, test_11) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "sqrt(4)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 2, 1e-7);
}

TEST(S21_Smart_Calc, test_12) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "log(10)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 1, 1e-7);
}

TEST(S21_Smart_Calc, test_13) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2+1.2";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 3.20000000, 1e-7);
}

TEST(S21_Smart_Calc, test_14) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(2+2)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 4, 1e-7);
}

TEST(S21_Smart_Calc, test_15) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(2)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 2, 1e-7);
}

TEST(S21_Smart_Calc, test_16) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "123/123";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 1, 1e-7);
}

TEST(S21_Smart_Calc, test_17) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "1+1)+1";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 3, 1e-7);
}

TEST(S21_Smart_Calc, test_19) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(+)";
  double res = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res), "nan");
}

TEST(S21_Smart_Calc, test_20) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2*(2+2)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 8, 1e-7);
}

TEST(S21_Smart_Calc, test_22) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "sin(5)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, -0.958924, 1e-7);
}

TEST(S21_Smart_Calc, test_23) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2+";
  double res = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res), "nan");
}

TEST(S21_Smart_Calc, test_24) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "2+2*sin(2)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 3.818594, 1e-7);
}

TEST(S21_Smart_Calc, test_25) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "1+6)+3";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 10, 1e-7);
}

TEST(S21_Smart_Calc, test_26) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(*)";
  double res2 = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res2), "nan");
}

TEST(S21_Smart_Calc, test_27) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(+5-4)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 1, 1e-7);
}

TEST(S21_Smart_Calc, test_28) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(-sqrt(4))";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, -2, 1e-7);
}

TEST(S21_Smart_Calc, test_29) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(*/2)";
  double res = controller.Calculate(input_str);
  ASSERT_EQ(std::to_string(res), "nan");
}

TEST(S21_Smart_Calc, test_30) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(-sqrt(9)^2)";
  double res = controller.Calculate(input_str);
  EXPECT_NEAR(res, 9, 1e-7);
}

TEST(S21_Smart_Calc, test_31) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(-sqrt(9)^x)";
  double res = controller.Calculate(input_str, "2^2");
  EXPECT_NEAR(res, 81, 1e-7);
}

TEST(S21_Smart_Calc, test_32) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  std::string input_str = "(*/x)";
  double res = controller.Calculate(input_str, "2");
  ASSERT_EQ(std::to_string(res), "nan");
}

TEST(S21_Smart_Calc, Credit_1) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  double sum = 100000;
  int deadline = 12;
  double percent = 5;
  double FirstPayments = 0.0;
  double Overpayment = 0.0;
  double Total = 0.0;
  controller.credit_amu(sum, deadline, percent, &FirstPayments, &Overpayment,
                        &Total);

  EXPECT_NEAR(FirstPayments, 8560.75, 1e-2);
  EXPECT_NEAR(Overpayment, 2728.98, 1e-2);
  EXPECT_NEAR(Total, 102728.97, 1e-2);
}

TEST(S21_Smart_Calc, Credit_2) {
  Model calc_test;
  CreditDepo credit_test;
  Controller controller(&calc_test, &credit_test);
  double sum = 100000;
  int deadline = 12;
  double percent = 5;
  double FirstPayments = 0.0;
  double Overpayment = 0.0;
  double Total = 0.0;
  double LastPayments = 0.0;
  controller.credit_dif(sum, deadline, percent, &FirstPayments, &Overpayment,
                        &Total, &LastPayments);

  EXPECT_NEAR(FirstPayments, 8750, 1e-2);
  EXPECT_NEAR(Overpayment, 2708.33, 1e-2);
  EXPECT_NEAR(Total, 102708.33, 1e-2);
  EXPECT_NEAR(LastPayments, 8368.06, 1e-2);
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
