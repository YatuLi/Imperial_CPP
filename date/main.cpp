#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include "Date.h"

using namespace std;

void f1(Date aDate){
  aDate.next();
}

void f2(Date* pDate){
  pDate->next();
}

void f3(Date& rDate){
  rDate.next();
}

int main(){
  // Method 1 to create objects;
  cout << "<<<<<<<<<<<<<<<<<<<<<<<< simple class with all public variables <<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  Date today, aDay;
  cout << "Properties of the object \'today\'" << '\n';
  today.day = 30;
  today.month = 10;
  today.year = 2007;
  today.print();

  cout << "Properties of the object \'aDay\'" << '\n';
  aDay.day = 15;
  aDay.month = 5;
  aDay.year = 1984;
  aDay.print();

  aDay = today;
  cout << "assign the aDay with everything in today" << '\n';

  if (aDay.equal(today)){ // equal(obj) to compare 2 objects
    cout << "today and tomorrow are equal \n";
  }

  cout << "After calling twice, aDay.next(), the aDay is --> \n";
  aDay.next();
  aDay.next();
  aDay.print();

  cout << "After calling 2 aDay.next() with aDay = today, the today is --> \n";
  today.print();


  if (aDay.equal(today)){ // equal(obj) to compare 2 objects
    cout << "today and tomorrow are equal \n";
  }

  Date bDay (17, 1, 2019);
  bDay.print();

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< There must be a constructor in a class, both well defined and declared  <<<<<<<<<<<<<<<<<<<<<<<\n";

  Date today_1(30,1,2008), anotherDay(78,10,1986);
  today_1.print();
  anotherDay.print();


  Date* tomorrow = new Date(11,21,1996);
  tomorrow->print();
  (*tomorrow).print();

  cout << "If we dont have a default constructor in place, so we go to Date.cpp to comment out the default constuctor, the initialisation of \'Dat someDay\' would become illegal. Gives undefined reference to this initialisation. \n";
  //Date someDay;
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Dynamic Objects - Pointer Revisited <<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  Date *aDate, *bDate;
  aDate = new Date(5, 11, 1996);
  bDate = new Date(5,11,1996);
  aDate->print();
  bDate->print();
  if (aDate == bDate){
    cout << "aDate, bDate are same \n";
  } else {
    cout << "aDate and bDate are not the same \n";
  }
  if (aDate->equal(*bDate)){
    cout << "by using equal(), they are the same \n";
  } else {
    cout << "by using equal(), they are not the same \n";
  }
  (*aDate).next();
  aDate->print();
  bDate->print();

  bDate = aDate;
  cout << "bDate = aDate; --> " << "makes the bDate point to the object which is pointed by aDate." << '\n';
  aDate->print();
  bDate->print();

  aDate->next();
  aDate->print();
  bDate->print();
  if (aDate == bDate){
    cout << "aDate and bDate are same\n";
    cout << "the comparison (==) for pointers is defined, by having (aDate == bDate), we can determine if 2 objects are the same or not in C++ as long as you define your object on heap." << '\n';
  }
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<<< Reference to object <<<<<<<<<<<<<<<<\n";
  Date today_2 (25, 11, 2001);
  Date tomorrow_1 (31,12,2002);
  today_2.print(); // 25-11-2001
  tomorrow_1.print(); // 31-12-2002
  // jump to rDate = tomorrow_1, both RHS are objects, but assign a reference by today.
  Date &rDate = today_2;
  today_2.print(); // 25-11-2001
  rDate.print(); // 25-11-2001

  today_2.next(); // 26-11-2001
  rDate.next(); // 27-11-2001
  rDate.print(); // 27-11-2001
  today_2.print(); // 27-11-2001
  tomorrow_1 .print(); // 31-12-2002
  rDate = tomorrow_1; // --> **** today_2 is changed as well, changed to tomorrow_1
  today_2.next(); // 28-11-2001
  rDate.next(); //??? 29-11-2001 or 01-01-2003
  today_2.print(); // 02/01/2003
  rDate.print(); // 02/01/2003
  tomorrow_1.print(); //02/01/2003
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<< int Date:equal (Date& aDate) the input is a reference of the object <<<<<<<<<<<<<<<<<<\n";
  Date today_3, tomorrow_2;
  if (tomorrow_2.equal(today_3)){
    cout << "today_3 and tomorrow_2 are \n";
  }

  cout << "<<<<<<<<<<<<<<<<< References, Pointers and Call by Value Parameter, f1, f2 and f3 <<<<<<<<<<<<<<<<<<\n";

  Date d(2, 12, 2222);
  Date* p = new Date (15, 1, 1919);
  Date& r = d;

  d.print();
  p->print();
  r.print();
  cout << '\n';

  // f1
  cout << "the function f1(Date aDate) would change anything on the passed in obj as it takes a copy of the passed in obj. \n";
  f1(d);
  d.print(); // 3-12-2222 --> wrong
  f1(*p);
  p->print(); // 13-1-1919 -- wrong
  f1(r);
  r.print(); // 4-12-2222  -- wrong

  // f2
  cout << "f2 function takes in a pointer variable pointing to the object type Date. it does change the properties of the passed in obj or whatever! \n";
  f2(&d);
  d.print(); // 3-12-2222
  f2(p);
  p->print(); // 16-01-1919
  f2(&r);
  r.print(); // 04-12-2222

  // f3
  f3(d);
  d.print(); // 05-12-2222
  f3(*p);
  p->print(); // 17-01-1919
  f3(r);
  r.print(); // 06-12-2222

  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<< References VS Pointers <<<<<<<<<<<<<<<<<<\n";
  int ii = 10;
  int iii = 100;

  int &rr = ii; // reference, &ii and &rr should be sharing the same address.
  int* pp = &ii; // pointer

  cout << "& of ii, rr, and pp--> " << &ii << '\t' << &rr << '\t' << &pp << '\n';

  cout << "values stored in ii, rr, and pp--> " << ii << '\t' << rr << '\t' << pp << '\n';

  rr = 100;
  cout << "after rr = 100 --> \n";
  cout << "& of ii, rr, and pp--> " << &ii << '\t' << &rr << '\t' << &pp << '\n';

  cout << "values stored in ii, rr, and pp--> " << ii << '\t' << rr << '\t' << pp << '\n';
}
