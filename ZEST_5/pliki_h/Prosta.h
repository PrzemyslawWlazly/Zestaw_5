// Prosta.h

#ifndef PROSTA_H
#define PROSTA_H

#include "Light.h" 

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Light;


class Prosta : public Figura
{
    private:
    friend float wspolcz_prostej_a(Punkt A , Punkt B);
    friend float wspolcz_prostej_b(Punkt A , Punkt B);
    //friend class Trojkat;
    //friend class Prostokat;
    //friend class Kwadrat;
    //friend class Kolo;
    friend class Punkt;

        double a; //wspolczynnik kierunkowy
        double b; // wyraz wolny
        char symbol = '/';

    public:
    //static Prosta& stworz_prosta(Punkt P_1, Punkt P_2) ;
    static Prosta& stworz_prosta(Punkt &P_1, Punkt &P_2) ;
    static Prosta& stworz_prosta(Punkt* P_1, Punkt* P_2);



    Prosta (double a, double b);
    Prosta (Punkt &A, Punkt &B);



    virtual bool operator<(Punkt & P);
    virtual bool operator>(Punkt & P);
    virtual bool operator==(Punkt & P);
    virtual void rysuj(ASCIICanvas & E);
    double get_a();
    double get_b();
    virtual void wyswietl_swoj_wzor();
    virtual void rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia); // 






};

#endif
