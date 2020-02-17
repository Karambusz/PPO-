#ifndef cipher_h
#define cipher_h
#include "mystring.h"
#include "binary.h"
#include "xor.h"

char* Encode(MyString* str, MyString* passwd);
char* Decode(MyString* str, MyString* passwd);
#endif
