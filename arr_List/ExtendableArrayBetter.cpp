#include <iostream>

using namespace std;

int INT_MAX = 1000;

// have a cap on the size of the internal store to avoid an array which is too large to handle.
// 1. apending or inserting to an ExtendableArrayBetter at full capacity: return false
// 2. remove data from an invalid location: return false
// 3. Be careful about the INT_MAX, which is defined above and out of the template, this is a parameter to tell the programme the max limit.
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

int main(){
  typedef ExtendableArrayBetter<char, 10> TinyArray;
  TinyArray arr(1);
  arr.append('a');

  return 0;
}
