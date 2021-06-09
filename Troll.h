#ifndef Troll_h
#define Troll_h
#include "Personaje.h"

using namespace std;
class Troll: public Personaje{
    public:
        Troll();
        Troll(string, string, int, int);
        string getArma();
        void setArma(string);
        void shoot(int);
    private:
        string arma;
};

//Getters

Troll::Troll(): Personaje(){
    Nombre = "Troll";
    HP= 100;
    arma= "Hacha";
    mascota = 0;
}

Troll::Troll(string weapon, string n, int healthp, int pet):  Personaje(n, healthp, pet){
    Nombre = n;
    arma = weapon;
    HP = healthp;
    mascota = pet;
}
//Getters
string Troll::getArma(){
    return arma; 
}



//Setters
void Troll::setArma(string weapon){
    arma = weapon;
} 

//

void Troll::shoot(int n){ 
    cout << "Te ha golpeado el troll y te ha quitado " << n << "puntos de vida" << endl;
}

#endif /* Troll_h */
