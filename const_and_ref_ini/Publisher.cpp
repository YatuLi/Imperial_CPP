#include "Publisher.h"

using namespace std;

Publisher::Publisher(int l)
  : licenceNr(l){
  // licenceNr = 1; // const data memb must be initialised in the initialiser
  numberBooks = 0; // it could be initialised here without any problems
};
