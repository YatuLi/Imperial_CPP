#include <iostream>

using namespace std;

class ExtendableIntArray{
  int _count, _capacity;
  int* store;

  // a pricate function.
  void resizeStore(){
    int* new_store = new int [_capacity]; // new int[]. new double[], new long[]
    for(int i = 0; i < _count; i ++){
      new_store[i] = store[i];
    }
    delete [] store;
    store = new_store;
  }

public:
  ExtendableIntArray(int cap = 10):
    _count (0){
      if (cap < 0) {
        cap = 0;
      }
      _capacity = cap;
      store = new int[cap];
    }

  virtual ~ExtendableIntArray(){ // override function in subclass, virtual functin is defined in the base class for base function.
    delete [] store;
  }

  int count() const{
    return _count;
  }

  int capacity() const{
    return _capacity;
  }

  int& operator[](int index){
    return store[index];
  }

  const int& operator[] (int index) const{ // 2nd const: applied as a member function qualifier, it means this method can be called when the calling instance of your class is const qualified.
    return store[index];
  }

  void ensureCapacity(int cap){
    if (_capacity < cap){
      while (_capacity < cap){
        (_capacity *= 2)++;
      }
      resizeStore();
    }
  }

  void append(int value){
    ensureCapacity(_count + 1); // count = 0;
    store[_count++] = value;
  }

  void compact(){ // it takes out extra volume if the actual count is less than the number of element the array is designed to hold.
    if (_capacity > _count){
      _capacity = _count;
      resizeStore();
    }
  }

  friend void print (ExtendableIntArray&);
};

void print (ExtendableIntArray& arr){
  int size = arr._count;
  int index = 0;
  while (index < size){
    cout << *(arr.store + index) << '\n';
    index ++;
  }
}

// what if we want to have this ExtendableI***Array (*** = double, float, long, char....) --> we use Template

int main(){
  ExtendableIntArray arr(5);

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
