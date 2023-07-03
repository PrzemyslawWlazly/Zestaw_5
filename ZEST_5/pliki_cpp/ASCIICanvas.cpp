//ASCIICanvas.cpp

#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"
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
class Light;



//***************************************************************************

void ASCIICanvas::wypelnij_canvas() 
{
        for (int i = 0; i < wysokosc; ++i) 
            {
             tablica2D[i] = new char[szerokosc];
            }

           for (int i = 0; i < wysokosc; i++) 
               {
                   for (int j = 0; j < szerokosc; j++) 
                      {
                      tablica2D[i][j] = this->symbol_tla;
                      if ( i == 0 || i == (wysokosc-1) )  {tablica2D[i][j] = '='; }
                      if ( j == 0 || j == (szerokosc-1) )  {tablica2D[i][j] = '|'; }
                      }
                  // tablica2D[i][j] = '\n';
                }


    std::cout << "**************************" << std::endl;
    //kopiowanie tablicy do obiektu string
    
    std::string plutno = "";
        for (int i = 0; i < wysokosc; ++i) {
            for (int j = 0; j < szerokosc; ++j) {
                plutno = plutno + tablica2D[i][j] ;
            }
            plutno += '\n';
        }

    //std::cout << "\n plutno : \n" << endl; 
    //std::cout << plutno << endl;


    //kopiowanie stringu do pliku 
        std::ofstream file("plik.ascii");
            if (file.is_open()) 
            {
                file << plutno;
                file.close();
                //std::std::cout << "Plik zapisany." << std::endl;
            } else 
                {
                    std::cout << "Nie można otworzyć pliku." << std::endl;
                }
}


ASCIICanvas::ASCIICanvas (int SZEROKOSC, int WYSOKOSC, char symbol_tla, char symbol_cienia) 
    : Canvas(SZEROKOSC, WYSOKOSC), symbol_tla(symbol_tla), symbol_cienia(symbol_cienia) 
        {   wypelnij_canvas();  };

//***************************************************************************

void ASCIICanvas::wyswietl_sie(std::string nazwa_pliku)
{
    //kopiowanie tablicy do obiektu string
    std::string plutno = "";
        for (int i = 0; i < this->get_wysokosc(); ++i) 
           {   for (int j = 0; j < this->get_szerokosc(); ++j) 
            { plutno = plutno + this->tablica2D[i][j] ;  }
           plutno += '\n';
           }
    //kopiowanie stringu do pliku 
        std::ofstream file(nazwa_pliku);
            if (file.is_open()) 
            {
                file << plutno;
                file.close();
                //std::cout << "Plik zapisany." << std::endl;
            } else 
                {  std::cout << "Nie można otworzyć pliku." << std::endl;  }
    
    // Wyświetlanie zawartości tablicy
        for (int i = 0; i < wysokosc; ++i) {
            for (int j = 0; j < szerokosc; ++j) 
            {  std::cout << tablica2D[i][j] << " "; }
            std::cout << std::endl;
        }       

}


//***************************************************************************

void ASCIICanvas::odwroc_ascii_canvas()
{
odwrocTablice(this->tablica2D, this->get_wysokosc(), this->get_szerokosc());

};
