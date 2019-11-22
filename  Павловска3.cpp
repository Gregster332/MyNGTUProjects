#include <iostream>

using namespace std;

int main(){
    
    const int rows = 4;
    const int columns = 4;
    
    int Array[rows][columns];
    
    cout<<"Исходный массив:\n  ";
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            Array[i][j] = 10 - (rand()%30+1);
            cout<<Array[i][j]<<"\t ";
            
        }
        cout<<endl;
    }
    cout<<endl;
    
    int Mass[columns];
    for (int k = 0 ; k<columns; k++){
        Mass[k] = 0;
    }
    for (int j = 0; j < columns; j++){
        for ( int i = 0; i<rows; i++){
            if(Array[i][j]<0 && Array[i][j]%2!=0){
                Mass[j]+=abs(Array[i][j]);
            }
        }
    }
        
    
    
    cout<<"Массив характеристик:\n";
    for (int t = 0; t<columns; t++)
        cout<<Mass[t]<<" ";
        cout<<endl;
        
        
    int arrIndex[columns];
    int min = 1000, IndexCol;
    
    for (int i = 0; i<columns;i++)
    {
        for (int j =0; j<columns; j ++){
            if ( min > Mass[j] && Mass[j]!= -1){
                min = Mass[j];
                IndexCol = j;
                
                
                
            }
        }
        
        
        arrIndex[i] = IndexCol;
        Mass[IndexCol]=-1;
        min = 1000;
        
    }
    
    
    int ReplaceArray[rows][columns];
    for (int i = 0; i<columns;  i++)
        for (int j = 0; j<rows; j ++)
            ReplaceArray[i][j]= Array[i][arrIndex[j]];
    
    cout<<"Массив после перестановки: \n"<<endl;
    for (int  i = 0; i<rows;i++){
        for (int j = 0; j<columns;j++){
            cout<<ReplaceArray[i][j]<<"\t";
            
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
