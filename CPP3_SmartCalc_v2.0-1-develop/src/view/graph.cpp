#include "mainwindow.h"
#include "ui_graph.h"

using namespace s21;

Graph::Graph(QWidget* parent, s21::Controller* controller)
    : QWidget(parent), ui(new Ui::Graph), controller_(controller) {
  ui->setupUi(this);
  setWindowTitle("Graph");
  setFixedSize(geometry().width(), geometry().height());
  ui->widget->addGraph();
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
}
Graph::~Graph() { delete ui; }

void Graph::paint() {
  QString result_label;
  h = 0.030000;
  x.clear();
  y.clear();

  QByteArray array = ui->label_3->text().toLatin1();
  QString strok = ui->label_3->text();
  char* str = array.data();
  double xmax = ui->x2->text().toInt();
  double xmin = ui->x1->text().toInt();
  double ymax = ui->y1->text().toInt();
  double ymin = ui->y2->text().toInt();

  if (xmax > 1000000 || xmax < -1000000) {
    ui->label->setText("Error Input");
    ui->x1->text() = "0";
  } else if (xmin > 1000000 || xmin < -1000000) {
    ui->label->setText("Error Input");
    ui->x2->text() = "0";
  } else if (ymax > 1000000 || ymax < -1000000) {
    ui->label->setText("Error Input");
    ui->y1->text() = "0";
  } else if (ymin > 1000000 || ymin < -1000000) {
    ui->label->setText("Error Input");
    ui->y2->text() = "0";
  } else {
    ui->widget->xAxis->setRange(xmin, xmax);
    ui->widget->yAxis->setRange(ymin, ymax);

    for (X = xmin; X <= xmax; X += h) {
      x.push_back(X);
      double res = controller_->Calculate(str, std::to_string(X));
      y.push_back(res);
    }
    //     x.remove(x.size()/2);
    //     y.remove(y.size()/2);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    //      x.clear();
    //      y.clear();
    //      x.squeeze();
    //      y.squeeze();
  }
}

void Graph::on_pushButton_clicked() { paint(); }

void Graph::slot(QString str) {
  ui->widget->clearGraphs();
  ui->widget->replot();
  ui->label_3->setText(str);
}
