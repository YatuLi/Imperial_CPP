#include "Compl.h"

using namespace std;

Compl operator+ (const Compl& z1, const Compl& z2){
  return Compl((z1.re + z2.re), (z1.im + z2.im));
}

Compl operator- (const Compl& z1, const Compl& z2){
  return Compl((z1.re - z2.re), (z1.im - z2.im));
}

Compl operator/ (const Compl& z1, const Compl& z2){
  return Compl((z1.re / z2.re), (z1.im / z2.im));
}

Compl operator* (const Compl& z1, const Compl& z2){
  return Compl((z1.re * z2.re), (z1.im * z2.im));
}

// contents on the RHS of the << are the parameters, so the << pick the obj Compl and take the c.re and c.im to be printed out.
ostream& operator<< (ostream& o, const Compl& c){
  o << "(r " << c.re << ", i " << c.im << " )\n";
  return o;
}

Compl::Compl(double r, double i){
  re = r;
  im = i;
}
