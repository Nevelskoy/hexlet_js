//#include "other.h"
#include <iostream>

///////////////////////////////////////////////////
int value = 5;
int& ref = value;


void printArray(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


// 1.5. Объявите и определите функцию, вычисляющую квадрат числа, переданного в качестве параметра.
//  параметр должен быть ссылкой (!).
 int square(const int& x) {
	 int y = x * x;
	return y;
}


// 2.1. Объявите и определите три функции, которые увеличивают заданное
//с помощью параметра значение на 1 
// а) - IncByValue(),
int IncByValue(int x) {
	return x += 1;
}
// б) - IncByPointer(),
void IncByPointer(int *x) {
	*x += 1;
}
//в) - IncByReference()
void IncByReference(int& x) {
	x++;
}


// 2.2 Передача параметров c помощью указателя и по ссылке.
//Создайте функцию (функции) Swap(), которая меняет значения
//переменных nX и nY местами.
	// а)Функция должна принимать два указателя на int  и оперируя этими указателями
	//   должна менять значения переменных в вызывающей (!) программе
void Swap(int* x, int* y) {
	int c = *x;
	*x = *y;
	*y = c;
}

	// б)Функция должна принимать две ссылки на int и оперируя этими ссылками
	//   должна менять значения переменных в вызывающей (!) программе
void Swap(int& x, int& y) {
	int c = x;
	y = x;
	y = c;
}


// 3.2. Напишите функцию поиска минимального элемента во встроенном одномерном массиве
int Min(const int* arr, size_t size) {
	int result = 0;
	const int* min_num = arr;
	for (size_t i = 1; i < size; i++) {
		if (arr[i] < *min_num) {
			min_num = &arr[i];
		}
		result = *min_num;
	}
	return result;
}


// 3.3. Напишите функцию сравнения двух строк - MyStrCmp()
int Compare(const char* first, const char* second) {
	if (first == nullptr || second == nullptr) return -2;
	
	while (*first == *second) {
		if (*first == '\0') {
			return 0;
		}
		first++;
		second++;
	}

	if (*first > *second) {
		return 1;
	}
	else return -1;
}


// 4. Создайте и вызовите функцию, которая принимает в качестве параметра 
//порядковый номер - nN - месяца, 
//а возвращает  указатель на символьную строку, содержащую название заданного месяца. 
//Подсказки: 
//1) для того, чтобы данная функция работала корректно, 
// очень важно – как объявлена строка, указатель на которую требуется вернуть.
//2) Кроме того, было бы неплохо предусмотреть защиту при некорректном значении месяца.

const char* NameOfMonth(const int numOfMonth) {
	if (numOfMonth <= 0 || numOfMonth > 12) return "Incorrect month number!";

	int corrData = numOfMonth - 1;
	const char* month[] = { "January", "February", "March", "April", "May", "June", "July", \
						    "August", "September", "October", "November", "December" };
	const char* result = *(month + corrData);
	return result;
}


//Задание 5. Возвращение адреса.
//Напишите функцию, которая находит адрес минимального элемента в массиве,
// таким образом, чтобы ее вызов можно было использовать слева от знака равенства

int* MyMin(const int* arr, size_t size) {
	int min_ind = 0;
	for (size_t i = 1; i < size; i++) {
		if (arr[i] < arr[min_ind]) {
			min_ind = i;
		};
	}
	return const_cast<int*>(&arr[min_ind]);
}


//Задание 6 (*). 
int f1(int* arr, size_t length) {
	int result = 1; //

	for (size_t i = 0; i < length; i++)
	{
		result ^= (1 << arr[i]); // младший бит будет указывать на совпадения, каждый раз переписываясь с 1 на 0 и наоборот
	}							 // повторяющиеся элементы == 0	
	return result;
}

void f2(int result, int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		if ((result & (1 << arr[i])) != 0) { // младший бит 1 - нечетное количество раз и наоброт, ошибка обратоки числа "0";
			std::cout << arr[i] << " встречается в массиве нечетное число раз \n";
		}
		else std::cout << arr[i] << " встречается в массиве четное число раз \n";
		}
	std::cout << std::endl;
	}



void f3(int* ar, size_t S) {
	for (size_t i = 0; i < S; i++) {
		int count = 0;

		for (size_t j = 0; j < S; j++) {
			if (ar[j] == ar[i]) {
				count++;
			}
		}

		if (count % 2 == 0) {
			std::cout << ar[i] << "  встречается в массиве четное число раз" << std::endl;
		}
		else {
			std::cout << ar[i] << " встречается в массиве нечетное число раз" << std::endl;
		}
	}
}
