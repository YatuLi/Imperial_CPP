#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>
#include "Compl.h"

using namespace std;

int main(){
  Compl z1(2.2, 4.4);
  Compl z2(1.1, 3.3);

  cout << "z1 = " << z1 << "z2 = " << z2;
  cout << (z1 + z2);
  cout << (z1 - z2);
  cout << (z1 / z2);
  cout << (z1 * z2);
  cout << ((z1/z2) + (z1*z2)) - z1;

  return 1;
}
