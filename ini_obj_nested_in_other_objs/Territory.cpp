#include "Territory.h"

/*
Territory::Territory(int k, int l, int m, int n){
  sw = Point (k, l); // obj Point contained within other obj, the assignment in the body of the containing constructor is not legal.
  ne = Point (m, n);  // obj Point contained within other obj, the assignment in the body of the containing constructor is not legal.
}
*/

Territory::Territory(int k, int l, int m, int n)
  : sw (k, l), ne (m, n){ // dont panic about the missing types, there are defined in the header file.

  }
// int Territory::area(Point& p){
//   int
//   return (p.)
// }
