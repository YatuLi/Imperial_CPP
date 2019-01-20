#include "Date.h"

// using namespace std;

Date::Date(){
  // these 3 are public vairables.
  day = 0;
  month = 0;
  year = 0;
}

//>>>>>>>>>>>>>>>>>. uncomment this part to see problems
Date::Date(int day, int month, int year){
  if (day < 1 || day > 32){
    cout << "the input day is out of scope \n";
  } else if (month < 0 || month > 12){
    cout << "the input month is out of scope \n";
  } else if (year < 0){
    cout << "pls give at least a start of the calendar --> 0, as its a Gregorian \n";
  }
  this->day = day;
  this->month = month;
  this->year = year;
}

void Date::next(){
  day++;
  if (this->day == 32){
    day = 1;
    month++;
  }
  if ((*this).month == 13){
    month = 1;
    year ++;
  }
}

bool Date::equal(Date aDate){
  return ((day == aDate.day) && (month == aDate.month) && (year == aDate.year));
}

// overloaded functions should have the same return types.
int Date::equalByReference(Date& aDate){
  cout << "in the return statement of this function, \'aDate.day == day\', the the first day is the \'day\' of aDate object, which is passed in explicitly. While the day after the equal sign is the \'day\' of calling object, which passed in implicitly. --> hence, we have an explictily and implicitly passed arguments. \n";
  return (aDate.day == day) && (aDate.month == month) && (aDate.year = year);
}

void Date::print(){
  cout << day << "/" << month << "/" << year << '\n';
}

//  why can't i include those functions here and initialise an obj in main to call them.

//
// void f1(Date aDate){
//   aDate.next();
// }
//
// void f2(Date* pDate){
//   pDate->next();
// }
//
// void f3(Date& rDate){
//   rDate.next();
// }
