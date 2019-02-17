#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

#include "Book.h"

using namespace std;

int main(){
  Publisher AddisonWesley (23);
  Publisher OxfUniPress (24);
  Book AliceInWonderland (AddisonWesley, 88);
  Book NavigatingCPP (AddisonWesley, 7998);
}
