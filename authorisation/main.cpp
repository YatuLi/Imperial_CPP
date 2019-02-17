#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class User;
class Authorisation;

class Workstation{
private:
  string hostname;
  list <Authorisation*> authorisation;
public:
  Workstation(string h):
    hostname(h){

    }

    void add_authorisation(Authorisation *auth){
      authorisation.push_back(auth);
    }

    Authorisation* get_authorisation (User* target){
      for (auto iterator = authorisation.begin(); iterator != authorisation.end(); iterator ++){
        if ((*iterator)->matches_user(target))
          return *iterator;
      }
      return NULL;
    }

    string get_hostname() const {
      return hostname;
    }
};

class User{
private:
  string name;
public:
  User(string n): name(n){ //private member are put into member initialiser

  }

  bool login(Workstation &w){
    // call a public function defined in a different class.--> a public function is free to be called where it is not within the class it gets defined.
    Authorisation* auth = w.get_authorisation(this);
    // return an obj of Authorisation to see if the login gets through or not.
    cout << "Login of User '" << name << "' into " << w.get_hostname() << " ";
    if (auth == NULL){
      cout << "failed due to lack of authorisation. " << endl;
      return false;
    }
    cout << "succeed!" << endl;
    return true;
  }
};

class StartSession{
private:
  string root;
public:
  StartSession (string r) :
    root (r){

    }
  // copy constructor
  StartSession(const StartSession &other):
    root (other.root){

  }
};

class Directory {
private:
  string name;
  Directory *parent; // if this obj might be contained in another obj of the same class, we use a pointer not a run time obj
public:
  Directory (string _name, Directory *p) :
  name (_name),
  parent(p){

  }
};

// 3 association relationship: User, Workstation and Directory
class Authorisation{
private:
  int priority;
  User* user; // one parties of association
  Workstation* workstation; // the other part of association
  StartSession start; // composition
  Directory* default_directory; // assocation
public:
  Authorisation(User *u, Workstation *w, int p, const StartSession &s, Directory *def): // number of parameters of const is 5 VS no of private members.
    priority (p),
    user (u),
    workstation(w),
    start(s),
    default_directory(def){
      w->add_authorisation(this);
    }

    bool matches_user(User* target){
      return user == target;
    }
};

int main(){

  User will("will");
  Workstation beast ("beast");
  Workstation mi5 ("mi5");

  StartSession sess("/bin/sh");
  Directory root ("/", NULL);
  Directory homes ("/homes", &root); // as long as it's an address, clear to go ahead to fit it into the place where the parameter is asked to be a pointer type.
  Directory def ("/homes/wjk", &homes);

  Authorisation auth (&will, &beast, 10, sess, &def);

  will.login(mi5);
  will.login(beast);

  return 0;
}
