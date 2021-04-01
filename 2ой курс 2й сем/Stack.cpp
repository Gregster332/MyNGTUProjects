#include <iostream>

using namespace std;


template <typename T>
class STACK
{
private:
  T* stack;
  int count;

public:
  
  STACK()
  {
    stack = nullptr;
    count = 0;
  }

  
  void push(T item)
  {
    T* tmp;

    
    try {
      
      tmp = stack;
      stack = new T[count + 1];
      count++;
      for (int i = 0; i < count - 1; i++)
        stack[i] = tmp[i];

      stack[count - 1] = item;
      if (count > 1)
        delete[] tmp;
    }
    catch (bad_alloc e)
    {
      
      cout << e.what() << endl;
    }
  }
  T pop()
  {
    if (count == 0)
      return 0;
    count--;
    return stack[count];
  }

  
//  T Head()
//  {
//    if (count == 0)
//      return 0;
//    return stack[count - 1];
//  }

  STACK(const STACK& st)
  {
    try {
      
      stack = new T[st.count];
      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
  }

  STACK operator=(const STACK& st)
  {
    if (count > 0)
    {
      count = 0;
      delete[] stack;
    }

    
    try {
      
      stack = new T[st.count];

      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {
      
      cout << e.what() << endl;
    }
    return *this;
  }

  
  ~STACK()
  {
    if (count > 0)
      delete[] stack;
  }

 
 

  bool IsEmpty()
  {
    return count == 0;
  }

  
  void print()
  {
    T* p;

    
    p = stack;

   
    cout << "Stack: " << endl;
    if (count == 0)
      cout << "is empty." << endl;

    for (int i = 0; i < count; i++)
    {
      cout << "Item[" << i << "] = " << *p << endl;
      p++;
    }
    cout << endl;
  }
};

int main()
{
  
  STACK <int> st1;

  st1.push(10);
  st1.push(15);
  st1.push(5);
  st1.push(40);
  st1.print();
 
  int t;
  t = st1.pop();
  cout << "Delete item: " << t << endl;
  st1.print();
 

  
  st1.pop();
  st1.pop();
  

  st1.print();
}
