#include "workingPointer.h"

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



int main(){

  lecture2();
  lecture3();
  lecture4();

  int p = 100;
  lecture5(&p); // & is an operator to give us the address of some variable.

  lecture6();

  int A[] = {1,2,3,4,5,6};
  cout << "The sum of all elements in A[] is -->" << lecture7(A) << '\n';
  cout << "in main(), the sizeof(A) is --> " << sizeof(A) << '\n';

  char* C = "RogerYatuLi";
  char C_1 [512] = "RogerYatuLi";
  lecture8(C);

  lecture9(C_1);
  lecture10_1();

  // 3-dimensional array
  int C_2[3][2][2] = {{{2,5}, {7,9}},
                    {{3,4}, {6,1}},
                    {{0,8},{11,13}}};
  int sizeofC_1st = sizeof(C_2)/sizeof(C_2[0]);
  int sizeofC_2nd = sizeof(C_2[0])/sizeof(C_2[0][0]);
  int sizeofC_3rd = sizeof(C_2[0][0])/sizeof(C_2[0][0][0]);
  lecture10_2(C_2, sizeofC_1st, sizeofC_2nd, sizeofC_3rd);

  lecture11();

  int a = 10;
  int b = 15;
  int c = lecture12_1(&a, &b);
  cout << "the function \'int lecture12_1(&a, &b);\' returns an int and takes in 2 pointer variables, and the int c is : --> " << c << '\n';

  int* cp;
  cp = lecture12_2(&a, &b);
  cout << "the function \' int* lecture12_2(int* a, int* b) \' returns a pointer. In turn, it literally returns an address of some value where the sum is stored in that address." << '\n';
  cout << "the value of *cp is cp = lecture12_2(&a, &b) --> " << *cp << '\n';


  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Lecture 13 Function Pointers Basic <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< This is for int lecture13_1(int a, int b) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  // delcare a pointer of a funtion.
  int (*ptroffuntion)(int, int);
  // initialise a pointer of a function
  ptroffuntion = &lecture13_1; // or just function name is good enough though.
  int holder;
  // execute the function and pass its output to somewhere.
  holder = (*ptroffuntion)(2,3); // or ptroffuntion(2,3) could also works
  cout << "the value of the holder is --> " << holder << " the value of the ptroffuntion is --> " << *ptroffuntion << '\n';

  cout << '\n';
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< This is for void lecture13_2() <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  void (*ptroffuntion_1)();
  ptroffuntion_1 = lecture13_2;
  ptroffuntion_1();
  cout << "for a void function, simply removing the holder along with = and call the pointer to the function followed by a (), which has whatever the inputs are." << '\n';

  cout << '\n';
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< This is for void lecture13_3(char* name) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  void (*ptroffuntion_3)(char*);
  ptroffuntion_3 = &lecture13_3;
  ptroffuntion_3("Yatu");

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Lecture 14 Function Pointers <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< This is for Lecture 14, function pointers and call backs <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << '\n';
  void (*ptroflecture14_1)() = &lecture14_1;
  cout << "the First way to call the function lecture14_2(void (*ptroflecture14_1)()) is to put the argument as the pointer which has been assigned with the address of the function, sth like --> \'lecture14_2(ptroflecture14_1);\' --> " << '\n'; lecture14_2(ptroflecture14_1);

  cout << "the Second way to call the function lecture14_2(void (*ptroflecture14_1)()) is to put the argument as the function name straightaway, sth like --> \'lecture14_2(lecture14_1);\' --> " << '\n';
  lecture14_2(lecture14_1);
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< As a rule, bubble sort an integer array. <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int i, intArray_1 [] = {1,2,3845,4,3,97};
  lecture14_3(intArray_1, 6);
  for (i = 0; i < 6; i ++){
    cout << "the " << i << "th element is " << *(intArray_1 + i) << " -->This is a normaly bubble sort function called." <<'\n';
  }
  cout << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< In particular, bubble sort with a pointer function input. <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int (*ptroflecture14_4_compare)(int, int);
  ptroflecture14_4_compare = lecture14_4_compare;
  lecutre14_3(intArray_1,6, ptroflecture14_4_compare);
  for (i = 0; i < 6; i ++){
    cout << "the " << i << "th element is " << *(intArray_1 + i) << " -->lecture14_3(int*, int, int (*p)(int,int)) is called." <<'\n';
  }
  cout << '\n';

  // TODO: as the pointer passed into this function is not deleted, so the following assignment of a new pointer of function cannot be successfully passed into the function void lecture14_3(int*, int, int (*p)(int, int)) 13/01/2019

  int intArray_2 [] = {1,2,-3845,4,-3,97};
  // int (*ptroflecture14_5_abscompare)(int, int);
  // ptroflecture14_5_abscompare = &lecture14_5_absolute_compare;
  // lecture14_3(intArray_2, 6, lecture14_5_absolute_compare);
  // for (i = 0; i < 6; i ++){
  //   cout << "the " << i << "th element is " << *(intArray_2 + i) << " -->lecture14_3(int*, int, int (*p)(int,int)) is called." <<'\n';
  // }

  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Using void pointer as a function parameter type to be passed into a built-in quick sort function. <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int (*ptroflecture_14_6_generic_compare)(const void*, const void*);
  ptroflecture_14_6_generic_compare = &lecture_14_6_generic_compare;

  qsort (intArray_2, 6, sizeof(int), ptroflecture_14_6_generic_compare);
  for (i = 0; i < 6; i ++){
    cout << "the " << i << "th element is " << *(intArray_2 + i) << " --> qsort(int*, int, int (*p)(void*, void*)) is called." <<'\n';
  }
  cout << '\n';

  int intArray_3 [] = {1,2,-909,4,-3323,97323};
  // int (*ptroflecture_14_6_generic_compare)(const void*, const void*);
  ptroflecture_14_6_generic_compare = &lecture_14_6_generic_compare;

  // TODO: as the pointer passed into this function is not deleted, so the following assignment of a new pointer of function cannot be successfully passed into the function void lecture14_3(int*, int, int (*p)(int, int)) 13/01/2019

  // qsort(intArray_3,6, ptroflecture_14_6_generic_compare);
  // for (i = 0; i < 6; i ++){
  //   cout << "the " << i << "th element is " << *(intArray_3 + i) << " --> qsort(int*, int, int (*p)(void*, void*)) is called." <<'\n';
  // }
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Memory Leakage <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "Welcome to the virtual Casino" << '\n';
  int bet;

  cout << "You current cash is " << cash << '\n';
  while (cash > 0){
    cout << "whats your bet? £" << '\n';
    cin >> bet;
    if (bet == 0 || bet > cash) break;
    lecture_15(bet);
    printf ("\n ********************\n");
  }


  return 0;
}
