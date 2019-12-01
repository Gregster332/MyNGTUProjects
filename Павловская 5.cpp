//
//  main.cpp
//  Павловская5
//
//  Created by Григорий on 30/11/2019.
//  Copyright © 2019 JQ Software. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
const int lil = 6;

struct TRAIN{
    string city;
    int number, hours, minutes;

};

int main(){
    setlocale(LC_ALL, "Russian");
    TRAIN a[lil];
    cout<<"Ввод информации"<<endl;
    for (int i = 0; i<lil;i++){
        cout<<"Введите пункт назначения "<<i+1<<"поезда: ";
        cin>>a[i].city;
        cout<<"Введите номер "<<i+1<<"поезда: ";
        cin>>a[i].number;
        cout<<"Введите часы отправления "<<i+1<<"поезда: ";
        cin>>a[i].hours;
        cout<<"Введите минуты отправления "<<i+1<<"поезда: ";
        cin>>a[i].minutes;
    }

    for (int i =0;i<lil;i++){
        for (int j = i+1; j<lil;j++){
            if (a[j].hours + a[j].minutes>a[j+1].hours +a[j+1].minutes){
                TRAIN tmp = a[j];
                a[j]=a[i];
                a[i]= tmp;
            }
        }
    }
    int k = 0;
    
    string search;
    cout<<"Введите пункт назначения поезда: ";
    cin>>search;
    
    for (int i = 0; i<lil;i++){
        if (a[i].city==search){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"Номер поезда: "<<a[i].number<<endl;
            cout<<"Пункт назначения: "<<a[i].city<<endl;
            cout<<"Время отправления(ЧЧ): "<<a[i].hours<<endl;
            cout<<"Время отправления(ММ): "<<a[i].minutes<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            k++;
            
        }
    }
    if (k == 0)
        cout<<"Таких поездов нет"<<endl;
    return 0;
}
