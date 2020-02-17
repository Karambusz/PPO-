#include <iostream>
#include "mystring.h"
#define max 5
using namespace std;

const int dlugosc = 13;
MyString **tab = new MyString *[max];
int number_of_strings = 0;

MyString *CreateString(const char *name)
{

    MyString *string = new MyString;
    if (name == NULL)
    {
        cout << "CreateString: NULL pointer passed. No object created." << endl;
        delete string;
        return NULL;
    }
    else
    {
        int licznik = 0;
        do
        {
            licznik++;
        } while (name[licznik] != '\0');
        if (licznik > 13)
        {
            cout << "CreateString: String is too long." << endl;
            delete string;
            return NULL;
        }
        else
        {
            if (number_of_strings >= max)
            {
                cout << "CreateString: Maximum no of strings has been reached." << endl;
                delete string;
                return NULL;
            }
            else
            {
                string->length = licznik + 1;
                string->str = name;
                tab[number_of_strings] = string;
                number_of_strings++;
                return string;
            }
        }
    }
}

void PrintMyString(MyString *wsk)
{
    if (wsk)
    {
        cout << wsk->str << endl;
    }
    else
    {
        cout << "PrintMyString: NULL pointer passed." << endl;
    }
}

void ClearStrings()
{
    for (int i = 0; i < number_of_strings; i++)
    {
        delete tab[i];
    }
    delete[] tab;
}