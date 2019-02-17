#include "Passenger.h"

string Passenger::getName(){
  return name;
}

Bus* Passenger::getCurrentlyOccupiedBus(){
  return occupiedBus;
}

void Passenger::setCurrentOccupiedBus(Bus* b){
  occupiedBus = b;
}
