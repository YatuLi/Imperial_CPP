#include "DLink.h"

DLinkList::DLinkList(){
  firstLink = nil; // nil is a DLink pointer potining to 0.
}

void DLinkList::insert(int x){
  if (firstLink == nil){// empty list
    firstLink == new DLink(x);
  }else {
    (firstLink->lastLink())->insertAfter(x);
  }
}

bool DLinkList::isEmpty() const{
  return (firstLink == nil;)
}

int DLinkList::length() const{
  if (firstLink == nil){
    return 0;
  }else {
    return firstLink->length();
  }
}

void DLinkList::insertAfter(int x, int y){
  if (firstLink == nil){
    return; // empty list
  }else{
    DLink* theLink = firstLink->find(y);
    if (theLink == nil){// y not in list
      return; // 7: do nothing
    }else{
      theLink->insertAfterThis(x);
    }
  }
}

void DLinkList::remove(int x){
  if (firstLink == nil){// empty list
    return ; // 10: do nothing
  }else {
    DLink* theLink = firstLink->find(x);
    if (theLink == nil){ // not found
      return; // 9: do nothing
    }else{
      if(theLink == firstLink){
        // its the first element
        firstLink = theLink->next;
        delete theLink;
      }
    }
  }
}
////////////??????? A lot of problems i get here.
ostream& operator<<(ostream& o, const DLinkList& l){
  if(l.firstLink == nil){
    o << "----\n";
  }else{
    o << *l.firstLink;
  }
  return o;
}

ostream& operator>>(ostream& o, const DLinkList& l){
  if(l.firstLink == nil){
    o << "---\n";
  }else{
    o >> *l.firstLink->lastLink();
  }
  return o;
}
