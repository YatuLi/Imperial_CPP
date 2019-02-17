#include <iostream>

using namespace std;

class Human{
  virtual void enjoying () = 0; // a pure virtual function is defined here using a pure specifier (=0) in the declaration of a virtual member function in the class declaration. it won't return any 0 based value but =0 is just a sign.

public:
  Human(){

  }

  void holiday (){
    cout << "spends holidays";
    enjoying();
  }
};

class Italian: public Human{
  void enjoying () override {
    cout << "on the beach" << '\n';
  }
};

class Swede: public Human{
  void enjoying() override {
    cout << "in the sauna" << endl;
  }
};

// TODO: for onw test purposes
class Roma: public Italian{
private:
  void enjoying () override {
    cout << " to buy Bvlgari necklace" << endl;
  }

  void thingToBuy(){
    cout << "Roma has Bvlgari and Fendi" << '\n';
  }

  // Error: enjoying() cannot be overloaded.
  // void enjoying (){
  //   cout << "an enjoying () without 'override' following it. " << '\n';
  // }
};

int main(){
  Italian giuseppe;
  Swede* stefan = new Swede();

  cout << "Giuseppe "; giuseppe.holiday();
  cout << "Stefan "; stefan->holiday();

  // TODO: Roman & italian
  Italian* obj_1 = new Roma();
  // Error: cannot assign a mother class type into a child class type
  // Roma* obj_2 = new Italian();

  // TODO: test if the obj_1
  cout << "Yatu "; obj_1->holiday();
  // Error: the obj_1 has the type of mother class, so it cannot call the sub-class's members;
  // obj_1->thingToBuy();


  //Error:
  // the class Human is an abstract class as it gets =0 without the definitino of the method.
  // it is not allowed to have an obj of an abs class;
  // Human* regHuman = new Human();
  // regHuman->holiday();

}
