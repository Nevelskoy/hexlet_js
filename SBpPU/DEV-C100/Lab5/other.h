//Прототипы используемых в данном задании функций:
#pragma once


extern int& ref;


void printArray(int arr[], size_t size);

int square(const int& x);

int IncByValue(int x);
void IncByPointer(int* x);
void IncByReference(int& x);

void Swap(int* x, int* y);
void Swap(int& x, int& y);

int Min(const int* arr, size_t size);
int Compare(const char* first, const char* second);

const char* NameOfMonth(const int numOfMonth);

int* MyMin(const int* arr, size_t size);

int f1(int* ar, size_t S);
void f2(int result, int* arr, size_t length);
void f3(int* ar, size_t S);
