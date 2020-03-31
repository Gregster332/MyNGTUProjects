#include <string>
#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point (){
        x = 0;
        y=0;
        cout<<this<<"constructor"<<endl;
    }
    
    Point (int valueX, int valueY){
        x = valueX;
        y = valueY;
        cout<<this<<"constructor"<<endl;
    }
    
    Point operator +(const Point &other)
    {
        Point temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        return temp;
    }
    
    Point operator -(const Point &other)
    {
        Point temp;
        temp.x = this->x - other.x;
        temp.y = this->y - other.y;
        return temp;
    }
    
};

int main() {
    cout<<"Сложение координат двух точек: "<<endl;
    
    Point a(5,1);
    Point b(5,2);
    
    Point c = a+b;
    Point d = a-b;
    
    return 0;
}

