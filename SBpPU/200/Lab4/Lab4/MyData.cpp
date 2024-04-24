#include "BD.h"


//MyData& MyData::operator=(const MyData& d)
//{
//	if (&d != this) {
//		m_sex = d.m_sex;
//		m_age = d.m_age;
//		m_job = d.m_job;
//		m_salary = d.m_salary;
//	}
//	return *this;
//}
//
//MyData::MyData(MyData&& d) {
//	m_sex = std::move(d.m_sex);
//	m_age = std::move(d.m_age);
//	m_job = std::move(d.m_job);
//	m_salary = std::move(d.m_salary);
//}
//
//MyData& MyData::operator=(MyData&& d) {
//	m_sex = d.m_sex;
//	m_age = d.m_age;
//	m_job = d.m_job;
//	m_salary = d.m_salary;
//	return *this;
//}


std::ostream& operator<<(std::ostream& os, const MyData& d) {
	os << "\tAge: " << d.m_age << "\tJob: " << d.m_job << "\tSex: " << (((d.m_sex == MyData::MALE) ? "Male" : (d.m_sex == MyData::FEMALE) ? "Female" : "UNDEF")) << "\tSalary: " << d.m_salary << std::endl;
	return os;
}