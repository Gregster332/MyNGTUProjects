#include <string>
#include <iostream>

using namespace std;

class Point{
private:
    int x;
    int y;
    int z;
public:
    
    Point(){
        
        x=0;
        y=0;
        z=0;
    }
    Point(int valX,int valY,int valZ){
        x=valX;
        y=valY;
        z=valZ;
    
    }
    void SetX(int x){
        this->x=x;
    }
    void SetY(int y){
        this->y=y;
    }
    void SetZ(int z){
        this->z=z;
    }
    
   void Print(){
        cout<<"Координаты точки: "<<endl;
       cout<<"X: "<<x<<"Y: "<<y<<"Z: "<<z<<endl;
    }
    
};

int main() {
    int n1,n2,n3;
    cout<<"Введите координаты точки A: "<<endl;
    cout<<"X: ";
    cin>>n1;
    cout<<"Y: ";
    cin>>n2;
    cout<<"Z: ";
    cin>>n3;
    
    Point A;
    A.SetX(n1);
    A.SetY(n2);
    A.SetZ(n3);
    A.Print();
    
    Point B(4,5,6);
    B.Print();
    return 0;
}
