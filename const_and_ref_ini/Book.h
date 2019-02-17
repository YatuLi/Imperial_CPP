#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

#include "Publisher.h"

using namespace std;

class Book{
  int soldSoFar;
  const int numberPages;
  Publisher& publishedBy;
public:
  Book (Publisher&, int); // this constructor takes in an obj of other types as an arg.
};
