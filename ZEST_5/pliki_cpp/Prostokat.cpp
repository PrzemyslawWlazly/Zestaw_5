// Prostokat.cpp

#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"
#include "../pliki_h/Prosta_Pionowa.h"
#include "../pliki_h/Light.h"
#include <fstream> // do pracy z plikami ASCII
#include <iostream>
#include <string>
#include <cmath> // round()

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
class Prosta_Pionowa;
class Light;

//double Punkt::d(Punkt & P_1, Prosta & pr);


void Prostokat::rysuj(ASCIICanvas & E)
    {    

    for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        {
            for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
            {
            if ( j >= wx && j < ( wx+(this->dlugosc ) ) && i >= wy && i < (wy+ (this->wysokosc ) ) )
                {
                    E.tablica2D[i][j] = this->symbol;
                    Punkt kolejny_nalezacy = {static_cast<double>(j),static_cast<double>(i) };
                    this->punkty_figury.push_back(kolejny_nalezacy); 
                }
            }
        }  

    }

Prostokat::Prostokat(int WX, int WY,int DLUGOSC, int WYSOKOSC, char SYMBOL)
   : wx{WX}, wy{WY}, dlugosc{DLUGOSC}, wysokosc{WYSOKOSC}, symbol{SYMBOL}
        {

        A = Punkt{static_cast<double>(wx), static_cast<double>(wy)};
        B = Punkt{static_cast<double>(wx+dlugosc-1),static_cast<double>(wy)};
        C = Punkt{static_cast<double>(wx + dlugosc-1),static_cast<double>(wy + wysokosc-1)};
        D = Punkt{static_cast<double>(wx), static_cast<double>(wy + wysokosc-1)};

    ab = Prosta(A,B);
    bc = Prosta_Pionowa(B,C);
    cd = Prosta(C,D);
    ad = Prosta_Pionowa(A,D);

// A.wyswietl_wsporzedne();
// B.wyswietl_wsporzedne();
// C.wyswietl_wsporzedne();
// D.wyswietl_wsporzedne();

        };


//***********************************************************************
void Prostokat::rysuj_cien(ASCIICanvas & E, Light S, char symbol_tla, char symbol_cienia)
{
auto P = S.get_punkt_swiatla();
auto W = new Punkt{0,0}; // punkt do porownywania wewnatrz petli

// Dzieki przeladowaniu operatorow porownania, 
// mozna czytelnie okreslic polozenie punktu i prostej,

// Ustalanie polozenia punkt swiatla wzgledem figury
// Rozwazanych jest 8 przypadkow (w przypadku polozenia punktu swiatla wewnatrz figury, figura nie powinna rzucac cienia).


//.........................................................
//     I stworz prosta SD i SC 
if(P > cd && P >= ad && P <= bc )
{
  
    // if prosta SD jest pionowa
    if(D.get_wsp_x() == P.get_wsp_x() ) 
    {
        //std::cout<< "/n prosta SD jest pionowa /n "<<std::endl;
    
     auto SD = new Prosta_Pionowa{ P, D };
     auto SC = new Prosta{ P, C };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W >= *SD && *W <= *SC && (*W<cd ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SD; delete SC;
    }

    // if prosta SC jest pionowa
        else if(C.get_wsp_x() == P.get_wsp_x() ) 
        {
            //std::cout<< "/n prosta SC jest pionowa /n "<<std::endl;
        
        auto SC = new Prosta_Pionowa{ P, C };
        auto SD = new Prosta{ P, D };


            for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SC && *W <= *SD && (*W<bc && *W<cd ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
                { E.tablica2D[i][j] = symbol_cienia;} } }  
        delete SD; delete SC;
        }
    // nie ma prostych pionowych
            else   
            {        //std::cout<< "/n prosta sd nie jest pionowa /n "<<std::endl;

            auto SD = new Prosta{ P, D } ;
            auto SC = new Prosta{ P, C } ; 

            for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
                    { 
                    *W = {static_cast<double>(j),static_cast<double>(i)};  if  ( (*W <= *SD && *W <= *SC) && ( *W < cd ) &&  ( E.tablica2D[i][j] == symbol_tla )  )
                    { E.tablica2D[i][j] = symbol_cienia;} 
                    } 
                } 
                    
                    delete SD; delete SC;
                    } 


}
 //.........................................................   
//     II 
if(P>bc && P>cd     ) 
{   //std::cout <<"\nPunkt S jest w sekcji II\n";    
    auto SD = new Prosta{ P, D };
    auto SB = new Prosta{ P, B };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if(  (*W<=*SD && *W >= *SB && *W < cd && *W < bc ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  

delete SD; delete SB;
}

//.........................................................
//     III 
if( P>bc && P <=cd && P >= ab  ) 
{//std::cout <<"\nPunkt S jest w sekcji III\n";
    auto SC = new Prosta{ P, C };
    auto SB = new Prosta{ P, B };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if( ( *W <= *SC && *W>=*SB && *W<bc ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  

delete SC; delete SB;
}


//.........................................................
//     IV 
if( S<ab && S> bc     ) 
{//std::cout <<"\nPunkt S jest w sekcji IV\n";
    auto SC = new Prosta{ P, C };
    auto SA = new Prosta{ P, A };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if(  (*W<=*SC && *W >=*SA && *W<bc && *W>ab ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  

delete SC; delete SA;
}
//.........................................................
//     V 
if( P<ab && P>=ad && P<=bc ) 
{
  
    // if prosta SB jest pionowa
    if(B.get_wsp_x() == P.get_wsp_x() ) 
    {
        //std::cout<< "/n prosta SD jest pionowa /n "<<std::endl;
    
     auto SB = new Prosta_Pionowa{ P, B };
     auto SA = new Prosta{ P, A };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W<= *SB && *W>= *SA && *W>ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  

    }

    // if prosta SA jest pionowa
        else if(A.get_wsp_x() == P.get_wsp_x() ) 
        {
            //std::cout<< "/n prosta SC jest pionowa /n "<<std::endl;
        
        auto SA = new Prosta_Pionowa{ P, A };
        auto SB = new Prosta{ P, B };


            for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                { *W = {static_cast<double>(j),static_cast<double>(i)}; if  (  *W>=*SA && *W>=*SB && *W > ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
                { E.tablica2D[i][j] = symbol_cienia;} } }  

        }
    // nie ma prostych pionowych
            else   
            {        //std::cout<< "/n prosta sd nie jest pionowa /n "<<std::endl;

            auto SA = new Prosta{ P, A } ;
            auto SB = new Prosta{ P, B } ; 

            for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
                    { *W = {static_cast<double>(j),static_cast<double>(i)};  if  ( (*W >= *SA && *W >= *SB) && ( *W >ab ) &&  ( E.tablica2D[i][j] == symbol_tla )  )
                    { E.tablica2D[i][j] = symbol_cienia;} } } 
                    delete SA; delete SB;
                    } 


}

//.........................................................
//     VI 
if(  S<ad && S<ab    ) 
{//std::cout <<"\nPunkt S jest w sekcji VI\n";     
    auto SD = new Prosta{ P, D };
    auto SB = new Prosta{ P, B };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if(  ( *W <= *SD && *W>=*SB && *W>ad && *W > ab  ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } } 

delete SD; delete SB;
}
//.........................................................
//     VII 
if(  P>=ab && P<=cd && P < ad     ) 
{//std::cout <<"\nPunkt S jest w sekcji VII\n"; 
    auto SA = new Prosta{ P, A };
    auto SD = new Prosta{ P, D };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if ( (*W<=*SD && *W>=*SA && *W>ad ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } } 

delete SA; delete SD;
}
//.........................................................
//     VIII stworz prosta SA i SC 
if( S>cd && S<ad      ) 
{//std::cout <<"\nPunkt S jest w sekcji VIII\n";
    auto SA = new Prosta{ P, A };
    auto SC = new Prosta{ P, C };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if ( ( *W >= *SA && *W<=*SC && *W>ad && *W<cd) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  

delete SA; delete SC;
}

delete W;
}











































// SPRAWDZANIE POLOZENIA PUNKTU SWIATLA W OSI WSPOLRZEDNYCH

// std::cout <<"\n ab : " <<std::endl; ab.wyswietl_swoj_wzor(); 

// if( S > ab  ) {std::cout <<"\nPunkt S > ab \n";    }
// if( S < ab  ) {std::cout <<"\nPunkt S < ab \n";    }

// std::cout <<"\n ad : " <<std::endl; ad.wyswietl_swoj_wzor(); 
// if( S > ad  ) {std::cout <<"\nPunkt S > ad \n";    }
// if( S < ad  ) {std::cout <<"\nPunkt S < ad \n";    }

// std::cout <<"\n bc : " <<std::endl; bc.wyswietl_swoj_wzor(); 
// if( S > bc  ) {std::cout <<"\nPunkt S > bc \n";    }
// if( S < bc  ) {std::cout <<"\nPunkt S < bc \n";    }

// std::cout <<"\n cd : " <<std::endl; cd.wyswietl_swoj_wzor(); 
// if( S > cd  ) {std::cout <<"\nPunkt S jest wieksze cd \n";    }
// if( S < cd  ) {std::cout <<"\nPunkt S jest mniejsze cd \n";    }