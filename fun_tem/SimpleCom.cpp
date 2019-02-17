/*
  this source file is more about the function template SimpleCom(const T& a, const T& b), which helps the class template SortedList with all types of comparisons.

  But it does have a compilable ExtendableArrayBetter but currently, some problems existing in SortedList which is an instantiation of class template ExtendableArrayBetter.

  This log is done at 21:46, 17/02/2019.
*/


#include <iostream>

using namespace std;

int INT_MAX = 1000;

template <class T, int MAXCAP = INT_MAX>
class ExtendableArrayBetter{
  // private members, just declare them without assignment
  int _count, _capacity;
  T* store;

  // this is the key function, to increase the size of the array with all the old elements;
  void resizeStore(){
    T* new_store = new T [_capacity]; // it calls the data member straightaway
    for (int index = 0; index < _count; index ++){
      *(new_store + index) = *(store + index);
    }
    delete [] store;
    store = new_store;
  }

public:
  ExtendableArrayBetter(int cap = 10): // first gurad: check if the user has provided the cap a value here
    _count (0){
      if (cap < 0) cap = 0; // 2nd guard: check if the cap is within the range
      else if (cap > MAXCAP) cap = MAXCAP; // 3rd gurad: cap cannot be too big
      _capacity = cap;
      store = new T [cap]; // int* myArray = new int [SIZE];
    }

  virtual ~ExtendableArrayBetter(){
    delete [] store;
  }

  int count () const{
    return _count;
  }

  int capacity() const{
    return _capacity;
  }

  T& operator[] (int index){
    return store[index]; // built-in type in pointer related and raw array.
  }

  const T& operator[] (int index) const {
    return store[index];
  }

  // changes:
  bool ensureCapacity(int cap){
    if (cap > MAXCAP){
      return false;
    }

    if (_capacity < cap){
      while (_capacity < cap){
        if (_capacity < MAXCAP/2){
          (_capacity *= 2)++;
        } else {
          _capacity = MAXCAP;
          break;
        }
      }

      resizeStore();
    }
    return true;
  }

  bool insert (T value, int index){
    if (index < 0) index = 0;

    int new_count = 0;
    // it doesnt matter how big the index is, as long as its greater than _count, the new element is added at the end of the array;
    if (index > _count){
      new_count = index + 1;
    } else{
      new_count = _count + 1;
    }

    if (!ensureCapacity(new_count)){
      return false;
    }

    //shifts elements:
    for (int i = _count; i > index; i --){
      *(store + i) = *(store + i - 1);
    }

    // actual insertion:
    store [index] = value;
    _count = new_count;

    return true;
  }

  // add a new element at the end of the array. --> normal way to add element, we say we append an element to the array.
  bool append(T value){
    return insert(value, _count);
  }

  bool remove (int index){
    if (index < 0 || index > _count){
      return false;
    }

    // shitfs elements, overwritting the removed;
    for (int i = index + 1; i < _count; i ++){
      store [i - 1] = store [i];
    }

    // Another moethod to realise a control of number of shifts required to make up the empty place after taking the indexed element out.
    // int ii = 0;
    // while (ii < _count - index - 1){
    //   store [index] = store[index + 1];
    //   index ++;
    //   ii ++;
    // }

    _count --;
    return true;
  }
};

// This is is a function template... for simpleCompare.
template <typename T>
int simpleCompare (const T& a, const T& b){
  if (a < b){
    return -1;
  } else if (a == b) {
    return 0;
  } else {
    return 1;
  }
}

template <typename T,
  int (*comp)(const T& a, const T& b) = simpleCompare,
  int MAXCAP = INT_MAX>
class SortedList : private ExtendableArrayBetter <T, MAXCAP>{

  // make Base as an aliase of ExtendableArrayBetter, as Base is easier to write than the long word ExtendableArrayBetter.
  typedef ExtendableArrayBetter <T> Base;

  const T err_val;

  int locate (T value) const{
    int head = 0;
    int tail = count();
    while (head < tail){
      int mid = (head + tail)/2;
      if ((*this)[mid] < value){
        head = mid + 1;
      } else if ((*this)[mid] == value) {
        return mid;
      } else {
        tail = mid;
      }
    }

    return head;
  }

  public:
  int indexOf (T value) const{
    int index = locate (value);
    if (index < count() && (value == (*this)[index])){
      return index;
    }
    return -1;
  }

  SortedList (int cap = 10, const T ev = 0):
    Base (cap), err_val(ev){}

  using Base::count;

  void add(T value){
    this->insert (value, locate(value));
  }

  bool removeAt (int index){
    return this->remove(index);
  }

  T get(int index) const {
    if (0 <= index && index < count()){
      return (*this)[index];
    }
    return err_val;
  }
};

int main(){
  char x = 'x';
  char y = 'y';

  struct Point{
    int x, y;
    Point (int x = 0, int y = 0):
      x(x),
      y(y){

      }
  }

  p1 (1, 1);

  cout << "x vs y: " << simpleCompare<char>(x,y) << endl;
  // OUT: x vs y: -1
  cout << simpleCompare(x, y) << endl;
  // Implicit Instantiation: simpleCompare<char>. OUT: x vs y: -1

  // this is how we use struct, like an obj.
  cout << "p1.x vs p1.y: " << simpleCompare(p1.x, p1.y) << endl;
  // Implicitly Instantiation: simpleCompare<int> OUT: p1.x vs p1.y
}
