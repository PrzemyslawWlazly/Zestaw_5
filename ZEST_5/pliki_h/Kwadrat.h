// Kwadrat.h

#ifndef KWADRAT_H
#define KWADRAT_H


class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Light;

class Kwadrat : public Prostokat {
public:
    //void Prostokat::rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia);
    Kwadrat(int WX, int WY, int DLUGOSC, char SYMBOL);
    virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia); // 
};

#endif
