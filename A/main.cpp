#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

// this is a class declaration, so it is supposed to be enclosed by the brackets.a
class A{
private:
  int j;
  int f(int y){
    return ++k;
  };

public:
  int k;
  int g(int x){
    return --j;
  };

  void print(){
    cout << " j = " << j << " , k = " << k << endl;
  };

  int compare(A z){
    return (k == z.k) && (j == z.j)  && (z.f(1) == g(5));
  };

  A(int x, int y ){
    j = x;
    k = y;
  };
};

void f(A x){ // the same function name to the function inside the class A
  // x.j++; // j is a private member which cannot be reached.
  x.k++;
  // cout << x.f(1) << endl; // f() is a private function which cannot be accessed by this function out of the class
  cout << "x.g(2) = " << x.g(2) << '\n';
}

int main(void){
  A a1(10, 20), a2(30, 40);
  a1.print();
  f(a1); // dont get confused, this is the function f() outside of the class A

  // a1.f(3); // giving compiler error

  a1.g(5);
  a1.compare(a2);
  return 0;

}
