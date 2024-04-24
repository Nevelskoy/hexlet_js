#pragma once
#include <iostream>
#include "Pair.h"

class BD {
	Pair* pBase;
	size_t m_count;
	size_t m_capacity;
public:
	BD() : pBase(nullptr), m_count(0), m_capacity(0) {};
	~BD();

	BD(const BD& bd);
	BD& operator=(const BD& bd);    //оптимизированный!
	BD(BD&& bd);
	BD& operator=(BD&& bd);

	MyData& operator[](const char*);

	int deletePair(const char* key);
	void sort();

//	friend class MyData;
//	friend class Pair;
//	friend class MyString;

	friend std::ostream& operator<<(std::ostream& os, const BD& bd);

};


std::ostream& operator<<(std::ostream& os, const BD& bd);

