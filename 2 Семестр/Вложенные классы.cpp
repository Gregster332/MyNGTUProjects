#include <string>
#include <iostream>

using namespace std;



class dataBase{
public:
    
  
    void GetDataBase(){
        for(int i = 0; i<LENGTH; i++){
            cout<<employeeinfo[i].GetEmployeeInfo()<<endl;
        }
    }
    
private:
    class employeeInfo{
        
    private:
        int age;
        string name, phoneNumber;
        
    public:
        employeeInfo(int x, string a, string b){
            this->age=x;
            this->name=a;
            this->phoneNumber=b;
            
        }
        
        string GetEmployeeInfo(){
            return "Имя: "+name+"Возраст: "+to_string(age)+","+"Номер телефона: "+phoneNumber;
        }
        
    };
    
    static const int LENGTH = 5;
    
    employeeInfo employeeinfo[LENGTH]{
        employeeInfo(33, " Иван, ", " 89993456789 "),
        employeeInfo(21, " Михаил, ", " 89101234567 "),
        employeeInfo(25, " Кирилл, ", " 89907893333 "),
        employeeInfo(36, " Артем, ", " 89304456677 "),
        employeeInfo(41, " Валера, ", " 89789006752 ")
    };
    
};



int main() {
    
    
   
   dataBase database;
   database.GetDataBase();
    
    
    
    return 0;
}
