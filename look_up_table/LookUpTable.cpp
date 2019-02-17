#include <iostream>

using namespace std;

template <typename TKey, typename TVal,
  int (*keyComp) (const TKey& a, const TKey& b) = simpleCompare>
class Map{

  // Struct to represent a Key-Value pair
  struct KVP{

    TKey key;
    TVal val;

    // get 2 simple "constructors for struct KVP"
    KVP (TKey key) : key (key){}
    KVP (TKey key, TVal val):
      key(key), val(val){}

    // C++ allows a function defined inside of a struct as a stuct is a special class type in C++, but it will fail in C.
    static int comp(KVP* const& a, KVP* const& b){
      return keyComp(a->key, b->key);
    }

    // what does this line mean??
    SortedList <KVP*, KVP::comp> base; // instaniate a template as a new class, base.

    int locate (const TKey& key) const {
      KVP dummy(key); // lets say dummy is an obj of the KVP struct.
      return base.indexOf(&dummy); // T of SortedList is KVP*, look at above.
    }

  public:
    // adds a mapping from key to val,
    void insert(const TKey& key, const TVal& val){
      int idx = locate(key);
      if (idx == -1) base.add(new KVP(key, val));
      else base.get(idx)->val = val;
    }

    // retrieve a pointer to the value associated with key.
    TVal* get(const TKey& key) const{
      int idx = locate(key);
      if (idx == -1) return nullptr;
      return &(base.get(idx)->val); // return a pointer, you return an address of it.
    }

    bool remove (const TKey& key){
      int idx = locate(key);
      if (idx == -1) return false;

      delete base.get(idx);
      base.removeAt(idx);
      return true;
    }

    virtual ~Map(){
      for (int i = 0l i < base.count(); i ++){
        delete base.get(i);
      }
    }
  };


}
