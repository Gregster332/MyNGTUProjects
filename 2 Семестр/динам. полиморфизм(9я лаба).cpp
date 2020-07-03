
#include <iostream>

using namespace std;

class Weapons{
public:
    virtual void shoot(){
        cout<<"Tsh-tsh-tsh"<<endl;
    }
};

class Shotgun:public Weapons{
public:
    void shoot(){
        cout<<"htch-pum"<<endl;
    }
};

class Machingun:public Weapons{
public:
    void shoot(){
        cout<<"pr-tsh-pr-tsh"<<endl;
    }
};

int main() {
    int SIZE, n;
    Weapons* Mass[2];
    Weapons* a;
    
    cout<<"Из чего будем стрелять?"<<endl;
    cout<<"1-дробовик, 2-пулемет"<<endl;
    
    for (int i =0; i<2;i++){
        cout<<i+1<<endl;
        cin>>n;
        
        switch(n){
            case 1:
                a = new Shotgun;
                break;
                
            case 2:
                a = new Machingun;
                break;
        }
        
        Mass[SIZE]=a;
    }
    
    for(int i =0;i<2;i++){
        Mass[SIZE]->shoot();
    }
    
    for (int i =0; i<2; i++){
        delete Mass[SIZE];
    }
    return 0;
}
