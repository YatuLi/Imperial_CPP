#include <stdio.h>
#include <iostream>

using namespace std;

class A{
  int i;
public:
  A (int l);
  friend A operator+ (const A&, const A&);
  A operator- (const A&) const; // a member function, which cannot change the obj.i
  friend A& operator++(A&); // not only simply changes the parameter but also return it back to us.
  A& operator--();
  friend ostream& operator<< (ostream&, const A&);
};

A::A(int l){
  i = l;
}

A operator+(const A& a1, const A& a2){ // global function
  return (a1.i + a2.i);
}

A A::operator-(const A& anA) const{ // member function
  return A(i - anA.i);
};

A& operator++(A& a1){
  a1.i = a1.i + 4;
  return a1;
};

A& A::operator--(){
  i = i - 4;
  return *this;
};

ostream& operator<< (ostream& o, const A& anA){
  return o << "A(" << anA.i << ")";
};

int main(void){
  A anA1(5), anA2(6);
  cout << "<< anA1 -->" << "is to get the attribute of obj anA1 and bring it out \n";
  cout << "anA1 = " << anA1 << "anA2 =" << anA2 << '\n';
  cout << '\n';

  cout << "+ is overloaded, but its a global function which has been friended with class A \n";
  cout << "anA1 + anA2 = " << anA1 + anA2 << '\n';
  cout << '\n';

  cout << "- is overloaded, but its a member function which is defined as a member of the class A \n";
  cout << "the anA1, the obj ahead of -, is the caller obj, anything after it is callee. \n";
  cout << "anA1 - anA2 = " << anA1 - anA2 << '\n';

  cout << "++anA1 = " << ++anA1 << '\n';

  cout << "--anA1 = " << --anA1 << '\n';
}
