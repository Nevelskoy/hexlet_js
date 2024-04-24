#include "MyString.h"



// ќпределение конструктора.
MyString::MyString(const char* pStr) {
	m_pStr = new char[strlen(pStr) + 1];
	memcpy(m_pStr, pStr, strlen(pStr) + 1);
}

MyString::MyString(const MyString& other) {
	m_pStr = new char[strlen(other.m_pStr) + 1];
	memcpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
}

// ќпределение деструктора.
MyString::~MyString() {
	delete[] m_pStr;
	m_pStr = nullptr;
}

const char* MyString::GetString(void) {
	return m_pStr;
};

//MyString bindStrs(const char* string, ...) {
//	va_list pList;			// указатель на необ€зательный параметр
//	va_start(pList, string);	// устанавливаем указатель
//	MyString result(string);
//	const char* str;
//	while ((str = va_arg(pList, const char*)) != nullptr) {
//		char* temp = new char[strlen(string) + strlen(str) + 1];
//		strcpy_s(temp, string, strlen(string) + 1);
//		strcat_s(temp, str);
//		string = temp;
//	}
//
//	va_end(pList);
//	return result;
//};

//MyString& operator+=(const char* str) {
//	char* temp = new char[strlen(data) + strlen(str) + 1];
//	strcpy(temp, data);
//	strcat(temp, str);
//	delete[] data;
//	data = temp;
//	return *this;
//}

//MyString bindStrs_2(size_t count, const char* str1, ...)
//{
//	va_list stek_p;
//	va_start(stek_p, count); // устанавливаем указатель и переводим сразу на следующий
//	size_t SumLenght = 0;
//	for (size_t i = 0; i < count; i++)
//	{
//		SumLenght += strlen(*reinterpret_cast<const char**>(stek_p)); //—читаем какой динамический массив понадобитьс€ дл€ передачи строки в объект MyString
//		va_arg(stek_p, const char*);
//	}
//	va_start(stek_p, count);
//	char* pStr = new char[SumLenght + 1];
//	SumLenght = 0;
//	for (size_t i = 0; i < count; i++)
//	{
//		strcpy(&pStr[SumLenght], *reinterpret_cast<const char**>(stek_p)); // опируем строки в динамический массив
//		SumLenght = strlen(pStr);
//		va_arg(stek_p, const char*);
//	}
//	va_end(stek_p);
//	MyString MyString(pStr);
//	delete[]pStr;
//	return MyString;
//}

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

