#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>

using namespace std;

#ifndef Book_H
#define Book_H
extern int counter;

class Book{
  char* title;
  static int counter;
  int serialNumber;
public:
  Book (char*);
  ~Book();
  static void printNumberBooks();
};


#endif
