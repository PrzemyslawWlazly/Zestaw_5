// Prosta_Pionowa.h

#ifndef PROSTA_PIONOWA_H
#define PROSTA_PIONOWA_H



class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Prosta;


class Prosta_Pionowa : Figura
{
    private:
    friend class Punkt;
    // np. x = 5
    double wartosc_x;
    char symbol = 'v';
    public:

    Prosta_Pionowa (double X);
    //Prosta_Pionowa (Punkt A, Punkt B);
    Prosta_Pionowa (Punkt &A, Punkt &B);   

    double get_x();
    virtual bool operator<(Punkt & P);
    virtual bool operator>(Punkt & P);
    virtual bool operator==(Punkt & P);
    virtual void rysuj(ASCIICanvas & E);
    void wyswietl_swoj_wzor();
    virtual void wypisz_punkty();
    virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia); // 
};

#endif


