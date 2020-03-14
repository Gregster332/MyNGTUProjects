
#include <iostream>
using namespace std;

 class Random{
 private:
     
     int RandomValue;
     int n;
     int* data;
 public:
     Random(){
         
         cout<<"Введите рандомный символ: "<<endl;
         cin>>RandomValue;
         cout<<RandomValue;
     }
     
     
     Random(const Random &random){
       cout<<"Введите рандомное число: "<<endl;
         cin>>RandomValue;
         cout<<"Вот оно: "<<RandomValue<<endl;
     }
     Random(int size){
         data=new int [size];
         for (int i =0;i<size;i++){
             cout<<"Введите "<<i+1<<"-й элемента массива"<<endl;
             cin>>n;
             data[i]=n;
         }
         for(int i =0;i<size;i++){
             cout<<data[i]<<"|";
         }
         cout<<"Вызвался конструктор"<<endl;
     }
     ~Random(){
         delete[] data;
         cout<<"Вызвался деструктор"<<endl;
     }
    
};


int main() {
  
    Random SIZE(6);
   Random a;
    Random  varname(a);
  
    
    return 0;
}
