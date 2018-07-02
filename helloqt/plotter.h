#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget{
  Q_OBJECT
private:
  float ampl, freq;
  float teta;
  float velocidade;

public:
  explicit Plotter(QWidget *parent = 0);

  void paintEvent(QPaintEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void timerEvent(QTimerEvent *e);

signals:
  void posx(int);
  void posy(int);

public slots:
  void setAmplitude(int ampl);
  void setFrequencia(int freq);
  void setVelocidade(int velocidade);
};

#endif // PLOTTER_H
