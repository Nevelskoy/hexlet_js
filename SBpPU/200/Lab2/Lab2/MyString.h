#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdarg>
#include <string>

class MyString
{
	char* m_pStr;
public:
    MyString(const char* pStr="");
    MyString(const MyString& other);

    ~MyString();

    const char* GetString();

};


//MyString bindStrs(const char* strs="", ...);

MyString bindStrs_2(const char* str1, ...);