// header ---> function declarartion goes in here

#include <iostream>
#include <string>

using namespace std;

#ifndef BMI_H
#define BMI_H

class BMI{
public:
  // default constructor: set member variables to null stats
  BMI();

  // Overload constructor
  BMI(string, int, double);

  // destructor
  ~BMI();

  // Accessor functions, return our member variables
  string getName() const; // dont modify any member variables
  int getHeight() const;
  double getWeight() const;

  // Mutator function: allow us to edit each of private member variable one at a time.
  void setName(string); // no const, as it changes member variables --> set name of a user
  void setWeight(double);
  void setHeight(int);

  double calculate() const; // just use member variable without passing them in to the function

private:
  // member variables
  string newName;
  int newHeight;
  double newWeight;

};

#endif
