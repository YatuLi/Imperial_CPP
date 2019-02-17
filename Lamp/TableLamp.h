#include <iostream>

using namespace std;

class TableLamp{
  enum {ON, OFF} state;
public:
  TableLamp(){
    state = ON;
  }

  void pressSwitch(){
    state = (state == ON ? OFF : ON); // if state == ON, assign it to OFF. Otherwise, make it ON
  }

  friend ostream& operator<< (ostream& o, const TableLamp& t){
    return o << (t.state == TableLamp::ON ? " is on" : " is off ");
  }
}
