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
};

class AdjTableLamp: public TableLamp{
  float brightness;
public:
  AdjTableLamp(){
    brightness = 1.0;
  }

  void dim(){
    if (brightness > 0.1){
      brightness -= 0.1;
    }
  }

  void print(ostream& o) const{
    o << *this << " with brightness " << brightness << endl;
  }
};

int main(){

  AdjTableLamp myLamp;

  cout << "myLamp";
  myLamp.print(cout);

  return 1;
}
