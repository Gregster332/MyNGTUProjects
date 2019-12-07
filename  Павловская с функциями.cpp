#include <iostream>
#include <string>
#define n 4
using namespace std;

int *MassOfCharacteristics(int Array[n][n]) {
    int Mass[n];
    int* p = Mass;
    for (int k = 0; k < n; k++) {
        Mass[k] = 0;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (Array[i][j] < 0 && Array[i][j] % 2 != 0) {
                Mass[j] += abs(Array[i][j]);
            }
        }
    }
    
    cout << "Массив характеристик:\n";
    for (int t = 0; t < n; t++)
        cout << Mass[t] << " ";
    cout << endl;
    return p;
    ;
}
void ReplaceMass(int* Mass, int Array1[n][n]) {
    int arrIndex[n];
    int min = 1000, IndexCol;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (min > Mass[j] && Mass[j] != -1) {
                min = Mass[j];
                IndexCol = j;
                
                
                
            }
        }
        
        
        arrIndex[i] = IndexCol;
        Mass[IndexCol] = -1;
        min = 1000;
        for (int i = 0; i<n;i++)
        {
            for (int j =0; j<n; j ++){
                if ( min > Mass[j] && Mass[j]!= -1){
                    min = Mass[j];
                    IndexCol = j;
                    
                    
                    
                }
            }
            
            
            arrIndex[i] = IndexCol;
            Mass[IndexCol]=-1;
            min = 1000;
            
        }
        
        
        int ReplaceArray[n][n];
        for (int i = 0; i<n;  i++){
            for (int j = 0; j<n; j ++){
                ReplaceArray[i][j]= Array1[i][arrIndex[j]];
            }
        }
        cout<<"Массив после перестановки: \n"<<endl;
        for (int  i = 0; i<n;i++){
            for (int j = 0; j<n;j++){
                cout<<ReplaceArray[i][j]<<"\t";
                
            }
            cout<<endl;
            
    }
    
}

}

    int main() {
    
    int Array1[n][n];
    int *p;
    cout << "Ваш массив: \n  ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Array1[i][j] = 10 - (rand() % 30 + 1);
            cout << Array1[i][j] << "\t ";
            
        }
        cout << endl;
    }
    cout << endl;
    
    
    p= MassOfCharacteristics(Array1);
    ReplaceMass(p, Array1);
    
    
    for (int i = 0; i < n; i++) {  //вывод
        for (int j = 0; j < n; j++)
        {
            cout << Array1[i][j] << endl;;
        }
        
    }

   
    }

