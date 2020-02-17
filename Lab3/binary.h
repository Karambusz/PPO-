#ifndef binary_h
#define binary_h
#include "mystring.h"

typedef bool *Binary;

unsigned int ObtainBinary(MyString *str, Binary &binary);
void PrintBinary(Binary binary, unsigned int binlength);
void PrintBinary(MyString *str);


#endif
