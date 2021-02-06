#include "grafbola.h"

grafbola::grafbola(int x, float posx, float posy, float vel, float angulo, float distancia):escala(0.8)
{   play = x; //bandera para la funcion paint saber que color asignarle
    //float posx,posy,velx,vely,mass,r,K,e; //variables
    float r,mass,velx,vely,K,e;

    r = 0.05*distancia;//radio
    mass = 50;//masa
    velx = vel*cos(angulo*pi/180);//velocidad en x inicial
    vely = vel*sin(angulo*pi/180);//velocidad en y inicial
    K = 0.1;//coeficiente de fricción
    e = (0+(rand()%4)); //Coeficiente de restitución es aleatorio, de esta forma se hace el juego dinámico
    esf = new bola(posx,posy,velx,vely,mass,r,K,e); //Se crea el objeto


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
