#include "workingPointer.h"

int cash = 100; // for Casino

void lecture2(){
  int a;
  int *p;
  p = &a; // &a = address of a
  printf("%d\n",p);
  printf("%d\n",*p); // *p - value, at address pointed by p

  int b = 10;
  int *q;
  q = &b;
  cout << "<<<<<<<<<<<<<<<<<<<<<< Define and Declare a pointer <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "int *q = &b; is the right way to define a pinter pointing to an integer, we have to assign it with an address of an integer." << " b = 10; so *q is --> " << *q << '\n';

  cout << "q = --> " << q << '\n';

  cout << "change the value of b by changing the pointer pointing to b" << '\n';
  *q = 20;
  cout << "*q = 20;, now print out the value of b, which is --> " << b << '\n';

  cout << "try to print out \'q\', which is an address --> " << q << '\n';

  cout << "the q + 1 is --> " << q +1 << "as q points to an integer, an integer has 4 bytes" <<'\n';

  cout << "size of an int type is by sizeof(int) --> " << sizeof(int) << '\n';
  cout << '\n';

}

void lecture3(){
  int a = 1025;
  int *p;
  p = &a;
  cout << "<<<<<<<<<<<<<<<<<<<<<< Pointer Arithematic <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "size of a char  is sizeof(char) --> " << sizeof(char) << '\n';
  cout << "the address of p is = " << p << ", the value stored in that address is = " << *p << '\n';
  cout << "the address of p+1 is = " << p+1 << ", the value stored in that new address is = " << *(p+1) << '\n';

  char *p0;
  p0 = (char*)p; // typecasting
  cout << "the original pointer q is pointing to an integer, so assign it to a pointer pointing to a char, we do the typecasting (char*), so p0 = (char*)p --> " << *p0 << '\n';
  cout << "the address of p0 is = " << p0 << ", the value stored in that address is = " << *p0 << '\n';
  cout << "the address of p0+1 is = " << p0+1 << ", the value stored in that new address is = " << *(p0+1) << '\n';

  cout << "<<<<<<<<<<<<<<<<<<<<<< Void Pointer  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  // Void pointer
  void *q;
  q = p; // can only give address but cannot be dereferenced
  cout << "the address of a void pointer q is = " << q << ", though we have assigned it with a value which is pointed by a valid pointer pointing to an integer. The value pointed by this void pointer q = " << " --> give back error, the \'void*\' is not a pointer-to-object type" << '\n';
  cout << '\n';
}

void lecture4(){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Pointer to Pointer  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int x = 5;
  int* p = &x;
  *p = 6;
  int** q = &p;
  int*** r = &q;

  cout << "*p --> " << *p << '\n';
  cout << "*q --> " << *q << "the address of p."<< " And the *(*q) is --> " << *(*q) << '\n';
  cout << "*r --> " << *r << "the address of q. "<< "And the *(*r), gives the address of pointer p,  --> " << *(*r) << ". And the *(*(*r)) gives the actual value pointed to by the pointer p --> "<< *(*(*r)) << '\n';

  ***r = 10;
  printf("%d\n", x);
  **q = *p + 2;
  printf("%d\n", x);
}

void lecture5(int* p){ // pass by reference, a variables' address
  cout << "<<<<<<<<<<<<<<<<<<<<<< pass by reference  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  *p = (*p) + 1;
  cout << "The value of p right now is " << *p << '\n';
  cout << '\n';
}

void lecture6(){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Pointers and Arrays  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int A[] = {2, 3, 4, 5, 6};

  for (int index = 0; index < sizeof(A)/sizeof(A[0]); index ++ ){
    cout << "Method 1: the address of each element stored to is &A[index]--> " << &A[index] << '\n';
    cout << "Method 2: the address of each element stored to is (A+index)--> " << A+index << '\n';
  }

  for (int index = 0; index < sizeof(A)/sizeof(A[0]); index ++){
    cout << "the every element in sequence is --> " <<
    *(A+index) << '\n';
  }
  cout << '\n';
}

int lecture7(int A[]){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Pass Arrays as function arguments  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int sum = 0;
  int sizeofA = sizeof(A)/sizeof(A[0]);
  cout << "inside of lecture7(), the sizeof(A) is --> " << sizeof(A) << "This is because the array is not passed by value, it is passed by reference, literally, the first element address of the int array A is passed, which gives the length of that address, 8 or 4 sometimes."  <<'\n';

  for (int index = 0; index < sizeofA; index ++){
    sum += *(A + index);
  }
  cout << "The size of an array passed into a function is caluculated differentlly than a local calculation of the size of the array, we'd better pass the size of the array along with the array into a function if the function has any execution to do with the size of the passed array." << '\n';

  cout << '\n';
  return sum;
}

void lecture8(char* C){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Char Array passed in as a parameter  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int index = 0;
  while (*C != '\n'){
    printf("The element of %ith is %c \n",index, *C);
    C ++;
  }
  printf("\n");
  cout << '\n';
}

void lecture9 (const char* C){
  cout << "<<<<<<<<<<<<<<<<<<<<<< a const Char array is passed into a function  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  char* extra = "EY and UCL";
  cout << "C = strcat (C, extra); --> gives error as the passed in parameter are not allowed to be modified, its realy only by the modifier \'const\'" << '\n';
  // C = strcat (C, extra);

  int index = 0;
  while (*(C+index) != '\0'){
    cout << "the " << index << "th char of this string is --> " << *(C+index) << '\n';
    index ++;
  }
  cout << '/n';
}

void lecture10_1(){
  cout << "<<<<<<<<<<<<<<<<<<<<<< basic 3 dimensional int array by pointer.  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int C[3][2][2] = {{{2,5}, {7,9}},
                    {{3,4}, {6,1}},
                    {{0,8},{11,13}}};
  printf("%d %d %d %d", C, *C, C[0], &C[0][0]);
  cout << '\n';
}

// the function takes in a 3-dimensional Array
void lecture10_2(int (*C)[2][2], int sizeofC_1st, int sizeofC_2nd, int sizeofC_3rd){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Pass 3-D Arrays as function arguments  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << "To call this 3 dimensiaonal array, we have to speficy what the exact dimension of this pointer pointing to --> so we have [2][2] in place as a part of arguments " << '\n';

  for (int index_1 = 0; index_1 < sizeofC_1st; index_1 ++){
    for (int index_2 = 0; index_2 < sizeofC_2nd; index_2 ++){
      for (int index_3 = 0; index_3 < sizeofC_3rd; index_3 ++){
        cout << "the element is: --> " << *(*(*(C+index_1) + index_2) + index_3) << '\n';
      }
    }
  }
  cout << '\n';
}

void lecture11(){
  cout << "<<<<<<<<<<<<<<<<<<<<<< dynamic programming in heap using heap <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int *p;
  p = new int;
  *p = 10;
  delete p;
  p = new int[20];
  delete [] p;

  cout << "the *p is --> " << *p << '\n';
}

int lecture12_1(int* a, int* b){
  cout << "<<<<<<<<<<<<<<<<<<<<<< dynamic programming in heap using heap part 1: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int c = *a + *b;
  cout << '\n';
  return c;
}

int* lecture12_2(int* a, int* b){
  cout << "<<<<<<<<<<<<<<<<<<<<<< dynamic programming in heap using heap part 2: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  int *c = (int*)malloc(sizeof(int));
  cout << "int *c = (int*)malloc(sizeof(int)); is dynamic programming, the malloc(sizeof(int)) gives a void pointer pointing to somewhere big enough to store an int, And this place is not within stack but in heap though." << '\n';
  *c = *a + *b;
  cout << '\n';
  return c; // we return an address as this is essential to define a pointer.
}

int lecture13_1(int a, int b){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Function pointer (a pointer pointing to a function -- part 1) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  cout << '\n';
  return a+b;
}

void lecture13_2(){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Function pointer (a pointer pointing to a function -- part 2) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  printf("Hello there \n");
  cout << '\n';
}

void lecture13_3(char* name){
  cout << "<<<<<<<<<<<<<<<<<<<<<< Function pointer (a pointer pointing to a function -- part 3) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  printf("Hello there %s \n", name);
  cout << '\n';
}

// lecture 14 function pointers can be passed as arguments to functions --> a function will receive a function pointer as an argument --> to call back the function where this pointer points to
void lecture14_1(){
  printf("hello from lecture14_1() function.\n");
}

void lecture14_2(void (*ptroflecture14_1)()){// function pointer as arguments
  ptroflecture14_1(); // call back function that ptro points to.
}

// bubble sort without any flag input
void lecture14_3(int* intArray, int sizeofArray){ // bubble sort
  int i, j, temp;
  for (i = 0; i < sizeofArray; i ++){
    for (j = 0; j < sizeofArray-1; j ++){
      if (intArray[j] > intArray[j+1]){
        temp = intArray[j];
        intArray[j] = intArray[j+1];
        intArray[j+1] = temp;
      }
    }
  }
}

// bubble sort with a function pointer input to realise contorl of the sort to an increasing order or decreasing order.
void lecutre14_3(int* intArray, int sizeofArray, int (*ptrofcompare)(int,int)){
  for (int outIndex = 0; outIndex < sizeofArray; outIndex ++){
    for (int inIndex = 0; inIndex < sizeofArray - 1; inIndex ++){
      if (ptrofcompare(*(intArray+inIndex), *(intArray+inIndex+1))){ //ascending order
        int temp = *(intArray+inIndex);
        *(intArray+inIndex) = *(intArray +inIndex +1);
        *(intArray + inIndex +1) = temp;
      }
    }
  }
}

int lecture14_4_compare(int integer1, int integer2){
  if (integer1 > integer2){
    return 1;
  }else if (integer1 < integer2){
    return -1;
  }else{
    return 0;
  }
}

int lecture14_5_absolute_compare(int integer1, int integer2){
  int absint1 = integer1;
  int absint2 = integer2;
  if (integer1 < 0){
    absint1 = 0 - integer1;
  } else if (integer2 < 0){
    absint2 = 0 - integer2;
  }

  if (absint1 > absint2){
    return 1;
  } else if (absint1 < absint2){
    return -1;
  } else {
    return 0;
  }
}

int lecture_14_6_generic_compare (const void* a, const void* b){
  int A = *((int*)a); // type casting a void pointer to an integer pointer and get access its value by putting an * in front of the bracket.
  int B = *((int*)b);
  return A-B;
}

void lecture_15(int bet){
  char *C = (char*) malloc(100*sizeof(int));
  *C = 'J';
  *(C+1) = 'Q';
  *(C+2) = 'K';

  cout << "shuffling ...... " << '\n';
  srand(time(NULL));
  for (int index  = 1; index < 5; index ++){
    int x = rand() % 3;
    int y = rand() % 3;
    int temp = C[x];
    *(C + x) = *(C + y);
    *(C + y) = temp;
  }
  int playerGuess;
  cout << "Whats the position of Queen? - 1, 2 or 3?" << '\n';
  // must put & in front of the variable used in scanf().
  cout << "must put & in front of the variable used in scanf()." << " because all arguments in C are passed by value, so we need to pass a pointer if we want a fucntion to be able to change a parameter." << '\n';
  scanf ("%d", &playerGuess);
 if (*(C + playerGuess - 1) == 'Q'){
 cash += 3*bet;
 cout << "You win! Result = " << *C << *(C+1) << *(C+2) << '\n';
 cout << "You currently have £" << cash << '\n';
} else {
  cash -= bet;
  cout << "You lose! Result = " << *C << *(C+1) << *(C+2) << '\n';
  cout << "You currently have £" << cash << '\n';
}
  free(C);
}
