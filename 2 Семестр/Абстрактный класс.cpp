#include <iostream>
#include <string>

using namespace std;


class Weapon{
public:
    virtual void Shoot()=0;
};

class Gun: public Weapon{
public:
    void Shoot() override{
        cout<<"BANG!"<<endl;
    }
};

class MachineGun: public Weapon{
public:
    void Shoot() override{
        cout<<"RA-TA-TA-TA-TA!"<<endl;
    }
};

class RPG: public Weapon{
public:
    void Shoot() override {
        cout<<"BOOM!"<<endl;
    }
};


class Knife: public Weapon{
public:
    void Shoot() override{
        cout<<"KNOCK-KNOCK!"<<endl;
    }
};

class Player{
public:
    void Shoot(Weapon *weapon){
        weapon->Shoot();
    }
};


int main() {
    int parametr=0;
    Player player1;
    
    cout<<"Каким оружием воспользоваться игроку? 1)Нож, 2)РПГ, 3)Пистолет, 4)Пулемет"<<endl;
    cin>>parametr;
    
    switch (parametr) {
        case 1:{
            Knife knife;
            player1.Shoot(&knife);
            break;
        }
        case 2:{
            RPG rpg;
            player1.Shoot(&rpg);
            break;
        }
        case 3:{
            Gun gun;
            player1.Shoot(&gun);
            break;
        }
        case 4:{
            MachineGun machinegun;
            player1.Shoot(&machinegun);
            break;
        }
    }
      
    
    cout<<"Kill confirmed!"<<endl;
   
    return 0;
}
