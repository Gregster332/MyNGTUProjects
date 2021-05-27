//
//  main.cpp
//  Pointers
//
//  Created by Григорий on 26.02.2021.
//

#include <iostream>
using namespace std;

void funcOne(int value) {
    value = 12;
}

void funcTwo(int* value) {
    *value = 12;
}


int main() {
    int firstNum = 5;
    cout<<"First num is: "<<firstNum<<endl;
    
    funcOne(firstNum);
    cout<<"Now num is: "<<firstNum<<endl;
    
    funcTwo(&firstNum);
    cout<<"And now, num is: "<<firstNum<<endl;
    
    return 0;
}

