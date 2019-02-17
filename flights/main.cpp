#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

class Date{
private:
  int day, month, year;

  int days_since_01011970() const {
    // exploits C function mktime ("man mktime for details")
    struct tm t; // stuct tm, containing a calendar date and time broken down into its components, are integer type
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    t.tm_sec = t.tm_min = t.tm_hour = 0;
    time_t t_seconds = mktime (&t); // time_t datatype is a typedef defined in the standard header.mktime(struct tm* timeptr), takes in a pointer.
    return ceil(t_seconds/86400.0); // ceil() returns the smallest possible integer value which is greater than or equal to the fiven argument.
  }
public:
  Date (int d, int m, int y){
    day = d;
    month = m;
    year = y;
  }

  // copy constructor --> always assgin attributes of another obj of the same calss to this new obj.
  Date (const Date &other) :
    day(other.day),
    month (other.month),
    year (other.year){

    }

  // making global operator for outputting dates to streams
  friend ostream& operator<< (ostream &out, const Date &d);

  // operator belonging to class for subtracting dates
  int operator-(const Date &other) const {
    return days_since_01011970() - other.days_since_01011970();
  }

  // friend int operator-(const Date &other, const Date &two);

  static Date today(){
    time_t rawtime;
    time (&rawtime);
    struct tm *t = localtime (&rawtime);
    assert(t);
    return Date (t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
  }
};

ostream& operator<<(ostream& out, const Date &d){
  out << d.day << "/" << d.month << "/" << d.year << '\n';
  return out;
}

class Passenger{
private:
  string name;
  string address;
public:
  Passenger(string n, string a) :
    name (n),
    address (a){

    }
};

class Flight{
private:
  int codeNumber;
  double price;
  Date takeoff;
public:
  Flight (Date d, int c, double p): // if we include Date class, it must be a compostion to class Flight
    takeoff (d),
    codeNumber (c),
    price (p){

  }

  Date getDate() const {
    return takeoff;
  }

  double getPrices () const {
    return price;
  }
};

class Booking{
protected:
  Flight* f;
  Passenger* p;
  string seat;

  virtual int days_before() = 0;
  virtual double cancel_amount() = 0;

public:
  Booking (Flight* _f, Passenger* _p, string _seat){
    f = _f;
    p = _p;
    seat = _seat;
  }

  bool cancel(){
    if (f->getDate() - Date::today() < days_before()){
      return false;
    double to_pay = cancel_amount();
    // do the paying
    return true;
    }
  }
};

class FlexibleBooking : public Booking {
private:
  double amount_paid;
  int days_before(){
    return 10;
  }

  double cancel_amount(){
    return 0.8*amount_paid;
  }
public:
  FlexibleBooking(Flight* f, Passenger* p, string s, int ap):
    Booking (f, p, s),
    amount_paid (ap) {

    }
};

class FirmBooking: public Booking{
private:
  int days_before(){
    return 20;
  }

  double cancel_amount(){
    return f->getPrices();
  }
public:
  FirmBooking (Flight* f, Passenger* p, string s) :
    Booking (f, p, s){

    }
};

int main(){
  Date xmas(25, 12 ,2017);

  cout << "today is " << Date::today() << endl; // today() is a static method
  // exmas.operator-(Date::today())
  cout << "day to xmas = " << xmas - Date::today() << endl;

  Passenger alice ("Alice," "Queen's Tower", "SW7 2AZ");
  Passenger bob ("Bob, ", "Huxuley Building, SW7 2RH");

  Flight ba249 (Date (19, 11, 2017), 249, 399);
  cout << "flight is on " << ba249.getDate() << endl;
  cout << "day before = " << ba249.getDate() - Date::today() << '\n';

  FlexibleBooking mybooking(&ba249, &alice, "1A", 100);
  FirmBooking yourbooking (&ba249, &bob, "16F");

  if (mybooking.cancel()){
    cout << "Flexible booking cancelled! " << endl;
  } else{
    cout << "Flexible booking could not be cancelled! " << endl;
  }

  if (yourbooking.cancel()){
    cout << "Firm Booking cancelled! " << endl;
  } else{
    cout << "Firm Booking could not be cancelled!" << '\n';
  }

  return 0;
}
