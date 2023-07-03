// Figura.h

#ifndef FIGURA_H
#define FIGURA_H
#include <vector> 

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
//class Kolo;
class Light;
class Prosta;
class Prosta_Pionowa;


class Figura
{
protected:
std::vector<Punkt> punkty_figury;

//skroty prc - prosta pionowa cienia
//skrot pc - prosta cienia
//punkt cienia moze miec ta sama wspolrzedna x punkt figury rzucajacy cien

public:
    virtual void rysuj(ASCIICanvas & E)=0; // klasa będzie abstrakcyjna
    //virtual void wypisz_punkty() = 0;

    virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia)=0;
};

#endif
