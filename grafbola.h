#ifndef GRAFBOLA_H
#define GRAFBOLA_H
#include <QTimer>
#include <QPainter>
#include <QGraphicsItem>
#include "bola.h"
#define pi 3.141617

class grafbola: public QGraphicsItem
{
public:
    QTimer * timer;

    grafbola(int x,float posx, float posy, float vel, float angulo, float distancia);
    ~grafbola();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void setEscala(float s);
    void actualizar(float v_lim);
    bola *getEsf();

private:
    bola * esf, *esf2;
    float escala;
    int play;

signals:

public slots:
    void Actualizacion();
};


#endif // GRAFBOLA_H
