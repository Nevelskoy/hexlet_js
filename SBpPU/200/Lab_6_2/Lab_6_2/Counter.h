#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

class Counter {
    Counter* pNext;
    static Counter* m_pHead;
    static size_t m_curCounters;  // ������� ���������� (������ ������)
    char* m_pStr;
    size_t m_nOwners;   // ������� ������������� ������ ������ 
public:
//    Counter();
    Counter(const char* str);
    ~Counter();

    const char* getStr() const;
    void addUser();
    void removeUser();
    //void removeOwner();

    static void changeCaseAll();
    static void sortAll();

    friend class MyString;
};

