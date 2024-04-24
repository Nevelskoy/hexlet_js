#pragma once
#include "MyData.h"

class Pair {
	MyString m_key;
	MyData m_data;    // MyData* pData - данные о сотруднике

	Pair() : m_key("UNDEF"), m_data() {};
	Pair(const char* key, const MyData& data) :m_data(data)// m_key(key), m_data(data.m_sex, data.m_age, data.m_job, data.m_salary)
	{};
//	~Pair();

//	Pair(const Pair& other);

	bool operator==(const char* k) const;

 	friend class BD;
//	friend class MyData;
//	friend class MyString;
	
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

};

std::ostream& operator<<(std::ostream& os, const Pair& pair);