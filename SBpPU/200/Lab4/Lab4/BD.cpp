#include "BD.h"


BD::~BD() {
    delete[] pBase;
}

MyData& BD::operator[](const char* key) {
    for (size_t i = 0; i < m_count; i++) {
        if (pBase[i] == key) {
            return pBase[i].m_data;
        }
    }
    if (m_count == m_capacity) {
        Pair* tempBase = new Pair [++m_capacity];
        for (size_t i = 0; i < m_count; i++) {
            tempBase[i] = std::move(pBase[i]);
        }
        delete[] pBase;
        pBase = tempBase;
    }
    pBase[m_count].m_key = key;
    return pBase[m_count++].m_data;
}

BD::BD(const BD& bd) {
	if (bd.pBase) {
		m_count = bd.m_count;
		m_capacity = bd.m_capacity;
		pBase = new Pair[m_capacity];
		for (size_t i = 0; i < bd.m_count; i++) {
			pBase[i] = bd.pBase[i];
		}
	} else {
		pBase = nullptr;
		m_count = 0;
		m_capacity = 0;
	}
}

BD& BD::operator=(BD&& other) {
	if (this != &other)	{
		delete[] pBase;
		pBase = other.pBase;
		m_count = other.m_count;
		m_capacity = other.m_capacity;
		other.pBase = nullptr;
		other.m_count = 0;
		other.m_capacity = 0;
	}
	return *this;
}

int BD::deletePair(const char* key) {
	for (size_t i = 0; i < m_count; i++) {
		if (pBase[i] == key) {
			m_count--;
			if (i != m_count) {
				pBase[i] = pBase[m_count];
			}
			return i;
		} 
	}
	return -1;
}

//BD& BD::operator=(const BD& bd) {
//	if (this != &bd) {
//		if (bd.pBase) {	
//			m_count = bd.m_count;
//			if (m_capacity < bd.m_capacity) {
//				if (m_capacity > bd.m_count) {
//					for (size_t i = 0; i < bd.m_count; i++) {
//						pBase[i] = bd.pBase[i];
//					}
//					//for (size_t i = bd.m_count; i < m_capacity; i++) {
//					//	this->deletePair(pBase->m_key.GetString());
//					}
//				}	else {
//				m_capacity = bd.m_capacity;
//
//
//				}
//
//				m_capacity = bd.m_capacity;
//				for (size_t i = 0; i < m_capacity; i++) {
//					pBase[i] = bd.pBase[i];
//				}
//
//
//
//				Pair* tempBase = new Pair[bd.m_capacity];
//				for (size_t i = 0; i < bd.m_count; i++) {
//					tempBase[i] = bd.pBase[i];
//				}
//				delete[] pBase;
//				pBase = tempBase;
//			}	
//			else {
//				size_t mincount = m_count > bd.m_count ? m_count : bd.m_count;
//				for (size_t i = 0; i < mincount; i++) {
//					pBase[i] = bd.pBase[i];
//				}
//				if (m_capacity > bd.m_capacity) {
//					
//				}
//
//				m_count = bd.m_count;
//				m_capacity = bd.m_capacity;			
//			}
//		} return *this;
//	}	else {
//		std::cout << "NULL exeption!!!" << std::endl;
//	}
//}

std::ostream& operator<<(std::ostream& os, const BD& bd) {
	for (size_t i = 0; i < bd.m_count; i++)	{
		os << bd.pBase[i];
	}
	return os;
}

BD& BD::operator=(const BD& bd) {
	if (this != &bd) {
		if (m_capacity < bd.m_count) {
			m_capacity = bd.m_count;
			delete[] pBase;
			pBase = new Pair[m_capacity];
		}
		for (size_t i = 0; i < bd.m_count; i++) {
			pBase[i] = bd.pBase[i];
		}
		m_count = bd.m_count;
	}
	return *this;
}


void BD::sort() {
	if (m_count < 2) { std::cout << "less than 2!"; };
	size_t max_i;
	size_t i;
	for (size_t j = 0; j < m_count; j++)
	{
		max_i = j;
		i = j + 1;
		for (; i < m_count; ++i) {
			//if (pBase[i]> pBase[j])
			if (strcmp(pBase[i].m_key.m_pStr, pBase[j].m_key.m_pStr) > 0) {
				max_i = i;
			}
		}
		Pair tmp = std::move(pBase[j]);
		pBase[j] = std::move(pBase[max_i]);
		pBase[max_i] = std::move(tmp);
	}
}



