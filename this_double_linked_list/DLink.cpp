#include "DLink.h"

DLink::DLink(int x){
  next = nil;
  prev = nil;
  contents = x;

DLink::~DLink(){
  DLink* oldPrev = prev;
  DLink* oldNext = next;

  if(!(oldPrev == nil)){
    oldPrev->next = oldNext;
  }
  if(!(oldNext == nil)){
    oldNext->prev = oldPrev;
  }
}

DLink* DLink::lastLink(){
  if (next == nil){
    return this;
  }else{
    return next->lastLink();
  }
}

void DLink::insertAfterThis(int x){
  DLink* oldNextLink = next;
  DLink* newLink = new DLink(x);
  next = newLink;
  newLink->prev = this;
  if (oldNextLink != nil){
    oldNextLink->prev = newLink;
    newLink->next = oldNextLink;
  }
}

ostream& operator<<(ostream& o, const DLink& l){
  o << l.contents << "-";
  if (l.next == nil){
    o << "---\n";
    return o;
  }else{
    o << (*(l.next));
    return o;
  }

ostream& operator>>(ostream& o, const DLink* l){
  o << l.contents<< "-";
  if (l.prev == nil){
    o << "---\n";
    return o;
  }else{
    o >> (*(l.prev));
    return o;
  }
}

DLink* DLink::find(int x){
  if (contents == x){
    return this;
  }else{
    if (next == nil){
      return nil;
    } else{
      return next->find(x);
    }
  }
}

int DLink::length() const{
  if (next == nil){
    return 1;
  }else{
    return 1 + next->length();
  }
}
}

}
