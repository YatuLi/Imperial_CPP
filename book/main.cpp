#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include "Book.h"

using namespace std;

extern int counter;
int main(){
  Book b1 ("Seagull"); // okay, as main finishes off, the runtime obj will also be removed. the destructor tells us when it happens.
  Book *b2, *b3;
  // when the block finishes its execution, the runtime obj inside would resign it off from the stack. This is why do we have 'Iron Mask' is called to be self-destroyed.
  {
    Book b4("Iron Mask"); // a runtime obj, who does it calls destructor?
    b2 = new Book("Moonstone");
    Book *b5 = new Book("Tom Sawyer");
  }

  b2 = new Book ("Polynna");
  b2 = new Book ("Shogun");
  b3 = b2;
  delete b3;

  // cout << "Now " << counter << "books left \n";


  cout << "Compare to JAVA, we call static variable in C++ by including its class name. Where in java you just call it anywhere whenever you have an obj by you hand. \n";
  Book::printNumberBooks();
  return 1;
}
