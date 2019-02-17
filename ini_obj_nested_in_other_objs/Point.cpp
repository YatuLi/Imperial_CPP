#include "Point.h"

Point::Point(int l1, int l2){
  x = l1;
  y = l2;
}

int Point::length(int k, int l){
  return (k - l);
}
