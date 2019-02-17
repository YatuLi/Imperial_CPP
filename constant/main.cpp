#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class A{
  const int i; // need to know the i cannot be changed
  int k;
public:
  A(int l, int m);
  void f1(int l);
  void f2(int l) const; // this function should not change the value of l.
  void print();
};

A::A(int l, int m): i (l){
  k = m;//???????????????
};

void A::f1(int l){
  k = k + i + l;
  // i = i - 1;
};

void A::f2(int l) const{ // this function cannot change any member variable of the object
  int m = k + i + 1;
  cout << "k = k + i + l; & i = i - l; --> " << "error: assignment of member A::k and A::i, in read-only object" << '\n';
  cout << "while int m is an irrelevant one, independent upon the class A" << '\n';
  // k = k + i + l; // cant change the k, which is a member variable of an obj of class A.
  // i = i - l; // cant change the i, which is a member variable of an obj of class A
}

void A::print(){
  cout << "i is --> " << i << '\n';
  cout << "k is --> " << k << '\n';
}

void h1(const A& anA, int l){ // parameter passed in cannot be changed, it doesnt matter whether the passed in ones are const or not.
  anA.f2(l);
};

void h2(A& anA, int l){
  anA.f1(l);
  anA.f2(2*1);
}

int main(){
  const int constInt = 44;
  const A aConst(1,1); // could be initialised no problems but cannot call the function void print() since only const function can call const obj.

  // constInt = 33;
  // const int anotherConst;
  // aConst.f1(3);
  // h2 (aConst, 5);

  // aConst.print(); // cannot to call print(), as 'this' argument discards qualifiers (qualifier is 'const' keyword right down here)
  A anA(20, 20); // i = 20, k = 20.
  cout << "A::A(int l, int m): i (l){ " << '\n' << "   k = m; " << '\n' << " };" << '\n';
  cout << " A::A(int l, int m) :i(l) --> is a way to set the variable i to l. oh my god, the C++ is so volatile" << '\n';
  anA.print(); // 20, 20
  aConst.f2(3);


  anA.f1(5);
  anA.print(); // i = 20, k = 45
  anA.f2(5);
  cout << "anA.f2(5) --> " << '\n';
  anA.print();
  h1(aConst, 5); // as aConst itself is a const, so it cannot be changed in its nature. so no worries about any change that might happen.

  h1(anA, 5); // anA is not a const type, but f2 is called, which wont change any member variable of anA, so i = 20, k = 45
  h2(anA, 5); // k = 70, i = 20
  anA.print();

  return 0;

}
