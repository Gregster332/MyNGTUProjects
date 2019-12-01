#include <iostream>

using namespace std;

int main(){
    int rows, columns;
    cout << "Введите количество строк матрицы: ";
    cin >> rows;
    cout << "Введите количество столбцов матрицы: ";
    cin >>columns;
   
    
    
    
    int **Array = new int* [rows];
    for (int count = 0; count < rows; count++)
        Array[count] = new int [columns];
    
    cout << "\nИсходный массив:\n";
    for (int i =0; i < rows; i++)
    {
        for (int j= 0; j< columns; j++)
        {
            Array[i][j] = 10 - (rand()%30 +1);
            cout << Array[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    
    int *Mass = new int [columns];
    for (int i = 0; i < columns;i++)
    {
        Mass[columns] = 0;
        for (int j = 0; j < rows; j++)
            if ( (Array[j][i] < 0) && ((Array[j][i] % 2 != 0)) )
                Mass[i] += abs(Array[j][i]);
    }
    
    cout << "\nМассив характеристик:\n";
    for ( int i = 0; i < columns; i++)
        cout << Mass[i] << "  ";
    cout << endl << endl;
    
   
        
        
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
        
        int *index = new int [columns];
        int min = 1000,
        index_column;
        
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (min > Mass[j] && Mass[j] != -1)
                {
                    min = Mass[j];
                    index_column = j;
                }
            }
            index[i] = index_column;
            Mass[index_column] = -1;
            min = 1000;
        }
      
        
        
    }
     delete [] Mass;
    
    int **replaceArray = new int* [rows];
    for (int i = 0; i < rows; i++)
        replaceArray[i] = new int [columns];
    
    for (int i = 0; i < columns; i++)
        for (int j = 0; j < rows; j++)
            replaceArray[j][i] = Array[j][i];


    cout<<"Массив после перестановки: \n"<<endl;
    for (int  i = 0; i<rows;i++){
        for (int j = 0; j<columns;j++){
            cout<<replaceArray[i][j]<<"\t";
            
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
