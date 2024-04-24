#pragma once
#include <iostream>
#include <cstring>
#include "Counter.h"


class MyString
{
	Counter* m_pMyCounter;
    char* m_str;
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& s);
//	MyString(MyString&& other);
//	MyString& operator=(MyString&& other);


    static void print();
    static void changeCase();
    const char* getString() const;
    static void sort();

};


std::ostream& operator<<(std::ostream& os, const MyString& str);
