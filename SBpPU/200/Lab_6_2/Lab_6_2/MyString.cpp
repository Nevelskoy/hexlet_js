#include "MyString.h"



MyString::~MyString() {
    m_pMyCounter->removeUser();
}


MyString::MyString() : m_str(nullptr) {}


MyString::MyString(const char* str) {
    Counter* temp = Counter::m_pHead;
    while (temp) {
        if (strcmp(temp->m_pStr, str) == 0) {
            m_pMyCounter = temp;
            m_pMyCounter->addUser();
            return;
        }
        temp = temp->pNext;
    }
    m_pMyCounter = new Counter(str);
}


//MyString::MyString(const MyString& other) {
//    if (other.m_pMyCounter) {
//        m_pMyCounter = other.m_pMyCounter;
//        m_pMyCounter->addUser();
//    }
//    else {
//        m_pMyCounter = nullptr;
//    }
//}


MyString::MyString(const MyString& other) {
	m_pMyCounter = other.m_pMyCounter;
	if (m_pMyCounter) {
	
		m_pMyCounter->addUser();
	}
}

//MyString::MyString(MyString&& other) {
//	m_pMyCounter = other.m_pMyCounter;
//	//m_pMyCounter->pNext = other.m_pMyCounter->pNext;
//	other.m_pMyCounter = nullptr;
//}
//
//
//MyString& MyString::operator=(MyString&& other) {
//	if (m_pMyCounter != other.m_pMyCounter) {
//		
//		m_pMyCounter = other.m_pMyCounter;
//		//m_pMyCounter->pNext = other.m_pMyCounter->pNext;
//		other.m_pMyCounter = nullptr;
//	}
//	return *this;
//}


MyString& MyString::operator=(const MyString& s) {
    if (this == &s) {
        return *this;
    }
    if (m_pMyCounter) {
        m_pMyCounter->removeUser();
        //if (m_pMyCounter->m_nOwners == 0) {
        //    delete m_pMyCounter;
        //}
    }
    m_pMyCounter = s.m_pMyCounter;
    if (m_pMyCounter) {
        m_pMyCounter->addUser();
    }
    return *this;
}


void MyString::print() {
    Counter* p = Counter::m_pHead;
    for (size_t i = 0; i < Counter::m_curCounters; i++) {
        std::cout <<"owners: "<< p->m_nOwners << ' ' << p->m_pStr << std::endl;
        p = p->pNext;
    }
    std::cout << std::endl;
}


void MyString::changeCase() {
    Counter::changeCaseAll();
}


void  MyString::sort() {
    Counter::sortAll();
}


const char* MyString::getString() const {
    if (m_pMyCounter->m_pStr){
        return m_pMyCounter->m_pStr;
    }
}


std::ostream& operator<<(std::ostream& os, const MyString& str) {
	if (str.getString()) {
		os <</* "contents:  \"" <<*/ str.getString()/*<< "\""*/;
	}
	return os;
}




/////////////////////////////////////
