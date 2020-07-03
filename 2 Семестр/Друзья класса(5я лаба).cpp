#include <iostream>
#include <string>

using namespace std;

class car;


class driver{
public:
    void whatAboutUrCar(car& car);
};


class car{
public:
    car(int speed, int series, string manufacturier){
        this->speed=speed;
        this->series=series;
        this->manufacturier=manufacturier;
    }
    
    friend void driver::whatAboutUrCar(car &car);
private:
    int speed, series;
    string manufacturier;
};

void driver::whatAboutUrCar(car &car){
    cout<<"Скорость:"<<car.speed<<endl;
    cout<<"Номер:"<<car.series<<endl;
    cout<<"Производитель:"<<car.manufacturier<<endl;
}

int main() {
    int s1, s2;
    string s3;
    cout<<"Введите скорость машины:"<<endl;
    cin>>s1;
    cout<<"Введите номер машины:"<<endl;
    cin>>s2;
    cout<<"Введите производителя:"<<endl;
    cin>>s3;
    car NOne(s1, s2, s3);
    driver Mark;
    Mark.whatAboutUrCar(NOne);
    return 0;
}
