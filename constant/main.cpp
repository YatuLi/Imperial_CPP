#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class A{
  const int i;
  int k;
public:
  A(int l, int m);
  void f1(int l);
  void f2(int l) const;
};

A::A(int l, int m): i(l){
  k = m;???????????????
};

void A::f1(int l){
  k = k + i + 1;
  // i = i - 1;
};

void A::f2(int l) const{
  int m = k + i + 1;
  // k = k + i + 1;
  // i = i - 1; // cant change the i, which is a member variable of class A
}

void h1(const A& anA, int l){
  anA.f2(l);
};

void h2(A& anA, int l){
  anA.f1(l);
  anA.f2(2*1);
}
