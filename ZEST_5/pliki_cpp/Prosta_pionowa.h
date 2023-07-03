// Prosta_pionowa.h

class Prosta_pionowa : public Prosta
{
friend class Punkt;
// Prosta_pionowa dziedziczy wspolczynnik kierunkowy a i wyraz wolny b, choc sa one nie uzywane
// uzywane sa przeladowane funkcje wirtualne operatorow porownania,
// aby mozna bylo porownywac polozenie punktu i prostej, nawet gdy prosta jest prostopadla
public:
double x_rowny ; // proste pionowe maja wzor 'x=5', 
//virtual void operator<

}
