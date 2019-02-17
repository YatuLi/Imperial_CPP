#include <iostream>

using namespace std;

class DLinkList; 

  class DLink{
    // all members are private
    // class DLinkList a friend
    // four friend operations
    // the NULL DLink Pointer.
    int contents;
      // the integers in the link
    DLink *next, *prev;
      // pointers to the next and previous links of the chain, possibly nil
    DLink(int);
    ~DLink();

    void insertAfterThis(int);
      // creates a new link containing x, and inserts after current link
    DLink* lastLink();
      // returns the last link in the chain.
    DLink* find (int x);
      // returns pointers to link with contents  x or nil, if no such link found
    int length() const;
      // returns the number of links in the chain.

    friend ostream& operator<< (ostream&, const DLink&); // prints list forward

    friend ostream& operator>> (ostream&, const DLink&);  // prints list backward

    friend ostream& operator<< (ostream&, const DLinkList&);
              // prints list forwards
    friend ostream& operator>>(ostream&, const DLinkList&);
              // // prints list backwards

    DLink* const nil = 0; // the null DLink pointer.
  }
