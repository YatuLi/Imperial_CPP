#include <iostream>

using namespace std;

class A{
  int i;
public:
  // TODO: assignments, constructors and destructors
  A (int l = 2);
  A (const A&);
  // A (A par){ // illegal!
  //   i = par.i;
  // }
  // A& (A& par){ // cannot return A& from a constructor.
  //   i = par.i;
  // }

  A& operator= (const A&);
  friend ostream& operator<< (ostream& o, const A&);
  ~A();
};


A::A(int l){
  cout << " A::A(int), " << l << ", " << (int*)this << endl; // this itself, is the address of a memoery location.
  i = l;
  // cout << "            the difference, is to make the default arg when declaring this constructor. As per the defintion of the default arg, when there is no arg applied by users, it comes in. So we can view those functions with def arg as the functions with a pair of brackets without being filled. \n";
}

A::A(const A& a){
  cout << "A::(const A&), , this: " << *this << " , a: " << a << '\n';
}

A::~A(){
  cout << "A::~A for " << *this << endl;
}

A& A::operator= (const A& a){
  cout << "A&::op=(const A&), this: " << *this << " , a: " << a << endl;
  i = a.i;
  return *this;
}

ostream& operator<< (ostream& o, const A& a){
  return o << " " << (int*)&a << ": A(" << a.i << ") \n";
}

// TODO: parameter passing
void g(A& a){
  cout << " g(A&), a: " << a << '\n';
}

void h (const A* a){
  cout << " h (A*), *a: " << *a << endl;
}

A ff(){
  return A(16);
}

A gg(){
  A anA;
  anA = A (17);
  return anA;
}

/// nested classes
class B{
  A* anAPointer;
  A anA;

public:
  B(){
    cout << "B::B(), this: " << (int*)this << " \n";
  };

  B(int i){
    cout << "B::B(int), this: " << (int*)this << " \n";
    anA = A(i); // call the obj A within the constructor of the B????????????
  };

  B (char c):anA(5){ // data initialiser, for initlisation of an obj within another obj.
    cout << " B::B(char), this: " << (int*)this << endl;
  }

  ~B(){
    cout << " B::~B(), for " << (int*)this << " \n";
  };
};

// implicit conversions
class C{
public:
  C(){
    cout << " C::C() \n";
  }
  C(A& a){
    cout << " C::C(A&), a: " << a << endl;
  }
};


int main(){
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< assignments, constructors and destructors <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,\n";
  A a1; // run time obj, the default arg comes in.

  A a2(6);

  a1 = A(9); //

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< parameter passing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  A a3(4);

  g(a3);

  h(&a3);

  a3 = ff();

  a3 = gg();

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< nested objs <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  A anA1(5);
  B aB; // ?????? why 2 is called.

  B aB1(9);
  B aB2('z');

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< implicit conversions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  A anA2;

  C aC;

  aC = anA2; //  assign an irrelvant obj to another one. anA2 calls the A(), which has a def arg so we have:

  return 0;



}
