// Light.cpp
#include "../pliki_h/Punkt.h"
#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
//#include "../pliki_h/Kolo.h"
#include "../pliki_h/Punkt.h"
#include "../pliki_h/Prosta.h"
#include "../pliki_h/Light.h"
#include <cstdio> // dla funkcji perror()
#include <cmath> // round() std::sqrt()
#include <iostream>
#include <cstdio> // dla funkcji perror()
#include <string>
#include <fstream> // do pracy z plikami ASCII

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
class Prosta;
class Light;

double Light::wsp_x_punktu_swiatla() {this->punkt_swiatla.get_wsp_x(); };
double Light::wsp_y_punktu_swiatla() {this->punkt_swiatla.get_wsp_y(); };

void Light::rysuj_punkt(ASCIICanvas & E)
    {   // w tablicy2D reprezentujacej ekran, najpierw jest wartosc y potem wartosc x
        E.tablica2D[static_cast<int>(this->punkt_swiatla.get_wsp_y())][static_cast<int>(this->punkt_swiatla.get_wsp_x())] = this->symbol;


//kopiowanie tablicy do obiektu string
    std::string plutno = "";
        for (int i = 0; i < E.get_wysokosc(); ++i) {
            for (int j = 0; j < E.get_szerokosc(); ++j) {
                plutno = plutno + E.tablica2D[i][j] ;
            }
            plutno += '\n';
        }
        //kopiowanie stringu do pliku 
        std::ofstream file("plik.txt");
            if (file.is_open()) 
            {
                file << plutno;
                file.close();
                //std::cout << "Plik zapisany." << std::endl;
            } else 
                {
                    std::cout << "Nie można otworzyć pliku." << std::endl;
                }
                
    };

Light::Light(double X, double Y, char SYMBOL) : punkt_swiatla{X,Y}, symbol(SYMBOL) {};


//****************************************

// PRZELADOWANIA OPERATOROW POROWNANIA NA RZECZ POROWNYWANIA PUNKTU I PROSTEJ
//  KORZYSTAM Z JUZ PRZELADOWANYCH OPERATOROW W KLASIE PUNKT
bool Light::operator<(Prosta & pr) 
{
        if  ( (this->punkt_swiatla) < pr) {return 1;}           
        else {return 0;}
//wywolanie : punkt<prosta    
}

bool Light::operator>(Prosta & pr) 
{
        if  ( (this->punkt_swiatla) > pr ) {return 1;}           
        else {return 0;}
//wywolanie : punkt>prosta    
}

bool Light::operator==(Prosta & pr) 
{
        if  ( (this->punkt_swiatla) == pr ) {return 1;}     
        else {return 0;}
//wywolanie : punkt==prosta    
}

//**************************************************
// Przeladowanie operatow porownania dla prostej pionowej
// korzystam z przeladowanych operatorow w klasie Punkt

bool Light::operator<(Prosta_Pionowa & pr) 
{
        if  ( pr > (this->punkt_swiatla) ) {return 1;}           
        else {return 0;}
//wywolanie : punkt<prosta    
}

bool Light::operator>(Prosta_Pionowa & pr) 
{
        if  ( pr < (this->punkt_swiatla) ) {return 1;}           
        else {return 0;}
//wywolanie : punkt>prosta    
}

bool Light::operator==(Prosta_Pionowa & pr) 
{
        if  ( pr == (this->punkt_swiatla)  ) {return 1;}     
        else {return 0;}
//wywolanie : punkt==prosta    
}

Punkt Light::get_punkt_swiatla()
{return this->punkt_swiatla ;}























//*

double Light::d(Punkt & P_1, Light & P_2)
{
// odleglosc 2 punktow
double wynik = Punkt::d( P_1, (this->punkt_swiatla) );
return wynik;
}

//*********************************************
double Light::d(Light & P_1, Punkt & P_2)
{
// odleglosc 2 punktow
double wynik = Punkt::d( P_2, (this->punkt_swiatla) );
return wynik;
}
//************************************************




// class Light
// {
// private:
//     Punkt punkt_swiatla;
//     char symbol = '/'; // wartosc domyslna

//     public:
//     void rysuj_punkt(ASCIICanvas & E);
//     void rysuj_cien(ASCIICanvas & E);
//     Light(double x, double y, char SYMBOL);
//     double wsp_x_punktu_swiatla();
//     double wsp_y_punktu_swiatla();
// };
