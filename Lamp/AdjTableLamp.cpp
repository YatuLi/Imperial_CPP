#include <iostream>

using namespace std;

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
