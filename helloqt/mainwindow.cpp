#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);

  connect(ui->pushButtonMorre,
          SIGNAL(clicked(bool)),
          this,
          SLOT(finaliza()));

  connect(ui->horizontalSliderVeloc,
          SIGNAL(valueChanged(int)),
          ui->widgetPlotter,
          SLOT(setVelocidade(int)));

  connect(ui->widgetPlotter,
          SIGNAL(posx(int)),
          ui->lcdNumberX,
          SLOT(display(int)));

  connect(ui->widgetPlotter,
          SIGNAL(posy(int)),
          ui->lcdNumberY,
          SLOT(display(int)));

  connect(ui->actionAbreDialogo,
          SIGNAL(triggered(bool)),
          this,
          SLOT(abreDialogo()));

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::finaliza()
{
  exit(0);
}

void MainWindow::copiaTexto()
{
  ui->textEditRight->setPlainText(
        ui->textEditLeft->toPlainText());
}

void MainWindow::mostraLcd(int value)
{
  ui->lcdNumber->display(value);
}

void MainWindow::abreDialogo()
{
  Dialog d;
  if( d.exec() == QDialog::Accepted){
    qDebug() << "ok ->" << d.pegaTexto();
  }
  else{
    qDebug() << "cancel -> " << d.pegaTexto();
  }
}














