 //Prosta.cpp
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
#include <cmath> // round()
#include <iostream> //uzywam funkcji cout w rysuj()
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



Prosta::Prosta(double A, double B) 
    : a(A), b(B) 
        {};


Prosta::Prosta(Punkt & P_1, Punkt & P_2) 
    : Prosta{wspolcz_prostej_a(P_1 , P_2),wspolcz_prostej_b(P_1 , P_2) } 
        {};



// Prosta& Prosta::stworz_prosta(Punkt P_1, Punkt P_2) 
//     {
//         if (P_1.wsp_x == P_2.wsp_y)
//         { perror ("\nProsta ktorej rownanie probujesz wyznaczyc jest pionowa\n"); }
//         else
//         {
//         double a =  wspolcz_prostej_a(P_1 , P_2);
//         double b =  wspolcz_prostej_b(P_1 , P_2);
//         Prosta* stworzona_prosta = new Prosta(a,b);
//         return *stworzona_prosta;
//         }
//     };

//**************************************************************
Prosta& Prosta::stworz_prosta(Punkt & P_1, Punkt & P_2) 
    {
        if (P_1.wsp_x == P_2.wsp_y)
        { perror ("\nProsta ktorej rownanie probujesz wyznaczyc jest pionowa\n"); }
        else
        {
        double a =  wspolcz_prostej_a(P_1 , P_2);
        double b =  wspolcz_prostej_b(P_1 , P_2);
        Prosta* stworzona_prosta = new Prosta(a,b);
        return *stworzona_prosta;
        }
    };

//**********************************************************************
Prosta& Prosta::stworz_prosta(Punkt* P_1, Punkt* P_2)
    {
        if (P_1->wsp_x == P_2->wsp_y)
        { perror ("\nProsta ktorej rownanie probujesz wyznaczyc jest pionowa\n"); }
        else
        {
        double a =  wspolcz_prostej_a(*P_1 , *P_2);
        double b =  wspolcz_prostej_b(*P_1 , *P_2);
        Prosta* stworzona_prosta = new Prosta(a,b);
        return *stworzona_prosta;
        }
    };



// PRZELADOWANIA OPERATOROW POROWNANIA NA RZECZ POROWNYWANIA PUNKTU I PROSTEJ
// Korzystam z JUZ przeladowanych operatorow w klasie Punkt
bool Prosta::operator<(Punkt & P) 
{
        if  ( P < *this ) {return 1;}
        else {return 0;}
//wywolanie : prosta<punkt    
}

bool Prosta::operator>(Punkt & P) 
// przydomek virtual 
{
        if ( P > *this ) {return 1;}
        else {return 0;}
//wywolanie : prosta<punkt    
}

bool Prosta::operator==(Punkt & P) 
// przydomek virtual 
{
        if ( P == *this ) {return 1;}
        else {return 0;}
//wywolanie : prosta<punkt    
}

//***************************************************************************

void Prosta::rysuj(ASCIICanvas & E)
{

for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        {
            for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
            {

            auto pij = new Punkt(static_cast<double>(j),static_cast<double>(i)); 
            //auto prosta = new Prosta(this->a, this->b);

            //std::cout << pij->get_wsp_x() << ", "<< pij->get_wsp_y() <<std::endl;

            if (  operator==(*pij) )
                { 
                    E.tablica2D[i][j] = this->symbol;
                    Punkt kolejny_nalezacy = {static_cast<double>(j),static_cast<double>(i) };
                    this->punkty_figury.push_back(kolejny_nalezacy);
                    //std::cout << pij.get_wsp_x() << ", "<< pij.get_wsp_y() <<std::endl;
                
                }
            delete pij;
            //delete prosta;
            }
        }  
    //Punkty figury mozna wypisac
    // for ( auto& p : punkty_figury) {
    //     std::cout << p.get_wsp_x() << ", "<< p.get_wsp_y() <<std::endl;
    // }

//odwrocTablice(E.tablica2D, E.get_wysokosc(), E.get_szerokosc());

 

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
}
//*********************************************
    double Prosta::get_a() {return this->a;};
    double Prosta::get_b() {return this->b;};
//*******************************************************
void Prosta::wyswietl_swoj_wzor() 
{
std::cout<<"\n" << this->get_a() <<"x + " << this->b <<std::endl;

}

void Prosta::rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia) { std::cout<<"\n";}