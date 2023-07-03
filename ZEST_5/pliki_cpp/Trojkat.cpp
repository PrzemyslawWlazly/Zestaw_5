// Trojkat.cpp

#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"
#include "../pliki_h/Light.h"
#include <string>
#include <fstream> // do pracy z plikami ASCII
#include <iostream>
#include <cmath> // round()
#include <vector> //dla funkcji push_back() zapelniajacy zmienna w Figura::punkty_figury

class Canvas;
class ASCIICanvas;
class Figura;
//class Prostokat;
//class Kwadrat;

class Punkt;
class Light;

Trojkat::Trojkat(int WX, int WY,int DLUGOSC, int WYSOKOSC, char SYMBOL)
    : wx(WX), wy(WY), wysokosc(WYSOKOSC), dlugosc(DLUGOSC), symbol(SYMBOL)
        {        
            A = Punkt{static_cast<double>(wx), static_cast<double>(wy)};
            B = Punkt{static_cast<double>(wx + dlugosc-1),static_cast<double>(wy)};
            C = Punkt{static_cast<double>( std::round( A.get_wsp_x() + 0.5* static_cast<double>(dlugosc) )) ,static_cast<double>(wy + wysokosc-1)};
        }


//***************************************************************************
void Trojkat::rysuj(ASCIICanvas & E)
    {    
// ustalic 2 punkty podstawy p1 i p2
// ustalic trzeci punkt wierzcholka p3
// p1 to (wx,wy)
// p2 to (wx+dlugosc-1,wy)
// p3 to (wx + (dlugosc/2), w2+wysokosc )
auto P1 = Punkt{static_cast<double>(wx),static_cast<double>(wy)};
auto P2 = Punkt{static_cast<double>(wx+dlugosc-1),static_cast<double>(wy)};
auto P3 = Punkt{static_cast<double>(wx + ((dlugosc-1)/2)), static_cast<double>(wy+wysokosc-1)};

// prosta 1 (z punku p1 i p3)
// prosta 2 (z punktu p2 i p3)
// w podobnej petli for z warunkiem if
// y>=y_podstawy i y<a1x+b1 i y <a2x+b2



for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        {
            for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
            {
            if ( i>=wy && i<= ((wspolcz_prostej_a(P1,P3)*j) + (wspolcz_prostej_b(P1,P3) )) && i<= ( (wspolcz_prostej_a(P2,P3)*j) + wspolcz_prostej_b(P2,P3) )  )
                { 
                    E.tablica2D[i][j] = this->symbol;
                    Punkt kolejny_nalezacy = {static_cast<double>(i),static_cast<double>(j) };
                    this->punkty_figury.push_back(kolejny_nalezacy);
                }
            }
        }  
};


void Trojkat::rysuj_cien(ASCIICanvas & E, Light S, char symbol_tla, char symbol_cienia) 
{
    auto ab = new Prosta{ A, B };
    auto ac = new Prosta{ A, C };
    auto bc = new Prosta{ B, C };
    auto a = new Prosta_Pionowa{ A.get_wsp_x() };
    auto b = new Prosta_Pionowa{ B.get_wsp_x() };

    auto P = S.get_punkt_swiatla();
    auto W = new Punkt{0,0}; // punkt do porownywania wewnatrz petli


// Dzieki przeladowaniu operatorow porownania, 
// mozna czytelnie okreslic polozenie punktu i prostej,

// Ustalanie polozenia punkt swiatla wzgledem figury

//Punkty A,B,C trojkata zostaly oznaczone zgodnie z konwencja oznaczania wierzcholkow 
//(A i B to podstawa trojkata)
//Trojkat zostal podzielony przez proste wyznaczajace boki na 6 sekcji numerowanych w komentarzach liczbami rzymskimi.
//Po narysowaniu 2 prostych pionowych wzgledem podstawy i przechodzacych przez punkty podstawy
//Przestrzen wokol trojkata zostala podzielona na obszary 


//  I 
if(  P >= *bc && P >= *ac )
{ //std::cout<< "/n SEKCJA I /n "<<std::endl;


  if(  P < *a  )
    {       //std::cout<< " P < *a "<<std::endl;

        auto SA = new Prosta{ P, A } ;
        auto SB = new Prosta{ P, B } ; 

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
                { 
                *W = {static_cast<double>(j),static_cast<double>(i)};  if  ( *W >= *SA &&  *W<= *SB && *W <= *ab &&  ( E.tablica2D[i][j] == symbol_tla )  )
                { E.tablica2D[i][j] = symbol_cienia;} 
                } 
            } 
                    
    delete SA; delete SB;
    }

    else if( P == *a ) 
    {
        //std::cout<< "/n 2 /n "<<std::endl;
    
     auto SB = new Prosta{ P, C };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *a &&  *W<= *SB && *W < *ab   && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
     delete SB;
    }

 
    else if( P<*b && P>*a )
    {       //std::cout<< " P<*b && P>*a "<<std::endl;

        auto SA = new Prosta{ P, A } ;
        auto SB = new Prosta{ P, B } ; 

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
                { 
                *W = {static_cast<double>(j),static_cast<double>(i)};  if  ( *W <= *SA &&  *W<= *SB && *W < *ab &&  ( E.tablica2D[i][j] == symbol_tla )  )
                { E.tablica2D[i][j] = symbol_cienia;} 
                } 
            } 
                    
    delete SA; delete SB;
    } 

    else if(P == *b ) 
        {
            //std::cout<< "P == *b "<<std::endl;
        
        auto SA = new Prosta{ P, A };


            for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SA &&  *W<= *b && *W < *ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
                { E.tablica2D[i][j] = symbol_cienia;} } }  
        delete SA; 
        }
    
    else if( P > *b)
    {       //std::cout<< "P < *b "<<std::endl;

        auto SA = new Prosta{ P, A } ;
        auto SB = new Prosta{ P, B } ; 

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
                { 
                *W = {static_cast<double>(j),static_cast<double>(i)};  if  ( *W <= *SA &&  *W>= *SB && *W < *ab &&  ( E.tablica2D[i][j] == symbol_tla )  )
                { E.tablica2D[i][j] = symbol_cienia;} 
                } 
            } 
                    
    delete SA; delete SB;
    } 
            


}
//.........................................................   

//   II
else if(  P <= *ac && P >= *bc && P >=*ab)
{ //std::cout<< "/n SEKCJA II /n "<<std::endl;
  

    if(P == *b ) 
    {
        //std::cout<< " P == *b  "<<std::endl;
    
     auto SC = new Prosta{ P, C };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W<=*b && *W<=*SC && ( *W<*ab || *W> *ac ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SC;
    }
    

    else
    {

    auto SB = new Prosta{ P, B };
    auto SC = new Prosta{ P, C };

            if( P < *b) 
            {
                //std::cout<< "\n P < *b  "<<std::endl;
                
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SB &&  *W<= *SC && ( *W>*ac || *W <*ab )  && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  


            }

            else if( P > *b ) 
            {
                //std::cout<< " \n P > *b  "<<std::endl;
            
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W >= *SB &&  *W<= *SC && ( *W>*ac || *W <*ab ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  

            }

    delete SB; delete SC;    
    }
}
//...............................................................

// III
else if(  P <= *ab && P >= *bc )
{               
//std::cout<< "\n III  "<<std::endl;

auto SC = new Prosta{ P, C };
auto SA = new Prosta{ P, A };
        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SC &&  *W>= *SA && *W > *ac  && ( E.tablica2D[i][j] == symbol_tla ) ) 
                { E.tablica2D[i][j] = symbol_cienia;} } }  
delete SA; delete SC;
}

//.............................................................
// IV
else if(  P <= *ab && P <= *bc && P <=*ac)
{    
//std::cout<< "\n Sekcja IV "<<std::endl;

    if ( P == *b )
    {//std::cout<< "\n P == *b "<<std::endl;
    auto SA = new Prosta{ P, A };
    for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
            { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                { *W = {static_cast<double>(j),static_cast<double>(i)}; if  (( *W<=*b && *W>=*SA && *W >=*ab ) && ( E.tablica2D[i][j] == symbol_tla ) )
                { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SA;
    } 
 
    else if( P == *a ) 
            {
                //std::cout<< " P == *a "<<std::endl;
                auto SB = new Prosta{ P, B };
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W>=*a && *W >=*SB  && *W>*ab   && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  
                delete SB;
            }
      
    else if ( P > *b ) 
            {
                //std::cout<< " P > *b "<<std::endl;
                auto SB = new Prosta{ P, B };
                auto SA = new Prosta{ P, A };   
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W>=*SA && *W <= *SB && *W>*ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  
                delete SA;   delete SB;
            }
 
    else if ( P <*a ) 
            {
                //std::cout<< " P <*a "<<std::endl;
                auto SB = new Prosta{ P, B };
                auto SA = new Prosta{ P, A };   
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W<=*SA && *W>=*SB  && *W>*ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  
                delete SA;   delete SB;
            }
 
    else if ( P < *b && P >*a  ) 
            {
                //std::cout<< " P < *b && P >*a  "<<std::endl;
                auto SB = new Prosta{ P, B };
                auto SA = new Prosta{ P, A };   
                for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
                { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
                    { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W>=*SA && *W>=*SB  && *W>*ab && ( E.tablica2D[i][j] == symbol_tla ) ) 
                    { E.tablica2D[i][j] = symbol_cienia;} } }  
                delete SA;   delete SB;
            }


}
//.............................................................

// V
else if(  P <= *ab && P>= *bc )
{               
//std::cout<< "\n Sekcja V  "<<std::endl;

auto SC = new Prosta{ P, C };
auto SB = new Prosta{ P, B };
        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SC &&  *W>= *SB && *W > *bc  && ( E.tablica2D[i][j] == symbol_tla ) ) 
                { E.tablica2D[i][j] = symbol_cienia;} } }  
delete SC; delete SB;                 
}

//.............................................................

// SEKCJA VI
else if(  P <= *bc && P >=*ac && P>=*ab )
{               
//std::cout<< "\n Sekcja VI  "<<std::endl;

    if(  P == *a  ) 
    {
        //std::cout<< " przypadek 18 "<<std::endl;
    
     auto SC = new Prosta{ P, C };


        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W>= *a  && *W<=*SC && ( *W<=*ab || *W >= *bc ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SC;
    }

    else if (P <*a)
    {
        //std::cout<< " przypadek 19 "<<std::endl;
    
     auto SA = new Prosta{ P, A };
     auto SC = new Prosta{ P, C };

        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W>=*SA && *W <=*SC && ( *W<=*ab || *W >= *bc ) && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SC; delete SA;
    }

    else if ( P >*a)
    {
        //std::cout<< " przypadek 20 "<<std::endl;
    
     auto SA = new Prosta{ P, A };
     auto SC = new Prosta{ P, C };


        for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        { for (int j = 0; j < ( E.get_szerokosc() ); ++j)   
            { *W = {static_cast<double>(j),static_cast<double>(i)}; if  ( *W <= *SA && *W <= *SC && ( *W<=*ab || *W >= *bc )  && ( E.tablica2D[i][j] == symbol_tla ) ) 
            { E.tablica2D[i][j] = symbol_cienia;} } }  
    delete SA; delete SC;
    }






}














};//koniec funkcji rysuj_cien()