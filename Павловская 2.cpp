#include <iostream>
#include <cmath>

using namespace std;
const int SIZE = 10;
int Mass[SIZE];


int Minimal(){
    int min = Mass[0];
    for ( int i = 1; i <SIZE; i++){
        if (min >Mass[i]){
            min = Mass[i];
        }
    }
    return min;
}

int Summa(){
    int sum =0;
    int l = 0;
    for (int i = 0; i<SIZE; i++){
        if (Mass[i]<0)
            l++;
        if (l == 2)
            break;
        if (Mass[i]>=0 && l == 1){
            sum+=Mass[i];
        }
    }
    cout<<"Сумма между первыми отрицательными элементами: "<<endl;
    return sum;
}



int main(){
    int Mass2[SIZE];
    int t = 0;
    for (int i =0; i<SIZE; i++){
        cout<<"Введите ["<<i<<"] элемент массива: "<<endl;
        cin>>Mass[i];
    }
    cout<<"Номер минимального элемента массива: "<<Minimal()<<endl;
    cout<<Summa()<<endl;
    
    cout<<"Массив до сортировки: "<<endl;
    for (int i = 0; i < SIZE; i++){
        cout<<Mass[i]<<"|";
    }
    
    cout<<"\nМассив после сортировки: "<<endl;
    
    for ( int i = 0; i<SIZE; i++){
            if (abs(Mass[i])<1){
                
                Mass2[t]=Mass[i];
                t++;
            }
            }
    
    for ( int i = 0; i<SIZE; i++){
        if (abs(Mass[i])>=1){
            
                Mass2[t]=Mass[i];
            t++;
            
        }
    }
    for (int i = 0; i<SIZE; i++)
    cout<<Mass2[i]<<" ";
    return 0;
            
        }

    
  
    
    
    


