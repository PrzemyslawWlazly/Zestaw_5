//Punkt.h
#ifndef PUNKT_H
#define PUNKT_H

class Canvas;
class ASCIICanvas;
class Figura;
class Prostokat;
class Kwadrat;
class Trojkat;
//class Kolo;
class Punkt;
class Prosta;
class Light;
class Prosta_Pionowa;

class Punkt 
{
    private:
        friend float wspolcz_prostej_a(Punkt A , Punkt B);
        friend float wspolcz_prostej_b(Punkt A , Punkt B);
        friend class Trojkat;
        friend class Prosta;
        friend class Prosta_Pionowa;
            double wsp_x;
            double wsp_y;
        //char symbol = '*';
    public:
        double get_wsp_x();
        double get_wsp_y();
        Punkt(double x, double y);
        Punkt(Light light);

      //  bool operator<(Prosta  pr) ;
      //  bool operator>(Prosta  pr) ;
      //  bool operator==(Prosta  pr) ;


        bool operator<(Prosta & pr) ;
        bool operator>(Prosta & pr) ;
        bool operator==(Prosta & pr) ;
bool operator<=(Prosta & pr) ;
bool operator>=(Prosta & pr) ;

bool operator>(Prosta_Pionowa & pr); 
bool operator<(Prosta_Pionowa & pr); 
bool operator==(Prosta_Pionowa & pr); 
bool operator<=(Prosta_Pionowa & pr) ;
bool operator>=(Prosta_Pionowa & pr) ;



      // odleglosc 2 punktow
        static double d(Punkt & P_1, Punkt & P_2); 
	static double d(Punkt & P_1, Prosta & pr); // odleglosc punktu od prostej
    static double d(Punkt & P_1, Prosta_Pionowa & pr_pionowa);

	
    void rysuj_punkt(ASCIICanvas & E, char SYMBOL);
	void wyswietl_wsporzedne();
};

#endif
