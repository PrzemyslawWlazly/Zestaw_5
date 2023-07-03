//Canvas.cpp

#include "../pliki_h/biblioteka_funkcji.h"
#include "../pliki_h/Canvas.h"
#include "../pliki_h/ASCIICanvas.h"
#include "../pliki_h/Figura.h"
#include "../pliki_h/Prostokat.h"
#include "../pliki_h/Kwadrat.h"
#include "../pliki_h/Punkt.h"
//#include "../pliki_h/Kolo.h"

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;

Canvas::Canvas (int SZEROKOSC, int WYSOKOSC) 
    : szerokosc{SZEROKOSC}, wysokosc{WYSOKOSC} 
        {};
// konstruktor z lista inicjalizacyjna, inicjalizujacy skladniki const