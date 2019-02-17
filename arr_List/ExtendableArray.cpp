#include <iostream>

using namespace std;

template <typename T> // <class T> is also valid
class ExtendableArray{
  int _count, _capacity;
  T* store;

  void resizeStore(){
    // it doesnt care about how big the _capacity is, but just use it to create a new array
    T* new_store = new T[_capacity];
    for (int i = 0; i < _count; i++){
      new_store[i] = store[i];
    }
    delete [] store;
    store = new_store;
  }

public:
  ExtendableArray(int cap = 10):
    _count(0){
      if (cap < 0){
        cap = 0;
      }
      _capacity = cap;
      store = new T[cap]; // initialise a new array of element T.
    }

virtual ~ExtendableArray(){
  delete [] store;
}

int count () const {
  return _count;
}

int capacity() const {
  return _capacity;
}

T& operator [] (int index){
  return store[index];
}

const T& operator [] (int index) const {
  return store [index];
}

void ensureCapacity (int cap){
  if (_capacity < cap){
    while (_capacity < cap){
      (_capacity *= 2)++;
    }
    resizeStore();
  }
}

void append(T value){
  ensureCapacity(_count + 1);
  store [_count++] = value;
}

void compact(){
  if (_capacity > _count){
    _capacity = _count; // the key in function resizeStore() is _capacity, so everytime it changes, the resizeStore() must be called.
    resizeStore();
  }
}

// learnt an old thing: look back at it, a friend function makes more sense to take in an obj and do whatever it wants on all private members of the obj.
template <class U>
friend void print (ExtendableArray<U>&);

};

template<class T>
void print(ExtendableArray<T>& arr){
  int size = arr._count;
  int index = 0;
  while (index < size){
    cout << arr.store[index] << '\n';
    index ++;
  }
}

// method 1: define an independant function prtin() to go over all the elements of any array, this function is not a friend function of any class -> you get to define a lot of print() to take in different array with different elements. --> forego
// method 2: to define a friend function print() to go over all the elements, so there is no such restriction about what type of elements are stored in the array. --> realised.

int main(){
  ExtendableArray<double> arr(5);

  arr.append(1.1);
  arr.append(2.2);
  arr.append(3.3);
  arr.append(4.4);
  arr.append(5.5); // capacity(5) reached
  arr.append(6.6); // internal store extended to 11
  print (arr);
  // count: 6, Cap:11

  arr[2] = 30;
  print (arr);

  arr.ensureCapacity(50);
  print(arr);

  arr.compact();
  print(arr);
}
