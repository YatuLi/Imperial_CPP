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

  AdjTableLamp myLamp; // the obj from child class.

  cout << "myLamp";
  myLamp.print(cout); // starts from print(o), then, from L to R, *this --> const TableLamp& t, but you dont print out t but t.state, which is evaluted to "is on".

  myLamp.dim();
  cout << "myLamp";
  myLamp.print(cout);

  myLamp.pressSwitch();
  cout << "myLamp" << myLamp << '\n';

  TableLamp yourLamp; // the obj from parent class
  AdjTableLamp* hisLamp = new AdjTableLamp(); // define a child class on the heap.

  cout << "hisLamp";
  hisLamp -> print(cout); // cout is defined by default, if you put an 'out', it doesnt recognise.
  cout << "the address of hisLamp is " << hisLamp << '\n';
  cout << "the address of the pointer pointing to TableLamp is " << &hisLamp << '\n';
  cout << "the thing pointed to by *hisLamp is " << *hisLamp << " which has been customised by friend ostream& ope<< ()" << '\n';

  hisLamp -> pressSwitch();
  cout << "hisLamp" << *hisLamp << '\n';

  cout << "<<<<<<<<<<<<<<<<<<< implicit conversion of pointers <<<<<<<<<<<<<<<<<<<<< \n";
  TableLamp* herLamp = new TableLamp();
  herLamp = hisLamp; //hisLamp is a derived type.
  TableLamp theirLamp;
  herLamp = &myLamp; // pointers to a derived class maybe implicitlyl converted to pointers to a base class. but not vice-versa
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<< assignment and inheritance <<<<<<<<<<<<<<<<<<<<< \n";
  AdjTableLamp atl_1; // derived type
  TableLamp tl_1; // base type

  atl_1.pressSwitch(); // atl_1.state = OFF
  cout << "atl_1 (derived type originally) ";
  atl_1.print(cout);
  cout << "tl_1 (base type originally) " << tl_1 << endl; // tl_1 = ON

  tl_1 = atl_1; // assgin the base type by derived type (assign the derived type to base type), explicitly.
  // just copies of attributes are copied and pasted from derived to base. When derived is changed, the base type still keeps the value when drived type was assigned to it.
  cout << "tl_1 (base type originally) " << tl_1 << endl; // OFF

  atl_1.pressSwitch(); // atl_1.state = ON
  cout << "atl_1 (derived type originally) " << atl_1 << '\n'; // ON
  cout << "tl_1 (base type originally) " << tl_1 << '\n'; // OFF. --> still keeps the values when it got assigned by the derived type.
  cout << '\n';

  cout << "pointer types in assignment and inheritance \n";
  AdjTableLamp* atl_p1 = new AdjTableLamp(); // derived type, pointer, still on the heap, without new keywords
  TableLamp* tl_p1; // base type, pointer, still on the heap, without new keywords

  tl_p1 = atl_p1; // assign the derived type pointer to the base type pointer. But the features of base type can only be accessed by the tl_p1 not atl_p1, while they are pointing to the same obj which is pointed to by derived type pointer now.
  cout << "after tl_p1 = atl_p1 \n";
  cout << "tl_p1 (base type originally) " << *tl_p1 << '\n'; // ON
  cout << "atl_p1 (derived type originally) " ; // ON
  atl_p1->print(cout);

  atl_p1->pressSwitch();
  cout << "atl_p1 (derived type originally) ";
  atl_p1->print(cout); // OFF
  cout << "tl_p1 (base type originally) " << *tl_p1 << '\n'; // OFF

  cout << "even though tl_p1 is assigned by atl_p1, but the features of base type is only accessed by base type obj tl_p1 --> \n";
  atl_p1->dim();

  delete atl_p1;
  cout << "after delete atl_p1, lets see if tl_p1 is still there? " << &tl_p1 << '\n';
  cout << "after delete atl_p1, lets see if atl_p1 is still there? " << &atl_p1 << '\n';
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<<< Assignment and Inheritance: Reference (part 1) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  AdjTableLamp atl_2;
  TableLamp tl_2;

  AdjTableLamp& atl_r1 = atl_2;
  TableLamp& tl_r1 = tl_2;

  atl_r1.pressSwitch(); // from ON->OFF
  cout << "atl_r1 "; // OFF
  atl_r1.print(cout);
  cout << "tl_r1 " << tl_r1 << endl; // ON

  tl_r1 = atl_r1; // assign the derived type to base type, in their references

  cout << "after tl_r1 = atl_r1 \n";
  cout << "tl_r1 " << tl_r1 << '\n'; // OFF

  atl_r1.pressSwitch(); // from OFF->ON
  cout << "atl_r1 ";
  atl_r1.print(cout);
  cout << "tl_r1 " << tl_r1 << endl; // ON ****************************************** Note

  cout << "<<<<<<<<<<<<<<<<<<<<<<< Assignment and Inheritance: Reference (part 2) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
  AdjTableLamp atl_3, atl_4; // 3 and 4 are 2 runtime objs of derived type
  AdjTableLamp& atl_r2 = atl_3; // r2 and r3 are assigned
  TableLamp& tl_r2 = atl_4;

  atl_r2.dim(); // 0.9
  atl_r2.pressSwitch(); // OFF
  cout << "atl_r2 ";
  atl_r2.print(cout);
  cout << "tl_r2 " << tl_r2 << endl; // ON

  tl_r2 = atl_r2;
  cout << "tl_r2 = atl_r2 \n";

  cout << "tl_r2 " << tl_r2 << endl; // OFF, without brightness
  cout << "atl_4 ";  // ON, with brightness as 1 --> because of bond "TableLamp& tl_r2 = atl_4, so its OFF, but with default brightness as 1? *********************"
  atl_4.print(cout);

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Assignment of obj references <<<<<<<<<<<<<<<<<<< \n";
  AdjTableLamp atl_5;
  AdjTableLamp& atl_r3 = atl_5;
  TableLamp& atl_r4 = atl_5;

  cout << "atl_r3";
  atl_r3.print(cout); // ON, brightness 1

  atl_r4.pressSwitch();
  cout << "atl_r4 " << atl_r4 << '\n'; // OFF!
  cout << "atl_r3 "; // OFF, brightness - 1
  atl_r3.print(cout);



  return 1;
}
