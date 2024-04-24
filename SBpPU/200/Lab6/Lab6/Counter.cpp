#include <string>
#include "Counter.h"

//------------CounterList------------//
Counter* Counter::CountersList::m_Head = nullptr;
size_t Counter::CountersList::CountersList::m_curCounters;

Counter::CountersList::CountersList() {
	m_Head = nullptr;
	m_curCounters = 0;
}

Counter::CountersList::~CountersList() {
	Counter* current = m_Head;
	while (current) {
		Counter* next = current->pNext;
		delete current;
		current = next;
	}
}

//------------Counter------------//
Counter::CountersList Counter::m_countersList;


Counter::Counter() {
	if (CountersList::m_Head == nullptr) {
		m_pStr = nullptr;
		pNext = nullptr;
		return;
	}

	Counter* p = CountersList::m_Head;
	while (p->pNext != nullptr) {
		if (strcmp(m_pStr, p->m_pStr) == 0) {
			++(p->m_nOwners);
			delete this;
			return;
		}
		p = p->pNext;
	}

	m_pStr = new char[strlen(m_pStr) + 1];
	strcpy(m_pStr, m_pStr);

	pNext = CountersList::m_Head->pNext;
	CountersList::m_Head->pNext = this;
	Counter::CountersList::m_curCounters++;
	m_nOwners++;
}


Counter::Counter(const char* ch) {
	CountersList countersList;
	Counter* p = countersList.m_Head;
	for (size_t i = 0; i < countersList.m_curCounters; i++) {
		p = p->pNext;
		if (strcmp(ch, p->m_pStr) == 0) {
			++(p->m_nOwners);
			return;
		}
	}
	m_pStr = new char[strlen(ch) + 1];
	strcpy_s(m_pStr, strlen(ch) + 1, ch);
	countersList.m_Head->pNext = this;
	countersList.m_curCounters++;
	m_nOwners++;
}


Counter* Counter::add(const char* ch) {
	CountersList countersList;
	Counter* p = countersList.m_Head;
	for (size_t i = 0; i < countersList.m_curCounters; i++) {
		p = p->pNext;
		if (strcmp(ch, p->m_pStr) == 0) {
			++(p->m_nOwners);
			return p;
		}
	}
	Counter* tmp = new Counter(ch);
	tmp->pNext = countersList.m_Head->pNext;
	countersList.m_Head->pNext = tmp;
	countersList.m_curCounters++;
	tmp->m_nOwners++;
	return tmp;
}



