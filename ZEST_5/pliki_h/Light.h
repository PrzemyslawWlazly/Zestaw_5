// Light.h
#ifndef LIGHT_H
#define LIGHT_H

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;



class Light
{
private:
    Punkt punkt_swiatla;
    char symbol = '/'; // wartosc domyslna

    public:
    void rysuj_punkt(ASCIICanvas & E);
    void rysuj_cien(ASCIICanvas & E);
    Light(double x, double y, char SYMBOL);
    double wsp_x_punktu_swiatla();
    double wsp_y_punktu_swiatla();



bool operator<(Prosta & pr) ;
bool operator>(Prosta & pr) ;
bool operator==(Prosta & pr);

bool operator<(Prosta_Pionowa & pr) ;
bool operator>(Prosta_Pionowa & pr) ;
bool operator==(Prosta_Pionowa & pr) ;

double d(Light & P_1, Punkt & P_2);
double d(Punkt & P_1, Light & P_2);

Punkt get_punkt_swiatla();



};

#endif
