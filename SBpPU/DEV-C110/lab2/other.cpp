#include <iostream>
#include <stdarg.h>
#include "other.h"


///////////////////////////////////////////////////
//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	int* ptr = &arg1;
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов
	while (*ptr != 0) {
		std::cout << "<" << *ptr << "> ";
		ptr++;
		number++;
	}
	std::cout << "--- ";
	//Печать числа элементов
	std::cout << "Number of elements: " << number << std::endl;
}


void VarArgsMacro(int arg1, ...) {
	int count = 1;	
	va_list ptr;
	std::cout << "<" << arg1 << "> ";
	va_start(ptr, arg1);
	while (*ptr != 0) {
		std::cout << "<" << va_arg(ptr, int) << "> ";
		count++;
	}
	std::cout << "--- ";
	//Печать числа элементов
	std::cout << "Number of elements: " << count << std::endl;
	va_end(ptr); //NULL;
}

///////////////////////////////////////////////////
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
};


int DayOfMonth(int DayOfYear, int year) {
	return 0;
};


int DayOfYear(size_t day, size_t month, size_t year, int nDayTab[][12]) {
	int result = 0;
	int month_day = 0;
	if (isLeapYear(year)) {
		for (size_t i = 0; i < month - 1; i++) {
			month_day += nDayTab[0][i];
		}
	}
	else {
		for (size_t i = 0; i < month - 1; i++) {
			month_day += nDayTab[1][i];
		}
	}
	result = month_day + day;
	return result;
	
};


///////////////////////////////////////////////////
void PrintArray(int (*ar)[M], size_t N, size_t M) {
	for (size_t i = 0; i < N * M; i++) {
		if ((i % M == 0) && (i != 0)) {
			std::cout << std::endl;
		}
		std::cout << *(*ar + i) << " ";
	}
	std::cout << std::endl;
}


void PrintArray(int *pArr, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			std::cout << pArr[i * M + j] << " ";
		}
		std::cout << std::endl;
	}
}

//TASK_6/////////////////////////////////////////////////
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется
												//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}
//-----------------------------------------------------------------------
void PrAr(int* ar, size_t N) {
	int* ptr1 = static_cast<int*>(ar);
	for (size_t i = 0; i < N; i++) {
		std::cout << *(ptr1 + i) << " ";
	}
	std::cout << std::endl;
}


void PrAr(double* ar, size_t N) {
	double* ptr1 = static_cast<double*>(ar);
	for (size_t i = 0; i < N; i++) {
		std::cout << *(ptr1 + i) << " ";
	}
	std::cout << std::endl;
}


void SwapInt(void* p1, void* p2)
{
	int* ptr1 = static_cast<int*>(p1);
	int* ptr2 = static_cast<int*>(p2);
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}


void SwapDouble(void* p1, void* p2)
{
	double* ptr1 = static_cast<double*>(p1);
	double* ptr2 = static_cast<double*>(p2);
	double tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}


void SwapChar(void* p1, void* p2)
{
	char** ptr1 = static_cast<char**>(p1);
	char** ptr2 = static_cast<char**>(p2);
	char* tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
//-----------------------------------------------------------------------
int CmpInt(void* p1, void* p2)
{
	int* ptr1 = static_cast<int*>(p1);
	int* ptr2 = static_cast<int*>(p2);
	int nResult = (*ptr1 - *ptr2);
	return nResult;
}

int CmpDouble(void* p1, void* p2)
{
	double* ptr1 = static_cast<double*>(p1);
	double* ptr2 = static_cast<double*>(p2);
	int nResult = (*ptr1 > *ptr2) ? 1 : ((*ptr1 == *ptr2) ? 0 : -1);
	return nResult;
}

int CmpChar(void* p1, void* p2)
{
	char** ptr1 = static_cast< char**>(p1);
	char** ptr2 = static_cast< char**>(p2);
	return strcmp(*ptr1,*ptr2);
}
//-----------------------------------------------------------------------
const char* GetString1()
{
	return "Hello";
}
//-----------------------------------------------------------------------
const char* GetString2()
{
	const char* str = "Book";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString3()
{
	static char str[] = "Little";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString4()
{
	static char str[] = "world";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString5()
{
	char* str = new char[strlen("time")+1];
	return str;
}
