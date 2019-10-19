#include <iostream>
#include <cmath>

using namespace std;

void Foo(float a, float c, float b){
    float x1, x2, dx, F;
    int n;
    cout<<"Введите начало отрезка"<<endl;
    cin>>x1;
    cout<<"Введите конец отрезка"<<endl;
    cin>>x2;
    cout<<"Введите расстояние"<<endl;
    cin>>dx;
    for(int x=x1; x<x2; x+=dx){
        n=0;
        if(c<0 && a!=0){
            F=-a*(x*x);
            
        }
        else if(c>0 && a==0){
            F=(a-x)/c*x;
        }
        else {
             F=x/c;
            
        }
        n++;
        if (n>0){
            cout<<"======================================="<<endl;
            cout<<"| При значении ["<<x<<"] Функция F = "<<F<<"|"<<endl;
                    }
                else{
                    cout<<"При значении"<<x<<"функция F не может быть вычислена тк выполняется деление на 0"<<endl;
                }
        }
    }




int main()
{
    float a,b,c;
    cout<<"Введите a"<<endl;
    cin>>a;
    cout<<"Введите b"<<endl;
    cin>>b;
    cout<<"Введите с"<<endl;
    cin>>c;
    Foo(a, b, c);
    return 0;
}
