#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cctype>

using namespace std;

#ifndef workingPointer
#define workingPointer

extern int cash;

void lecture2();
void lecture3();
void lecture4();
void lecture5(int* p);
void lecture6();
int lecture7(int A[]);
void lecture8(char* C);
void lecture9 (const char* C);
void lecture10_1();
void lecture10_2(int (*C)[2][2], int sizeofC_1st, int sizeofC_2nd, int sizeofC_3rd);

void lecture11();
int lecture12_1(int* a, int* b);
int* lecture12_2(int* a , int* b);
int lecture13_1(int a, int b);
void lecture13_2();
void lecture13_3(char* name);

void lecture14_1();
void lecture14_2(void (*ptroflecture14_1)());
void lecture14_3(int* intArray, int sizeofArray);

void lecutre14_3(int* intArray, int sizeofArray, int (*ptrofcompare)(int,int));
int lecture14_4_compare(int integer1, int integer2);
int lecture14_5_absolute_compare(int integer1, int integer2);
int lecture_14_6_generic_compare (const void* a, const void* b);
void lecture_15(int bet);

#endif
