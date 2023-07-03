#include "pliki_h/biblioteka_funkcji.h"
#include "pliki_h/Canvas.h"
#include "pliki_h/ASCIICanvas.h"
#include "pliki_h/Figura.h"
#include "pliki_h/Prostokat.h"
#include "pliki_h/Kwadrat.h"
//#include "pliki_h/Kolo.h"
#include "pliki_h/Punkt.h"
#include "pliki_h/Prosta.h"
#include "pliki_h/Light.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Light;

using namespace std;
using json = nlohmann::json;

int main(int argc, char* argv[])
{
string filename;         
if(argc > 1)
{filename = argv[1];}
else
{
cout << "\n Nie podano nazwy pliku konfiguracyjnego \n Prosze podac nazwe pliku : ";
cin >> filename;
}

ifstream reader(filename);
json j;
reader >> j;
reader.close();

int liczba_figur;
int szerokosc_okna;
int wysokosc_okna;
char sym_tla ;
char sym_cienia;
char sym_figury;
char sym_swiatla;
int P_swiatla_x ;
int P_swiatla_y ;


szerokosc_okna = j["szerokosc_okna"];
wysokosc_okna = j["wysokosc_okna"];
liczba_figur = j["liczba_figur_do_narysowania"];

string string_sym_tla = j["znak_tla"];
sym_tla = string_sym_tla[0];// operator pobierania pierwszego znaku z obiektu string

string string_sym_figury = j["znak_figury"];
sym_figury = string_sym_figury[0];// operator pobierania pierwszego znaku z obiektu string

string string_sym_cienia = j["znak_cienia"];
sym_cienia = string_sym_cienia[0];// operator pobierania pierwszego znaku z obiektu string

string string_sym_swiatla = j["znak_swiatla"];
sym_swiatla = string_sym_swiatla[0];// operator pobierania pierwszego znaku z obiektu string

P_swiatla_x = j["wspolrzedna_x_punktu_swiatla"]; 
P_swiatla_y = j["wspolrzedna_y_punktu_swiatla"];


auto S = new Light(P_swiatla_x,P_swiatla_y,sym_swiatla);
auto Ekran = new ASCIICanvas{ szerokosc_okna , wysokosc_okna , sym_tla, sym_cienia };

bool czy_rysowac_kwadraty = j["czy_rysowac_kwadraty"];
bool czy_rysowac_prostokaty = j["czy_rysowac_prostokaty"];
bool czy_rysowac_trojkaty = j["czy_rysowac_trojkaty"];


json tablica_kwadratow = j["Kwadraty"];
json tablica_prostokatow = j["Prostokaty"];
json tablica_trojkatow = j["Trojkaty"];



//..................................
if (czy_rysowac_kwadraty == true)  
{
for (const auto& kwadrat : tablica_kwadratow)
    {
       int wsp_figury_x = kwadrat["wspolrz_x"];
       int wsp_figury_y = kwadrat["wspolrz_y"];
       int dl_figury = kwadrat["dlugosc"];
        auto Figura = new Kwadrat{wsp_figury_x ,wsp_figury_y, dl_figury, sym_figury };
         Figura -> rysuj(*Ekran);
         Figura -> rysuj_cien(*Ekran, *S, sym_tla, sym_cienia);
       delete Figura; 
    }   
}
//..................................
if (czy_rysowac_prostokaty == true)  
{
for (const auto& prostokat : tablica_prostokatow)
    {
        int wsp_figury_x = prostokat["wspolrz_x"];
        int wsp_figury_y = prostokat["wspolrz_y"];
        int dl_figury = prostokat["dlugosc"];
        int wys_figury = prostokat["wysokosc"];
        auto Figura = new Prostokat{wsp_figury_x,wsp_figury_y,dl_figury,wys_figury, sym_figury };
        Figura -> rysuj(*Ekran);
        Figura -> rysuj_cien(*Ekran, *S, sym_tla, sym_cienia);
       delete Figura;
    }
} 

//..................................
if (czy_rysowac_trojkaty == true)  
{
for (const auto& trojkat : tablica_trojkatow)
    {
        int wsp_figury_x = trojkat["wspolrz_x"];
        int wsp_figury_y = trojkat["wspolrz_y"];
        int dl_figury = trojkat["dlugosc"];
        int wys_figury = trojkat["wysokosc"];
        auto Figura = new Trojkat{wsp_figury_x,wsp_figury_y,dl_figury,wys_figury, sym_figury };
        Figura -> rysuj(*Ekran);
        Figura -> rysuj_cien(*Ekran, *S, sym_tla, sym_cienia);
       delete Figura;
    } 
}



S->rysuj_punkt(*Ekran);
Ekran->odwroc_ascii_canvas();
Ekran->wyswietl_sie("plik.ascii");


}
