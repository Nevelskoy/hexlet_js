#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdarg>
#include <string>
#include <ctype.h>

class MyString
{
	char* m_pStr;
public:
    MyString();
    MyString(const char* pStr);
    MyString(const MyString& other);
    MyString(MyString&& other);

	~MyString();

    MyString& operator=(const MyString& other);
	MyString& operator=(const char* str);
	MyString& operator=(MyString&& other);

    MyString operator+(const MyString& other) const;
    MyString& operator+=(MyString& other);
	MyString operator--(int);
	MyString& operator++();
     

	const char* GetString() const;
    
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

MyString bindStrs_2(const char* str1, ...);

std::ostream& operator<<(std::ostream& os, const MyString& str);

