#include<iostream>
#include<string>

#include "BMI.h"
using namespace std;

int main(){
  string name;
  int height;
  double weight;

  cout << "Enter your name: ";
  cin >> name;
  cout << "Enter your height (in inches): ";
  cin >> height;
  cout << "Enter your weight (in pounds): ";
  cin >> weight;

  // create an object
  BMI Student_1(name, height, weight);

  cout << '\n' << "Paitient Name: " << Student_1.getName() << endl << "Height: " << Student_1.getHeight() << endl << "Weight: " << Student_1.getWeight() << '\n';\

  BMI Student_2;
  Student_2.setName(name);
  Student_2.setHeight(height);
  Student_2.setWeight(weight);
  Student_2.calculate();

  cout << '\n' << "Paitient Name: " << Student_2.getName() << endl << "Height: " << Student_2.getHeight() << endl << "Weight: " << Student_2.getWeight() << "BMI is: " << Student_2.calculate() << '\n';



  return 0;
}
