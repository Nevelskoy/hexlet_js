#include <iostream>
#include "functions.h"


int sumOfnumber(int x) {
	if (x == 0) {
		return 0;
	}
	else {
		return x + sumOfnumber(x - 1);
	}
}


int countDigits(int x) {
	if (x < 10) {
		return 1;
	}
	else {
		return 1 + countDigits(x / 10);
	}
}


void reverseStr(const char* str) {
	if (*str) {
		reverseStr(str + 1);
		std::cout << *str;
	}
}


void forwardStr(const char* str) {
	if (*str) {
		std::cout << *str;
		forwardStr(str + 1);	
	}
}
