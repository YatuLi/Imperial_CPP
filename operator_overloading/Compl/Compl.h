#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class Compl{
  double re, im;
public:
  Compl (double, double);
  friend Compl operator+ (const Compl&, const Compl&);
  friend Compl operator- (const Compl&, const Compl&);
  friend Compl operator/ (const Compl&, const Compl&);
  friend Compl operator* (const Compl&, const Compl&);
  friend ostream& operator<< (ostream&, const Compl&);
};

/*
  Note: dont get confused by the return type Compl, you can have tons of functions returning you an int but it doesnt necessariliy mean they are the same or part of the class int if it existed.

  here, the outlier functions are opeartor+, -, / and *. those guys need 'friend' to enable them to fully use whatever defined within this class.

  the names of them dont turn to light blue as they usually do thats probably because they are special ones.
*/
