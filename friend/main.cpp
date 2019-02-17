#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

// the friend XXX, means, the XXX would have access to the things inside of the class where the statement 'friend XXX' is placed.

//  friend functions and friend member functions (implying the this function is from a class)
class C2;
class C1;

class C2{
  int j;
public:
  friend int f(C1&, C2&); // make the outlier function f as a friend, so it can access all its member, even private ones.
  C2 (int l){
    j = l;
  };
  int g(C1&);
};

class C1{
  int i;
public:
  C1(int l){
    i = l;
  };
  friend int f(C1&, C2&); // same thing happens here, so we include this outlier function as a part of delcaration of the class itself.
  friend int C2::g(C1&); // we include the resolution operator to include this C2 function as a friend of function of the C1.
};

int f(C1& aC1, C2& aC2){ // a totally outlier
  return aC1.i * aC2.j;
}

int C2::g(C1& aC1){ // this function g() is a member function of C2
  aC1.i * j;
}


// a class is declared as a friend of another class
class C3;
class C4;

class C3{
  int j;
public:
  C3 (int i){
    j = i;
  };
  friend class C4; // find where this class is, and all of its things could use things delcared in C3.
};

class C4{
public:
  int g(C3& aC3){
    return 2*aC3.j;
  }
};

int main(){
  C1 a(7); // a.i = 7
  C2 b(3); // b.j = 3

  int result = f(a,b) + b.g(a); // 21 + 21
  cout << result << '\n';
  return 0;
}
