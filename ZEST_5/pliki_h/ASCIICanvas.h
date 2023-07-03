// ASCIICanvas.h

#ifndef ASCIICANVAS_H
#define ASCIICANVAS_H
#include <string>

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
//class Kolo;
class Prosta_Pionowa;


class ASCIICanvas : public Canvas 
{
private:
friend void odwrocTablice(char** tablica, int rows, int cols);
friend class Punkt;
friend class Figura;
friend class Prostokat;
friend class Trojkat;
//friend class Kolo;
friend class Prosta;
friend class Prosta_Pionowa;
friend void wypelnij(ASCIICanvas & E, Punkt P, bool warunek);

//friend class Punkt;
friend class Light;
char symbol_tla;
char symbol_cienia;
int wymiar_plutna_x;
int wymiar_plutna_y;
//char tablica2D[wysokosc][szerokosc];
char** tablica2D = new char*[wysokosc]; //tablica 2d tworzona dynamicznie
void wypelnij_canvas(); // funkcja wywolywana przy konstrukcji obiektu
public:
int get_wysokosc() {return this->wysokosc;} // funkcje inline
int get_szerokosc() {return this->szerokosc;} //
void wyswietl_sie(std::string nazwa_pliku);
//ASCIICanvas(int SZEROKOSC, int WYSOKOSC); // konstruktor z definicja w pliku ASCIICanvas.cpp
ASCIICanvas(int SZEROKOSC, int WYSOKOSC, char symbol_tla, char symbol_cienia); // konstruktor z definicja w pliku ASCIICanvas.cpp
void odwroc_ascii_canvas();
};

#endif
