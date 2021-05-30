
#ifndef Personaje_h
#define Personaje_h
using namespace std;

class Personaje{
    public:
        Personaje();
        Personaje(string, int); 
        string getNombre();
        int getHP();
        void setHP(int);
        void setNombre(string);
        virtual void shoot();
        virtual void correr();
        virtual void saltar();
        virtual void imprime();

    protected:
        string Nombre; 
        int HP;
};

Personaje::Personaje(){
    Nombre= "-";
    HP = 100;
}

Personaje::Personaje (string name, int hp){ 
    Nombre= name;
    HP= hp;
}

//Getters
string Personaje::getNombre(){
    return Nombre;
}

int Personaje::getHP(){
    return HP; 
}

//Setters
void Personaje::setNombre(string name){
    Nombre= name;
}

void Personaje::setHP(int hp){
    HP= hp;
}

void Personaje::saltar(){
    cout << "Saltar" << endl;
}

void Personaje::correr(){
    cout << "Correr" << endl;
}

void Personaje::shoot(){
    cout << "Atacar" << endl;
}

//Funcion imprimir
void Personaje::imprime(){
    cout << "Personaje" << endl << "Nombre: " << Nombre << endl;
    cout << "Nivel: " << HP << endl;
}
#endif /* Personaje_h */
