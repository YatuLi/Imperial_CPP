/*
Test driven development:
      Consider possible cases, and when there is a leeway, decide the expected behaviour. This can be reflected in a “test plan” for the particular class.  For example, indicating the possibilities in italics, and the choices by strike-through:
1)are empty lists possible? yes, no
2)a list with one element
3)a list with several elements
4)add an element into an empty list
5)add  an element into a nonempty list
6)insert element after another that exists in list
7)insert  element after a non-existing: void, error, insert at end
8)remove an element that is in the list
9)remove an element that is not in the list: void, error
10)remove an element from the empty list: void, error
*/

#include <iostream>

using namespace std;

#include "DLink.h"

class DLinkList{
  DLink *firstLink; // first link of chain
public:
  DLinkList();
            // 1: creates new, empty doubly linked list, constructor reflects decision on 1.
  void insert(int x);
            // insert a new link with x at the end of the list
  void insertAfter(int x, int y);
            // inserts new link with x in list after y;
                // 7: y not in list, then nothing inserted.
  bool isEmpty() const;
            // true if receiver is an empty list
  int length () const;
            // number of elements in the list
  void remove(int x);
            // 9, 10: does nothing if x not in list.
  friend ostream& operator<< (ostream&, const DLinkList&);
            // prints list forwards
  friend ostream& operator>>(ostream&, const DLinkList&);
            // // prints list backwards
}
