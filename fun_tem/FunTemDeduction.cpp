#include <iostream>

using namespace std;

// it may takes in and return back 2 different types, so we have T and U.
template <typename T, typename U>
U foo (T t){};

// default argument for the template argment list, if we havent defined U, it will be defaulted to int type.
template <typename T, typename U = int>
void bar (T t = 0, U u = 0) {};
// default type needs C++ 11

template <typename T>
char f(T) {
  return 'a';
} // #1

char f(int x){
  return 'b';
} // #2

int main(){
  int x = foo(5); // U cannot be deduced; T is int
  bar (1); // bar <int, int> (1, 0)
  bar (); // T cannot be deduced.

  f (550); // uses function #2
  f <> (550); // uses function #1
  // empty template argument list --> things enclosed within the <> refers to a specialisation of a function template

  return 0;
}
