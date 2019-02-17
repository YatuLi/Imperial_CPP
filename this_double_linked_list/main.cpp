#include <iostream>
#include "DLinkList.h"

using namespace std;

int main(){
  DLinkList list;
  // 1: printing an empty list
  cout << list;
        // out ---

  // 2: inserting the first element
  // 2: printing list with one element
  list.insert(6);
  cout << list << '\n' >> list;
        // out 6 --- forward printing
        // out 6 --- backward printing

  // 3: inserting 8, 12, 14
  list.insert(8);
  list.insert(12);
  list.insert(14);
  cout << list << endl >> list;
        // out 6 - 8 - 12 - 14
        // out 14 - 12 - 8 - 6

  // 6: inserting 10 after 8
  list.insertAfter (10, 8);
  cout << list << endl >> list;
        // out 6 -8 -10 -12 -14
        // 14 - 12 - 10 - 8 -6

  // 7: inserting 100 after 500
  list.insertAfter (100, 500);
  cout << list << endl >> list;
        // out 6 - 8 - 12 - 14 - ----
        // out 14 - 12 - 8 - 6

  // 9: removing an element that is not in the list
  list.remove (500);
  cout << list << endl >> list;
        // out 6 - 8- 10 -12 - 14 ---
        // out 14 - 12- 10 - 8 -6 ----

  // removing an element from middle of list
  list.remove(10);
  cout << list << endl >> list;
        // out 6 -8 - 12 -14 ----

  // 8:removing the first element
  list.remove(6);
  cout << list << endl >> list;
        // out 8 - 12 ----
        // out 14 - 12 -8 ----

  // 8: removing the last element
  list.remove (14);
  cout << list << endl >> list;
        // out 8 -12
        // 12  -8

  // 8: removing all elements
  list.remove(8);
  list.remove(100);
  cout << list << endl >> list;
        // out ---
        // out ---

  return 1;

}
