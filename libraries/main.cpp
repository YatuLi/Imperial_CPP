#include <iostream>
#include <string>

using namespace std;

class Item;

class LibraryUser{
private:
  string name;
  int items_borrowed_count;
  Item* item_borrowed[3]; // an array of pointers to Item.

public:
  LibraryUser(string u) : // get other operations within this constuctor.
    name (u){
      items_borrowed_count = 0;
      for (int c = 0; c < 3; c++){
        item_borrowed[c] = NULL;
      }
    }
};

class Item{
protected:
  int location;
  string title;
  LibraryUser* borrowed_by;
public:
  Item(string t, int l):
  title(t),
  location(l){
    cout << "Item( " << this << "): constructing with '" << title << "' at location " << location << endl;
    borrowed_by = NULL; // when it is got instaniated, it has nothing to point to.
  }

  virtual int get_loan_period() const=0;
};

class Book: public Item{ // book class takes after attributes and methods from Item class
private:
  int loan_period;
public:
  Book (string t, int l, int lp):
    Item (t,l), // obj Item is contained in other obj, must be, instaniated in member initialiser, this is what it does
    loan_period(lp){
      cout << "Book( " << this << "): constructing with load_period = " << loan_period << '\n';
    }
    int get_loan_period() const{
      return loan_period;
    }
};

class Periodical: public Item{
private:
  static int loan_period; // its not necessarily to initialise it in the first place.
public:
  Periodical(string t, int l): Item(t, l){

  }

  int get_loan_period() const{
    return loan_period;
  }

  // uses a particular method, a static one, to set it up,  one attribute defined in its parent class, rather than in a constructor.
  static void set_loan_period (int lp){
    loan_period = lp;
  }
};

// a way to initialise the value of a static member's value.
int Periodical::loan_period = 5;

int main(){
  Book cppwt ("C++ Without Tears", 1, 10);
  Book hhgitc ("Hitechhiker's Guide to IC", 2, 13);

  Item *i = &cppwt; // assigned by the address of an obj's address of its derived class, Book.
  cout << i->get_loan_period() << '\n';
  Periodical::set_loan_period(7);

  Periodical atww80("Around....", 3);
  Periodical tmuqt ("20m under the Queen's Tower", 4);

  LibraryUser ali ("ali");
  LibraryUser georgia ("georgia");

  return 0;
}
