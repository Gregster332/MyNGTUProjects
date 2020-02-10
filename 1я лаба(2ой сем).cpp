#include <iostream>
#include <string>

using namespace std;


class  Ship {
public:
    int health;
    string name;
    int damage;

};

int main(){
   
    Ship Aurora;
    Ship Titanic;
    Aurora.health=Titanic.health=1000;
    Aurora.damage=70;
    Titanic.damage=50;
    int choiser;
    for(int i = 0; i<20;i++){
    cout<<"Выберете, кто будет нападать "<<i+1<<"-м:"<<endl;
    cin>>choiser;
    if((Aurora.health<=0) || (Titanic.health<=0)){
        cout<<"Один из кораблей повержен!"<<endl;
        break;
    }
        
    if (choiser==1){
        Titanic.health-=Aurora.damage;
    }
    else if(choiser==2) {
        Aurora.health-=Titanic.damage;
    }
        else{
            cout<<"У тебя всего 2 корaбля!"<<endl;
        }
        if((Aurora.health<=0) || (Titanic.health<=0)){
            cout<<"Один из кораблей повержен!"<<endl;
            break;
        }
        
        cout<< "ХП Авроры: "<<Aurora.health<<"|||"<<"ХП Титаника: "<<Titanic.health<<endl;
    
  
}
}
