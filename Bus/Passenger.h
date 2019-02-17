#include <iostream>

using namespace std;

class Passenger{
  string name;
  Bus* occupiedBus; // non-owing
public:
  string getName();
  Bus* getCurrentlyOccupiedBus();
  void setCurrentOccupiedBus();
}
