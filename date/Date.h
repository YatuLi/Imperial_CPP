#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cctype>

using namespace std;

// cannot use the exact same name as the class name here, so we add '_H' after the class name.
#ifndef Date_H
#define Date_H

// very very basic class declaration even without any constructors and destructor.
class Date {
public:
  // if we dont have constructors in place, the class is views as a struct which cannot allow to use this keyword.
  Date();
  Date(int, int, int);
  //>>>>>>>>>>>>>>>>>. uncomment this part to see problems
  // ~Date();

  int year, month, day;

  void next ();
  bool equal (Date);
  int equalByReference (Date&);
  void print();

  // void f1(Date aDate);
  // void f2(Date* pDate);
  // void f3(Date& rDate);


private:
  int newDay;
  int newMonth;
  int newYear;
};

#endif
