#include <iostream>

using namespace std;

class Bus{
  Passenger* occupants [100]; // composition relatioship .

  void havePassengerEnter (Passenger* p);

  void havePassengerLeave (Passenger* p);

  Bus* getFullBus();

  void havePassengerTransfer (Passenger* p, Bus& from, Bus& to);

  // destructors, not only destory the Bus obj, but also Passenger obj.
  ~Bus(){
    while (i < 100 && occupants[i] != NULL){
      delete occupants [i++];
    }
  }

}
