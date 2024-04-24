#pragma once
#pragma warning(disable : 4996)

class Counter
{
	class CountersList
	{
	public:
		static Counter* m_Head;  // голова списка
		static size_t m_curCounters;  // счетчик указателей (размер списка)

		CountersList();
		~CountersList();
	};

	char* m_pStr;
	size_t m_nOwners;  // счетчик пользователей данной строки 
	Counter* pNext; //	указатель на следующий Counter 

	static CountersList m_countersList; // перечень всех используемых строк
	static Counter* add(const char* ch);

	Counter();
	Counter(const char* ch);
	
	friend class MyString;
};




