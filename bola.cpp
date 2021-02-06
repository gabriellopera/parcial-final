#include "bola.h"

bola::bola(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_; //pos en x
    PY = posY_; //pos en y
    mass = masa_;//masa_; // masa del cuerpo
    R = radio_; //radio del cuerpo
    VX = velX_; //vel en x
    VY = velY_; //vel en y
    AX = 0; //acel en x
    AY = 0; //acel en y
    G = 10; //gravedad
    K = K_; //Resistencia del aire
    e = e_; //Coeficiente de restitucion
    V = 0; //vector de velocidad
    dt = 0.1; //delta tiempo
    //dt = _dt; //delta tiempo

}

bola::~bola()
{

}

void bola::actualizar()
{
    //Ecuaciones del movimiento parabólico
    V = pow(((VX*VX)+(VY*VY)),(1/2)); //magnitud
    angulo = atan2(VY,VX); //angulo
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo); //acelaracion en X
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G; //acelaracion en Y
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2); //posición en X
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2); //posición en Y
    VX = VX + AX*dt; //velocidad en X
    VY = VY + AY*dt; //velocidad en Y


}

float bola::getPY() const
{
    return PY;
}


float bola::getMass() const
{
    return mass;
}

float bola::getR() const
{
    return R;
}

float bola::getVX() const
{
    return VX;
}

float bola::getVY() const
{
    return VY;
}


float bola::getE() const
{
    return e;
}

float bola::getPX() const
{
    return PX;
}

void bola::set_vel(float v)
{
    V=v;
}

void bola::set_angulo(float an)
{
    angulo=an;
}

