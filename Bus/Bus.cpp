#include "Bus.h"

void Bus::havePassengerEnter(Passenger* p){
  size_t i = 0;
  while (i < 100 && occupants[i] != NULL){
    if (occupants[i] == p){
      return;
    }
    i ++;
  }
  occupants [i] = p;
  p.setCurrentOccupiedBus(this);
}

void::havePassengerLeave(Passenger* p){
  p.setCurrentOccupiedBus(NULL); // occupiedBus = NULL;

  size_t i = 0;
  while (i < 100 && occupants[i] != NULL && occupants[i] != p){
    i ++
  }
  if (occupants[i] == p){
    while (i < 100 && occupants[i] != NULL){
      occupants[i] = occupants[i+1];
    }
  }
}

void Bus::havePassengerTransfer(Passenger* p, Bus& from, Bus& to){// optional parameter --> pointers, parameters --> reference
  from.havePassengerLeave(p);
  to.havePassengerEnter(p);

}

Bus* Bus::getFullBus(){
  Bus* b1 = new Bus;
  Bus* b2 = new Bus;

  Passenger* holger = new Passenger;
  Passenger* will = new Passenger;
  Passenger* fidelis = new Passenger;
  b1->havePassengerEnter(holger);
  b2->havePassengerEnter(will);
  b2->havePassengerEnter(fidelis);
  // b2->havePassengerLeave(fidelis);
  // b1->havePassengerEnter(fidelis);
  b->havePassengerTransfer(fidelis);
  return b1;
}
