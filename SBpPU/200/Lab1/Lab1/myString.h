#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:
    MyString(const char* pStr);
    MyString(const MyString & other);
    
    ~MyString();

    const char* GetString();
    const char* GetString() const;

    void SetNewString(const char* newStr);
};
