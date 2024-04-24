#include "MyString.h"


// Определение конструктора.
MyString::MyString() {
	m_pStr = nullptr;
}

MyString::MyString(const char* pStr) {
	m_pStr = new char[strlen(pStr) + 1];
	memcpy(m_pStr, pStr, strlen(pStr) + 1);
}

MyString::MyString(const MyString& other) {
	if (other.m_pStr) {
		m_pStr = new char[strlen(other.m_pStr) + 1];
		memcpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
	}
	else m_pStr = nullptr;
}

MyString::MyString(MyString&& other)//Move
{
	this->m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}

// Определение деструктора.
MyString::~MyString() {
	delete[] m_pStr;
	m_pStr = nullptr;
}

const char* MyString::GetString(void) const {
	if (m_pStr) {
		return m_pStr;
	}
	else std::cout << "nullptr";
};

MyString bindStrs_2(const char* str, ...) {
	const char** PptrStr = &str;
	int sizeStrs = 0;

	while (*PptrStr) {
		sizeStrs += strlen(*PptrStr);
		PptrStr++;
	}

	char* temp = new char[sizeStrs + 1];
	temp[0] = '\0';
	PptrStr = &str;
	while (*PptrStr) {
		strcat(temp, *PptrStr);
		PptrStr++;
	}

	MyString my(temp);
	return my;
}

/////////////////////////////////////////////////////////////////

MyString& MyString::operator=(const MyString& other) {
	if (other.m_pStr) {
		if (this != &other) {  // компилятор адреса умеет сравнивать сам, а если (*this!=other), то придётся дополнительно перегрузить оператор "!="
			delete[] m_pStr;
			this->m_pStr = new char[strlen(other.m_pStr) + 1];
			memcpy(this->m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
		}
		return *this;
	} else {
		std::cout << "NULL exeption!!!" << std::endl;
	} 
}

MyString& MyString::operator=(const char* str) {
	delete[] m_pStr;
	this->m_pStr = new char[strlen(str) + 1];
	memcpy(this->m_pStr, str, strlen(str) + 1);
	return *this;
}

MyString& MyString::operator=(MyString&& str) {
	//if (this != &other)
	delete[] m_pStr;
	this->m_pStr = str.m_pStr;
	str.m_pStr = nullptr;
	return *this;
};


std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << "contents: " << str.m_pStr;
	return os;
}

MyString MyString::operator+(const MyString& other) const {
	char* temp = new char[strlen(other.m_pStr) + strlen(m_pStr) + 1];
	temp[0] = '\0';
	strcat(temp, m_pStr);
	strcat(temp, other.m_pStr);
	MyString res(temp);
	delete[] temp;
	return res;
}

MyString& MyString::operator+=(MyString& other) {
	char* temp = new char[strlen(other.m_pStr) + strlen(m_pStr) + 1];
	temp[0] = '\0';
	strcat(temp, m_pStr);
	strcat(temp, other.m_pStr);
	delete m_pStr;
	this->m_pStr = temp;
	return *this;
}

MyString MyString::operator--(int) {
	MyString temp(*this);
	if (this->m_pStr) {
		for (int i = 0; i < strlen(this->m_pStr); i++) {
			this->m_pStr[i] = tolower(this->m_pStr[i]);
		}
		return temp;
	}
}

MyString& MyString::operator++() {
	if (this->m_pStr) {
		for (int i = 0; i < strlen(this->m_pStr); i++) {
			this->m_pStr[i] = toupper(this->m_pStr[i]);
		}
	}
	return *this;
}

bool MyString::operator==(const char* c) const {
	if (strlen(c) != strlen(m_pStr)) {
		return false;
	}
	for (size_t i = 0; i < strlen(c); i++) {
		if (m_pStr[i] != c[i]) {
			return false;
		}
	}
	return true;
}

bool MyString::operator==(char* c) const {
	return (m_pStr == c);
}