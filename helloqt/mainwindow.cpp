#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);

  connect(ui->pushButtonQuit,
          SIGNAL(clicked(bool)),
          this,
          SLOT(mataTudo()));
  connect(ui->horizontalSliderFrequencia,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setFrequencia(int)));
  connect(ui->horizontalSliderVelocidade,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setVelocidade(int)));
  connect(ui->widget,
          SIGNAL(mudouX(int)),
          ui->lcdNumberX,
          SLOT(display(int)));
  connect(ui->widget,
          SIGNAL(mudouY(int)),
          ui->lcdNumberY,
          SLOT(display(int)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::mataTudo(){
  exit(0);
}

void MainWindow::copiaTexto(){
  ui->textBrowser->setText(ui->textEdit->toPlainText());
}
