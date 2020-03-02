#include <string>
#include <iostream>

using namespace std;

class Apple{
    
public:
    static int Count;
    
    Apple (int weight, string color){
        this->weight = weight;
        this->color=color;
        Count++;
        id = Count;
    }
    
    int GetId(){
        return id;
    }
    
private:
    int weight;
    string color;
    int id;
};
int Apple::Count=0;


int main() {
    /*int CountOfApples;
    cout<<"Какому количество яблок нужно присвоить id? "<<endl;
    cin>>CountOfApples;
   
    for (int i = 0; i < CountOfApples; i++){
        Apple apple;
    }*/
    cout<<"Присваеваем номера каждому яблоку: "<<endl;
    Apple FirstApple(200, "Green");
    Apple SecondApple(100, "Red");
    Apple ThirdApple(75, "Yellow");
    Apple FourthApple(45, "Brown");//гниль палучаеца
    
    cout<<"ПЕрвое:"<<"\t"<<FirstApple.GetId()<<endl;
    cout<<"Второе:"<<"\t"<<SecondApple.GetId()<<endl;
    cout<<"Третье:"<<"\t"<<ThirdApple.GetId()<<endl;
    cout<<"Четвертое:"<<"\t"<<FourthApple.GetId()<<endl;
    return 0;
}
