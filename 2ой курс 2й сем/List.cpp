//
//  main.cpp
//  List
//
//  Created by Григорий on 17.03.2021.
//

#include <iostream>

using namespace std;


template<typename Type>
class List {
    
public:
    List();
    ~List();
    
    //void deleteFirstElem();
    void deleteAllList();
    void add(Type data);
    int getSIZE() {
        return SIZE;
    }
    
    Type& operator[](const int index);
    
private:
    
    template<typename Typ>
    class ListElem {
        
    public:
        ListElem *nextElem;
        Type elemData;
        
        ListElem(Type elemData = Type(), ListElem *nextElem = nullptr) {
            this->elemData = elemData;
            this->nextElem = nextElem;
        }
    };
    int SIZE;
    ListElem<Type> *first;
    
};

template<typename Type>
List<Type>::List() {
    SIZE = 0;
    first = nullptr;
}

template<typename Type>
List<Type>::~List() {
    deleteAllList();
}

template<typename Type>
void List<Type>::add(Type data) {
    
    if (first == nullptr) {
        first = new ListElem<Type>(data);
    } else {
        ListElem<Type> *currentElem = this->first;
        while(currentElem->nextElem != nullptr) {
            currentElem = currentElem->nextElem;
        }
        
        currentElem->nextElem = new ListElem<Type>(data);
        
    }
    
    SIZE++;
    
}


template<typename Type>
Type & List<Type>::operator[](const int index){
    
    int  someVar = 0;
    int element = 0;
    ListElem<Type> *currentIndex = this->first;
    
    while (currentIndex != nullptr) {
        
        if (element == index) {
            return currentIndex->elemData;
        }
        currentIndex = currentIndex->nextElem;
        element++;
        
    }
    //some warning here!! Fix!!
    return someVar;
}


//template<typename Type>
//void List<Type>::deleteFirstElem() {
//
//    ListElem<Type> *temp = first;
//
//    first = first->nextElem;
//    delete temp;
//
//    SIZE -= 1;
//
//}

template<typename Type>
void List<Type>::deleteAllList() {
    
    while(SIZE) {
        ListElem<Type> *temp = first;
        
        first = first->nextElem;
        delete temp;
        
        SIZE -= 1;
    }
    
}


int main(int argc, const char * argv[]) {
    
    
    List<int> list;
    list.add(4);
    list.add(11);
    list.add(36);
    list.add(78);
    list.add(1012);
    
    for (int i = 0; i < list.getSIZE(); i++) {
        cout<<"|"<<list[i]<<"|"<<" ";
    }
    
    cout<<endl;
    
    list.deleteAllList();

    if (list.getSIZE() == 0) {
        cout<<"Список пуст. Произошло удаление всех элементов."<<endl;
    }

    
    return 0;
}
