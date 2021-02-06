#ifndef GRAFBOLA_H
#define GRAFBOLA_H
#include <QTimer>
#include <QPainter>
#include <QGraphicsItem>
#include "bola.h"

class grafbola: public QGraphicsItem
{
public:
    QTimer * timer;

    grafbola(int x);
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
