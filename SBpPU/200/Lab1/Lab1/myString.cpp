#include <string>
#include "myString.h"
using namespace std;

// ��������� ��������� ���������� ���������� ������ �� ����������� (������ ��� �������� ��� ����������� ����������)?
// 
// ��� ����������� ������ ����� ������� ���������� �� ������ expression:
// 1) m_pStr = new char[strlen(pStr) + 1];
// 2) MyString::m_pStr = new char[strlen(pStr) + 1];
// 3) this->m_pStr = new char[strlen(pStr) + 1];
// ����� ���������� stylecode?


// ����������� ������������.
MyString::MyString(const char* pStr) {
	m_pStr = new char[strlen(pStr) + 1];
	memcpy(m_pStr, pStr, strlen(pStr) + 1);
}

MyString::MyString(const MyString& other) {
	m_pStr = new char[strlen(other.m_pStr) + 1];
	memcpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
}

// ����������� �����������.
MyString::~MyString() {
	delete [] m_pStr;
	m_pStr = nullptr;   
}

const char* MyString::GetString() {
	return (this->m_pStr);  // �������� ����� ������������ const_cast<const char*>???
}

const char* MyString::GetString()const {
	return (this->m_pStr);
}

void MyString::SetNewString(const char* newStr) {
	delete[] m_pStr;
	m_pStr = new char[strlen(newStr) + 1];
	memcpy(m_pStr, newStr, strlen(newStr) + 1);
}
