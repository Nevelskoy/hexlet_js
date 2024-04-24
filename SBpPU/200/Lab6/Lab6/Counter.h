#pragma once
#pragma warning(disable : 4996)

class Counter
{
	class CountersList
	{
	public:
		static Counter* m_Head;  // ������ ������
		static size_t m_curCounters;  // ������� ���������� (������ ������)

		CountersList();
		~CountersList();
	};

	char* m_pStr;
	size_t m_nOwners;  // ������� ������������� ������ ������ 
	Counter* pNext; //	��������� �� ��������� Counter 

	static CountersList m_countersList; // �������� ���� ������������ �����
	static Counter* add(const char* ch);

	Counter();
	Counter(const char* ch);
	
	friend class MyString;
};




