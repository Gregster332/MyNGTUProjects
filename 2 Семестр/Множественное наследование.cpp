#include <iostream>
#include <string>


using namespace std;


class Fruits{
public:
    int countOfFruits;

     void howManyFruits(int count){
         this->countOfFruits=count;
    }
    

 
};


class Vegetables{
public:
    int countOfVegetables;
    

    void howManyVegetables(int count2){
        this->countOfVegetables=count2;
    }
};


class Market: public Fruits, public Vegetables{
public:
    void howManyProductsInTheMarket(int P1, int P2){
        cout<<"На рынке "<<P1<<" фруктов и "<<P2<<" овощей"<<endl;
        cout<<"А в сумме(ппордуктов): "<<P2+P1<<endl;
    }
};

int main() {
    int firstPar, secondPar;
    Market fruits;
    cout<<"Введите количество фруктов на рынке: "<<endl;
    cin>>firstPar;
    fruits.howManyFruits(firstPar);
    
    Market vegetables;
    cout<<"Введите количество овощей на рынке: "<<endl;
    cin>>secondPar;
    vegetables.howManyVegetables(secondPar);
    
    
    cout<<"Подсчитаем общее количество продуктов на рынке: "<<endl;
    Market finalCount;
    
    finalCount.howManyProductsInTheMarket(firstPar, secondPar);
       
    
    return 0;
}
