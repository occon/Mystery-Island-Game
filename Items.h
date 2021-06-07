//
//  Items.h
//  Tarea 04 
//  
//  Created by Lydia Delgado uriarte & Hugo Edgar Palomares Estrella on 01/06/21.
//

#ifndef Items_h
#define Items_h
using namespace std;

class Items{

    public:
        Items();
        Items(int, string, string, int);
        virtual void use(); //virtual solo en declaracion - Función polimórfica
        int getLvl(){return level;};
        string getName(){return name;};
        string getDescription(){return description;};
        int getHP(){return HP;};
    protected:
        int level; 
        string name; 
        string description;
        int HP;
        
};
Items::Items(){
    level=0; 
    name=""; 
    description="";
    HP=1000;
}
Items::Items(int lvl, string n, string descr, int healthp){
    level= lvl;
    name= n;
    description= descr;
    HP= healthp;
}
void Items::use(){
    cout<<"Ese USE no se debe llamar de la clase base"<<endl;
}

#endif