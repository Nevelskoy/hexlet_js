#pragma once
#include "MyString.h"


class MyData {
public:
	enum Sex {UNDEF, MALE, FEMALE};
private:
	Sex m_sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData() : m_sex(UNDEF), m_age(0), m_job("UNDEF"), m_salary(0) {};
	MyData(const Sex& s, size_t& age, const char* job, float& sal) : m_sex(s), m_age(age), m_job(job), m_salary(sal) {};
	MyData(const Sex& s, const size_t& age, const MyString& job, const float& sal) : m_sex(s), m_age(age), m_job(job), m_salary(sal) {};
	
	//MyData(const MyData& d) : m_sex(d.m_sex), m_age(d.m_age), m_job(d.m_job), m_salary(d.m_salary) {};
	//
	//MyData(MyData&& d);
	//~MyData();


	//MyData& operator=(const MyData& d);
	//MyData& operator=(MyData&& d);
	
	friend class BD;
//	friend class Pair;
//	friend class MyString;

	friend std::ostream& operator<<(std::ostream& os, const MyData& d);
};

std::ostream& operator<<(std::ostream& os, const MyData& d);