#include "Pair.h"


bool Pair::operator==(const char* k) const {
	return (this->m_key == k);
}

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	os << "Name: " << pair.m_key << pair.m_data;
	return os;
}