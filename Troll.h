#ifndef Troll_h
#define Troll_h
#include "Personaje.h"

using namespace std;
class Troll: public Personaje{
    public:
        Troll();
        Troll(string, string, int);
        string getArma();
        void setArma(string);
        void shoot();
    private:
        string arma;
};

//Getters

Troll::Troll(): Personaje(){
}

Troll::Troll(string weapon, string n, int healthp):  Personaje(n, healthp){
    Nombre = n;
    arma = weapon;
     HP = healthp;

}
//Getters
string Troll::getArma(){
    return arma; 
}



//Setters
void Troll::setArma(string weapon){
    arma = weapon;
} 


void Troll::shoot(){ 
    cout << "Tirar golpe" << endl;
}

#endif /* Troll_h */
