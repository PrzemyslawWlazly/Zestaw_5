//biblioteka_funkcji.cpp
#include "../pliki_h/Punkt.h"
#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"
#include <cstdio> // dla funkcji perror()
#include <iostream>

//odwracanie tablicy
void odwrocTablice(char** tablica, int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        char* temp = tablica[i];
        tablica[i] = tablica[rows - 1 - i];
        tablica[rows - 1 - i] = temp;
    }
}

// funkcje do wyznaczania rownan prostej


float wspolcz_prostej_a(Punkt A , Punkt B );
float wspolcz_prostej_b(Punkt A , Punkt B);

float wspolcz_prostej_a(Punkt A , Punkt B)
{
    double wynik ;
     wynik = (static_cast<double>(B.wsp_y) -static_cast<double>(A.wsp_y) ) / (static_cast<double>(B.wsp_x)-static_cast<double>(A.wsp_x));
     if (std::abs(wynik) == 0.0) { wynik = 0.0; } // moze powstac -0 zaburzajace wyniki operatora porownania 
    return wynik; 
   
}
float wspolcz_prostej_b(Punkt A , Punkt B)
{ 
    //if (A.wsp_x != B.wsp_y)
    //{
    float wynik = static_cast<float>(A.wsp_y) - ( ((static_cast<float>(B.wsp_y) - static_cast<float>(A.wsp_y) ) / (static_cast<float>(B.wsp_x) - static_cast<float>(A.wsp_x) ))*static_cast<float>(A.wsp_x)  );
    return wynik;
    //}
}



void wypelnij(ASCIICanvas & E, Punkt P, bool warunek)
{
for (int i = 0; i < ( E.get_wysokosc() ); ++i) 
        {
            for (int j = 0; j < ( E.get_szerokosc() ); ++j) 
            {
            if (  warunek )
                {
                    //P.get_wsp_y();
                    //P.get_wsp_y();

                    E.tablica2D[i][j] = 'c';
                }
            }
        }  
}



