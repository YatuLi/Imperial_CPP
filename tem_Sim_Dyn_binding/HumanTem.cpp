#include <iostream>

using namespace std;


template <typename T>
class Human{
public:
  void holiday(){
    cout << "spends holidays ";
    static_cast<T*>(this)->enjoying();
  }
};

class Italian: public Human <Italian>{
public:
  void enjoying(){
    cout << "on the beach " << endl;
  }
};

class Swede: public Human <Swede>{
public:
  void enjoying(){
    cout << "in the sauna " << endl;
  }
};

int main(){
  // normal definition of objs
  Italian giuseppe; Swede stefan;

  // test begins here
  // Error: missing template arguments before * token.
  // Human* italian_1 = new Italian();

  // Error: because of static_cast<T*>(this)
  // Italian* italian_2 = new Human();

  cout << "Giuseppe "; giuseppe.holiday();
  cout << "Stefan "; stefan.holiday();
}
