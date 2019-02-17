#include <iostream>

using namespace std;

class Course{
  const int code;
  const char* const name;

public:
  Course (int code, cosnt char* name)
    code (code),
    name (name){}

  int getCode() const {
    return code;
  }

  const char* getName() const {
    return name;
  }
};

ostream& operator<< (ostream& o, const Course& c){
  return o << "Course " << c.getCode() << ": " << c.getName();
}

class Textbook{
  const int id;
  const char* const title;

public:
  Textbook (int id, const char* title):
    id (id),
    title (title){}

  int getId () const {
    return id;
  }

  const char* getTitle() const {
    return title;
  }
};

// just simply pass in an obj, id and title would be returned without specifically calling them.
ostream& operator<< (ostream& o, const Textbook& tb){
  return o << "Textbook " << tb.getId() << ": " << tb.getTitle();
}

int courseComparer (const Course* const& a, const Course* const& b){
  return a->getCode() - b->getCode();
}


int main(){
  Course* oo = new Course (517, "OO Design & Prog");
  Course* cs = new Course (515, "Computer System");
  Course* lg = new Course (518, "Logic");

  Textbook* ps = new Textbook (11, "Problem Sovling w/C++");
  Textbook* ca = new Textbook (33, "Computer Architecture");
  Textbook* mc = new Textbook (55, "Modern C++");

  Map < const Course*, Textbook*, courseComparer> ctm; // LookUpTable.cpp defines Map, which is

  ctm.insert (oo, ps);
  ctm.insert (cs, ca);

  Textbook** result = ctm.get(oo);
  cout << "[ " << result << "]" << **result << endl;

  result = ctm.get(cs);
  cout << "[ " << result << "] " << **result << endl;

  result = ctm.get(lg);
  cout << "[ "<< result << "] " << **result << endl;

  ctm.insert(oo, mc);
  result = ctm.get (oo);
  cout << "[ " << result << "] " << **result << endl;

  bool success = ctm.remove(lg);
  cout << success ? "true" : "false" << endl;

  success = ctm.remove (cs);
  cout << success ? "true" : "false" << endl;

  result = ctm.get(cs);
  cout << "[ " << result << "] " << endl;

  delete oo;
  delete cs;
  delete lg;
  delete ps;
  delete ca;
  delete mc;

  return 0;
}
