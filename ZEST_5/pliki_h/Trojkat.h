// Trojkat.h

#ifndef TROJKAT_H
#define TROJKAT_H
#include "Figura.h"
#include "Punkt.h" // tutaj musi byc dolaczany plik z definicja klasy Punkt
// gdyz jest on bezposrednim skladnikiem klasy 
//(w pliku Figura.h, gdzie typ Punkt jest czescia Vectora, Punkt nie musi byc zalaczany)

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Light;

class Trojkat : public Figura 
{
    //x,y to wspolrzedne lewego poczatku figury
private:
int wx;
int wy;
    Punkt A{0,0}; // WIERZCHOLKI
    Punkt B{0,0};
    Punkt C{0,0};

int wysokosc; 
int dlugosc; //dlugosc podstawy 
char symbol = '$'; //wartosc domniemana
public:
void rysuj(ASCIICanvas & E);
Trojkat(int WX, int WY,int DLUGOSC, int WYSOKOSC, char SYMBOL);
virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia); // 

};

#endif
