// Kwadrat.cpp

#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"
#include "../pliki_h/Light.h"

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;
class Light;


Kwadrat::Kwadrat(int WX, int WY,int DLUGOSC, char SYMBOL)
   : Prostokat(WX, WY, DLUGOSC, DLUGOSC, SYMBOL)
        {};
void Kwadrat::rysuj_cien(ASCIICanvas & E, Light light, char symbol_tla, char symbol_cienia)
 {  Prostokat::rysuj_cien(E,light, symbol_tla, symbol_cienia);       };