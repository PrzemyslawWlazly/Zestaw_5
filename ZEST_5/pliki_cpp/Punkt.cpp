 //Punkt.cpp
// Klasa TPunkt jest przyjacielem klast ASCIICanvas i ma dostep do tablicy2D

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

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
class Prosta;
class Light;


double Punkt::get_wsp_x() { return this-> wsp_x;}
double Punkt::get_wsp_y() { return this-> wsp_y;}

Punkt::Punkt(double x, double y) : wsp_x(x), wsp_y(y) {};
Punkt::Punkt(Light light) : wsp_x { light.wsp_x_punktu_swiatla() } , wsp_y { light.wsp_y_punktu_swiatla() } {}; 

//PRZELADOWANIA OPERATOROW POROWNANIA NA RZECZ POROWNYWANIA PUNKTU I PROSTEJ Z REFERENCJĄ

bool Punkt::operator<(Prosta & pr) 
{
        if ( pr.a <= 0.01 && pr.a >= -0.01) 
                {
                if ( (this->wsp_y) < pr.b   ) {return 1;}
                else {return 0;}
                std::cout<< "((this->wsp_x) < pr.b   ) " << ((this->wsp_x) < pr.b  )<<std::endl;
                }
                
        if  ( round( ((pr.a)*(this->wsp_x) - (this->wsp_y) + (pr.b) ) )  > 0.0 ) {return 1;}           
        else {return 0;}
}

bool Punkt::operator>(Prosta & pr) 
{
                if ( pr.a <= 0.01 && pr.a >= -0.01) 
                {
                if ( (this->wsp_y) > pr.b   ) {return 1;}
                else {return 0;}
                }
        if  ( round( ((pr.a)*(this->wsp_x) - (this->wsp_y) + (pr.b) ) )  < 0.0 ) {return 1;}           
        else {return 0;}
//wywolanie : punkt>prosta    
}

bool Punkt::operator==(Prosta & pr) 
{
                
        if  (round( ((pr.a)*(this->wsp_x) - (this->wsp_y) + (pr.b) ) ) == 0 ) {return 1;}     
        else {return 0;}
//wywolanie : punkt==prosta    
}
// W operatorach <= oraz >= korzystam ze zdefiniowanych wczesniej operatorow
bool Punkt::operator<=(Prosta & pr) 
{
         if  ( *this < pr || *this == pr ) {return 1;}     
        else {return 0;}
}

bool Punkt::operator>=(Prosta & pr) 
{
         if  ( *this > pr || *this == pr ) {return 1;}     
        else {return 0;}
}


//****************************************************
double Punkt::d(Punkt & P_1, Punkt & P_2)
{
// odleglosc 2 punktow
double d = std::sqrt( (P_2.wsp_x - P_1.wsp_x )*(P_2.wsp_x - P_1.wsp_x ) + (P_2.wsp_y - P_1.wsp_y )*(P_2.wsp_y - P_1.wsp_y )  );
return d;
}
//*****************************************************
double Punkt::d(Punkt & P_1, Prosta & pr)
{
// odleglosc punktu od prostej

double licznik = std::abs(   ( (pr.get_a())*(P_1.get_wsp_x()) ) -1.0*(P_1.get_wsp_y()) + (pr.get_b())  );
double mianownik =  std::sqrt( ((pr.get_a())*(pr.get_a())) + 1 ) ; // Kazda badana prosta ma wzor ax -1y +b 
double d = licznik/mianownik;
return d;
}

double Punkt::d(Punkt & P_1, Prosta_Pionowa & pr_pionowa)
{
// odleglosc 2 punktow
double d = std::abs(pr_pionowa.get_x() - P_1.get_wsp_x());
return d;
}

//************************************************************************
// Korzysram z operatorow przeladowanych w klasie Prosta_Pionowa
bool Punkt::operator<(Prosta_Pionowa & pr) 
        {
        if ( pr  > *this ) {return 1;}
        else {return 0;}
        };


bool Punkt::operator>(Prosta_Pionowa & pr) 
        {
        if (pr  < *this) {return 1;}
        else {return 0;}
        };


bool Punkt::operator==(Prosta_Pionowa & pr) 
    // przydomek virtual 
        {auto punkt_tymczasowy = new Punkt(this->get_wsp_x(),this->get_wsp_y());
        if ( pr  == *punkt_tymczasowy  ) {delete punkt_tymczasowy; return 1;}
        else {delete punkt_tymczasowy;return 0;}
        }  

bool Punkt::operator<=(Prosta_Pionowa & pr) 
{
         if  ( pr.get_x() >= this->wsp_x ) {return 1;}     
        else {return 0;}
}

bool Punkt::operator>=(Prosta_Pionowa & pr) 
{
         if  ( pr.get_x() <= this->wsp_x ) {return 1;}     
        else {return 0;}
}
//**************************************************************************8


void Punkt::rysuj_punkt(ASCIICanvas & E, char SYMBOL)
{
 E.tablica2D[static_cast<int>(this->wsp_y)][static_cast<int>(this->wsp_x)] = SYMBOL;

}

//****************************************************

void Punkt::wyswietl_wsporzedne()
{
std::cout<< "\n" << this->wsp_x << "  "<< this->wsp_y <<std::endl;

}