#pragma once
#include <iostream>


class A
{
	int* m_arr;
	int m_size;

public:
	A(int size) {
		this->m_size = size;
		this->m_arr = new int[size];
	}

	~A() {
		delete[] m_arr;
	}

	int& operator[](int idx) {
		if (idx >= 0 && idx < this->m_size) {
			return this->m_arr[idx];
		}
		throw std::out_of_range("Index out of range");
	}

	//const int& operator[](int idx) const {
	//	if (idx >= 0 && idx < this->m_size) {
	//		return this->m_arr[idx];
	//	}
	//	throw std::out_of_range("Index out of range");
	//}
};


class B {
	int** m_arr;
//	int m_size;
	int m_row;

public:
	B(int row, int col) {
		this->m_row = row;
		this->m_arr = new int*[row];
		for (int i = 0; i < row; i++) {	
			this->m_arr[i] = new int[col];
		}
	}

	~B() {
		for (int i = 0; i < m_row; i++) {
			delete[] m_arr[i];
		}
		delete[] m_arr;
	}

	int* operator[](int index) {
		return m_arr[index];
	}
};
