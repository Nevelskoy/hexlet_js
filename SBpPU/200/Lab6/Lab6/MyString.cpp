#include "MyString.h"


MyString::~MyString() {
	delete m_pMyCounter;
}

MyString::MyString() {
	m_pMyCounter = new Counter();
}

MyString::MyString(const char* ch) {
	m_pMyCounter = Counter::add(ch);
}

MyString::MyString(const MyString& other) {
	if (other.m_pMyCounter == nullptr) {
		m_pMyCounter = nullptr;
		return;
	}
	m_pMyCounter = new Counter();
	m_pMyCounter->m_pStr = new char[strlen(other.m_pMyCounter->m_pStr) + 1];
	strcpy(m_pMyCounter->m_pStr, other.m_pMyCounter->m_pStr);
}

//
//MyString::MyString(const char* pStr) {
//	m_pStr = new char[strlen(pStr) + 1];
//	memcpy(m_pStr, pStr, strlen(pStr) + 1);
//}
//
//MyString::MyString(const MyString& other) {
//	if (other.m_pStr) {
//		m_pStr = new char[strlen(other.m_pStr) + 1];
//		memcpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
//	}
//	else m_pStr = nullptr;
//}
//
//MyString::MyString(MyString&& other)//Move
//{
//	this->m_pStr = other.m_pStr;
//	other.m_pStr = nullptr;
//}
//
//MyString::~MyString() {
//	delete[] m_pStr;
//	m_pStr = nullptr;
//}
//
//const char* MyString::GetString(void) const {
//	if (m_pStr) {
//		return m_pStr;
//	}
//	else std::cout << "nullptr";
//};
//
//
//MyString& MyString::operator=(const MyString& other) {
//	if (other.m_pStr) {
//		if (this != &other) {  // компилятор адреса умеет сравнивать сам, а если (*this!=other), то придётся дополнительно перегрузить оператор "!="
//			delete[] m_pStr;
//			this->m_pStr = new char[strlen(other.m_pStr) + 1];
//			memcpy(this->m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
//		}
//		return *this;
//	}
//	else {
//		std::cout << "NULL exeption!!!" << std::endl;
//	}
//}
//
//MyString& MyString::operator=(const char* str) {
//	delete[] m_pStr;
//	this->m_pStr = new char[strlen(str) + 1];
//	memcpy(this->m_pStr, str, strlen(str) + 1);
//	return *this;
//}
//
//MyString& MyString::operator=(MyString&& str) {
//	//if (this != &other)
//	delete[] m_pStr;
//	this->m_pStr = str.m_pStr;
//	str.m_pStr = nullptr;
//	return *this;
//};
//
//
//std::ostream& operator<<(std::ostream& os, const MyString& str) {
//	os << "contents: " << str.m_pStr;
//	return os;
//}
//
//bool MyString::operator==(const char* c) const {
//	if (strlen(c) != strlen(m_pStr)) {
//		return false;
//	}
//	for (size_t i = 0; i < strlen(c); i++) {
//		if (m_pStr[i] != c[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool MyString::operator==(char* c) const {
//	return (m_pStr == c);
//}
