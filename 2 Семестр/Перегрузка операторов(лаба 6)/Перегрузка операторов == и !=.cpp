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
    
    bool operator == (const Point & other){
        return this -> x == other.x && this ->y == other.y;
    }
    
    bool operator != (const Point & other){
        return !(this -> x == other.x && this ->y == other.y);
    }
};

int main() {
    cout<<"Сравнение координат двух точек: "<<endl;
    
    Point a(5,1);
    Point b(5,2);
    
    bool result1 = a==b;
    cout<<result1<<endl;
    
    Point c(6,10);
    Point s(5,12);
    
    bool result2 = c!=s;
    cout<<result2<<endl;
    
    return 0;
}
