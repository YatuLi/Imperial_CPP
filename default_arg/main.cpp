#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class A{
  int i;
public:
  A (int j = 22){ // def parameter for constructor.
    i = j;
  };

  void f(int l = 44){
    cout << " f(" << l << "); \n";
  };

  void g(int l = 44, char c = 'b', int m = 66){
    cout << " g(" << l << " , " << c << " , " << m <<" ); \n";
  };

  // void h1 (int l = 4, char c){
  //   ...
  // };

  void h2 (int l, char c = 'd'){ // only have one def arg here.
    cout << " h2( " << l << ", " << c << " );\n";
  };

  friend ostream& operator<< (ostream& o, A& x){
    return o << " A(i= " << x.i << ") \n";
  };
};

A al(3);

// this function could be defined anywhere out of the class A. so we put it here making no different from having a different source file to hold it.
void h (A& x = al, int l = 88){ // 2 default args, the obj one must have been initialised in the declaration of the class.
  cout << " h( " << x << " , " << l << ") \n";
  cout << "within this member function void h(), the operator<< could simply read an obj by sending its attribute i up onto the console. \n";
  cout << "this is because of the friend overloaded function ostream& operator<< (), so it can see everything within the class A and start applying them \n";
  cout << "the way if cannot use --> x.i = --> as void h() is a global function defined anywhere else rather than within this class, we onlly have access to the private member of class A due to friend function operator<< here"  << '\n';
};

int main(){
  A myA(5);
  cout << "myA = " << myA << " \n";
  cout << "overloaded operator<< knows what kinds of args or how many of args are out there --> so it will read the newly defined obj by users. \n";

  A anA;
  cout << "anA = " << anA << " \n";

  cout << "the call of h() will not be required to be led by an obj as it is defined as a global function rather than a member function. \n";
  h(anA, 3);
  h(anA);
  h();

  anA.f(5);
  anA.f();

  anA.g(1, 'f', 5);
  anA.g(1, 'f');
  anA.g(1);
  anA.g();

  anA.h2(5, 'g');
  anA.h2(5);

  return 0;



}
