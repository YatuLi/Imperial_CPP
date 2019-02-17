#include "Book.h"

using namespace std;

Book::Book(Publisher& p, int nr)
  : publishedBy(p), numberPages(nr){
  // publishedBy = p; // reference data member must be initialised in the member initialiser
  // numberPages = nr; // const member variable must be initialised in the member initialiser
  soldSoFar = 0; // a private but not const
}
