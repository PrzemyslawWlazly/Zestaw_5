// Prostokat.h
#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "Prosta.h" 
#include "Prosta_Pionowa.h" 
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
class Prosta_Pionowa;
class Light;


class Prostokat : public Figura 
    {
        //x,y to wspolrzedne lewego poczatku figury
    private:
    int wx;
    int wy;

    Punkt A{0,0}; // WIERZCHOLKI
    Punkt B{0,0};
    Punkt C{0,0};
    Punkt D{0,0};

    Prosta ab{0,0};
    Prosta_Pionowa bc{0};
    Prosta cd {0,0};
    Prosta_Pionowa ad{0}; 

// prc - prosta cienia , prpc i prosta pionowa cienia
// Prosta_Pionowa prpc1_1 {0};
// Prosta_Pionowa prpc2_2 {0};
// Prosta prc_1 {0,0};
// Prosta prc_2 {0,0};



    int wysokosc; 
    int dlugosc; 
    char symbol = '$'; //wartosc domniemana
    public:
    void rysuj(ASCIICanvas & E);
    Prostokat(int WX, int WY,int DLUGOSC, int WYSOKOSC, char SYMBOL);
    virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia); // 
    };

#endif
