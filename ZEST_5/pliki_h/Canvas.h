//Canvas.h

#ifndef CANVAS_H
#define CANVAS_H


class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
class Punkt;


class Canvas
{
 int szerokosc;
 int wysokosc;
friend class ASCIICanvas;
public:
Canvas(int SZEROKOSC, int WYSOKOSC); 
};

#endif