#include <iostream>
#include <string>

using namespace std;

// these 4 components below are must as per requirement.
class RAM{

};

class CPU{

};

class Chassis{

};

class Fan{

};

// #define MAX_CAPACITY 4
const int MAX_CAPACTTY = 4;

class SystemBox{
private:
  Chassis cage; // directed embedded --> what time to use run time obj rather than a pointer type
  CPU* processor;
  RAM* dimms[MAX_CAPACITY];
  int number_of_ram_installed;

public:
  SystemBox(CPU* p): processor(p){ // its not a reference data member, processor, but it is still initialised in the member initialiser. (another requirement is the const, if a const is about to be initialised, getta put it in the member initialiser. processor(p) == processor = p;),
    // okay, non-const and non-reference data member may, but need not, also be treated in initialiser.
    for (int n = 0; n < MAX_CAPACITY; n++){
      dimms[n] = NULL;
    }
    number_of_ram_installed = 0;
  }

// when there are less than 4 installed, assign the pointer obj to the array of obj RAM.
bool install_ram(RAM* d){ // why it takes a pointer here?
  if (number_of_ram_installed >= 4){
    return false;
  }
  dimms [number_of_ram_installed++] = d;
}
};

// These 3 components are not compulsory for the SystemBox.
class keyboard{ // aggregation to SystemBox, but not essential

};

class Mouse{ // aggregation to SystemBox, but not essential

};

class Monitor{ // aggregation to SystemBox, use * as its multiplicity, as there must be at least one monitor to the SystemBox.
};

class Workstation{
private:
  string hostname;
  SystemBox box; // a regular runtime obj again
  Mouse *mouse; // if its not an essential part, put it up as a pointer type?
  Keyboard &kbd; // if its not an essential part, put it up as a pointer type?
  int monitors;
  Monitor *monitor[256];
public:
  Workstation(string name, CPU* chip, keyboard &k):
    hostname (name),
    box(chip),
    kbd(k){ // &kbd, the reference data member must be initialised in member initiailiser.
      mouse = NULL;
    }
};

int main(){
  CPU inteli9;
  keyboard keys; // look donw at the Workstation, so you get to instanistate
  Mouse mymouse;

  Workstation swordfish("swordfish", &inteli9, keys);
  return 0;
}
