
#ifndef Personaje_h
#define Personaje_h
using namespace std;
#include "ItemKey.h"
class Personaje{
    public:
        Personaje();
        Personaje(string, int, int); 
        string getNombre();
        int getHP();
        void setHP(int);
        void setNombre(string);
        void setMascota(int);
        int getMascota();
        void AdicionaLlave(Items*);
        void showInventario();
        virtual void shoot();
        virtual void imprime();

    protected:
        string Nombre; 
        int HP;
        int mascota;
        vector <Items*> vecItems; 
};

Personaje::Personaje(){
    Nombre= "-";
    HP = 100;
    mascota = 0;
}

Personaje::Personaje (string name, int hp, int pet){ 
    Nombre= name;
    HP= hp;
    mascota= pet;
}

//Getters
string Personaje::getNombre(){
    return Nombre;
}

int Personaje::getHP(){
    return HP; 
}

int Personaje::getMascota(){
    return mascota;
}
//Setters
void Personaje::setNombre(string name){
    Nombre= name;
}

void Personaje::setHP(int hp){
    HP= hp;
}

void Personaje::setMascota(int pet){
    mascota= pet;
}

void Personaje::shoot(){
    cout << "Atacar" << endl;
}

void Personaje::AdicionaLlave(Items* llave){
    vecItems.push_back(llave);
    cout << "Haz agarrado una llave, usala para abrir el tesoro final" << endl;
}
//Funcion imprimir
void Personaje::imprime(){
    cout << "Personaje" << endl << "Nombre: " << Nombre << endl;
    cout << "Vida: " << HP << endl;
}

void Personaje::showInventario(){
    for (int i=0; i<vecItems.size(); i++){
        vecItems[i]->use();
    }
}
#endif /* Personaje_h */
