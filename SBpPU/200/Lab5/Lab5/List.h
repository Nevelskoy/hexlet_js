#pragma once
#include "Circle.h"


class List
{
	class Node {
		Node* pPrev;
		Node* pNext;
		Circle m_data;
	public:
		Node() : pPrev(nullptr), pNext(nullptr) {};
		Node(Node* p, const Circle* pc);	// для подключения Node в существующий список
		~Node();	// исключаем из списка

		bool operator!=(const Node& other) const;
		bool operator==(const Node& other) const;

		friend List;
		friend std::ostream& operator<<(std::ostream&, const List& l);
	};

	Node Head;	
	Node Tail;	
	size_t m_size;
public:
	List();
	List(const List& other);
	List(List&& other);
	~List();
	List& operator=(const List& other);
	List& operator=(List&& other);
	
	void AddToTail(const Circle& other);
	void AddToHead(const Circle& other);
	int Remove(const Circle& other);
	int RemoveAllExemple(const Circle& other);
	void ClearList();
	void SortList();
	void PrintList() const;

	friend std::ostream& operator<<(std::ostream&, const List& l);
	friend std::istream& operator>>(std::istream& is, List& l);
};

std::ostream& operator<<(std::ostream&, const List& l);
std::istream& operator>>(std::istream& is, List& l);
