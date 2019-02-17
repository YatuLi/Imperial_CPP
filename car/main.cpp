#include <iostream>
#include <string>

using namespace std;

class Car;

class Passenger{
private: // only instances of class Passenger can access this atribute
  double weight;
  string name;

public: // public operation
  Passenger(string n, double w){
    name = n; // -> (*this).name = n; -> this->name = n;
    weight = w;
  }

  void print_details(ostream &out){
    out << name << " (" << weight << "Kg)" << '\n';
  }

  void diet();
  void eat (double food_weight){
    cout << "Passenger(" << this << ") eat called." << '\n';
    weight += food_weight;
  }

  bool get_into(Car &c);

  double get_weight() const {
    return weight;
  }

  friend ostream& operator<< (ostream& out, const Passenger& p);

};

ostream& operator<< (ostream& out, const Passenger& p){ // &p here is not a pointer type, please bear in mind.
  out << "Passenger( "<< "name: "<< p.name << ", weight: " << p.weight << ")" << '\n';
  return out;
}

void Passenger:: diet (){
  if(weight > 40){
    weight -= 1.0;
  }
}

class Car{
private:
  int mileage;
  string colour;
  bool engine_on;
  double weight;
  int passenger_count;
  Passenger* rider[3]; // rider is an array of 3 pointers to passengers
public:
  Car(int m, string c, double w);
  void start (){
    engine_on = true;
  }

  void stop(){
    engine_on = false;
  }

  bool drive (){
    mileage ++;
  }

  bool take_passenger(Passenger& p){
    if (passenger_count >= 3){
      return false;
    }
    rider [passenger_count] = &p; // assign the Passenger object (the real not a copy) to the array rider.
    passenger_count++;
    weight += p.get_weight();
    return true;
  }
};

Car::Car(int m, string c, double w){
  mileage = m;
  colour = c;
  engine_on = false;
  weight = w;
  passenger_count = 0;
  for (int n = 0; n < 3; n++){ // when having an array of pointers as a data member, we initialise it using a for statement.
    rider[n] = NULL; // for a pointer of other objs, we initalise them as NULL pointers for sure.
  }
}

bool Passenger::get_into(Car& c){
  return c.take_passenger(*this);
}

int main(){

  Passenger alice ("Alice", 60), bob("Bob", 70);

  Car bmw(10000, "Red", 1200);

  Car *mini = new Car (50000, "Mini", 750);

  alice.print_details(cout);

  alice.eat(5);
  bob.eat(3);

  cout << alice << endl;

  for (int days = 0; days < 5; days ++){
    alice.diet();
  }

  cout << alice << endl;

  if (bob.get_into(bmw)){
    cout << "lets go!" << endl;
  }else {
    cout << "Sorry Bob" << endl;
  }

  bob.get_into(bmw);
  bob.get_into(bmw);

  if (bob.get_into(bmw)){
    cout << "lets go!" << endl;
  } else{
    cout << "sorry bob" << endl;
  }


  return 0;
}
