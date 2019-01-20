#include "Book.h"

Book::Book(char* t){
  title = new char[strlen(t) + 1];
  strcpy (title, t);
  serialNumber = ++ counter;
  cout << "constr " << title  << " at " << serialNumber << '\n';
}

Book::~Book(){
  cout << " del " << title << " from " << serialNumber << "; BC = " << --counter << endl;
  delete [] title;
}

// static variable is required to be initialised before using it.
int Book::counter = 0;

void Book::printNumberBooks(){
  cout << "== there are " << counter << " Books \n";
  cout << "This function calls a static variable. \n";
}
