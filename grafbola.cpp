#include "grafbola.h"

grafbola::grafbola(int x):escala(0.8)
{   play = x; //bandera para la funcion paint saber que color asignarle
    float posx,posy,velx,vely,mass,r,K,e;
    posx = 0;
    posy = 0;
    r = 50;
    mass = 50;
    velx = 60;
    vely = 60;
    K = 0;
    e = 0.2;
    esf = new bola(posx,posy,velx,vely,mass,r,K,e);


}

grafbola::~grafbola() //eliminar nuestro objeto
{
    delete esf;

}

QRectF grafbola::boundingRect() const
{
    //return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR()); //Tamano para nuestro circulo de acuerdo a la escala
    return QRect(-2,-2,esf->getR(),esf->getR());
}

void grafbola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Dependiendo de los jugadores,se crearan los objeto con diferente color
    if(play==1){
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect().center(),5,5);

    }
    if(play==2){
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect().center(),5,5);
    }
}

void grafbola::setEscala(float s) //escala para acoplarse a la escena
{
    escala = s;
}

void grafbola::actualizar(float v_lim)
{
    //Actualizamos la posición del objeto

    esf->actualizar();
    setPos(esf->getPX(),v_lim-esf->getPY());

}


bola *grafbola::getEsf() //obtener valores de nuestro objeto
{
    return esf;
}
