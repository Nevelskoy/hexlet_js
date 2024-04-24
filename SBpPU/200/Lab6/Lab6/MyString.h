#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdarg>
#include <string>
#include <ctype.h>
#include "Counter.h"


class MyString
{
	Counter* m_pMyCounter;
public:
    MyString();
    ~MyString();
    MyString(const MyString&);
	MyString(const char*);

 /*   MyString(const char* pStr);
    MyString(const MyString& other);
    MyString(MyString&& other);
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(const char* str);
    MyString& operator=(MyString&& other);


    bool operator==(const char*) const;
    bool operator==(char*) const;

    const char* GetString() const;
*/
   
    //friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};


