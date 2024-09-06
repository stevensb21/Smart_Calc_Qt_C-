#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QWidget>

#include "../controller/controller.h"

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget* parent, s21::Controller* controller);
  ~Graph();

 private slots:
  void on_pushButton_clicked();

 public slots:
  void slot(QString str);

 private:
  double xBegin, xEnd, h, X;
  int N;
  void paint();
  QVector<double> x, y;

  Ui::Graph* ui;
  s21::Controller* controller_;
};
}  // namespace s21

#endif  // GRAPH_H
