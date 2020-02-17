#ifndef mystring_h
#define mystring_h
struct MyString{
    const char *str;
    int length;
};




MyString *CreateString(const char *name);
void PrintMyString(MyString *wsk);
void ClearStrings();

#endif