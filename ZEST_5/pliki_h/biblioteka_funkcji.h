// biblioteka_funkcji.h
#ifndef BIBLIOTEKA_FUNKCJI_H
#define BIBLIOTEKA_FUNKCJI_H

#include "Trojkat.h"
class Trojkat;
class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
//class Kolo;
class Punkt;

void odwrocTablice(char** tablica, int rows, int cols) ;
float wspolcz_prostej_a(Punkt A , Punkt B );
float wspolcz_prostej_b(Punkt A , Punkt B);
void wypelnij(ASCIICanvas & E, Punkt P, bool warunek);


#endif
