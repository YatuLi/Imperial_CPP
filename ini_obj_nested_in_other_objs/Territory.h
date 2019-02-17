#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

#include "Point.h"

using namespace std;

class Territory{
  Point sw, ne;
public:
  Territory(int, int, int ,int);
  // Territory (Point, Point); // this would be a better design.
  area(Point&);
};
