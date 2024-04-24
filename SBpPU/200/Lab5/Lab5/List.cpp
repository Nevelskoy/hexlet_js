#include "List.h"


List::Node::Node(Node* p, const Circle* pc) : m_data(*pc) {
	if (p) {
		this->pPrev = p;
		this->pNext = p->pNext;
		p->pNext = this;
		this->pNext->pPrev = this;
	}
}

List::Node::~Node() {
	if (pPrev)	{
		pPrev->pNext = this->pNext;
	}
	if (pNext)	{
		pNext->pPrev = this->pPrev;
	}
}

List::~List() {
	while(Head.pNext != &Tail)	{
		delete Head.pNext;
	}
}

bool List::Node::operator!=(const Node& other) const
{
	return (m_data != other.m_data);
}
bool List::Node::operator==(const Node& other) const
{
	return (m_data == other.m_data);
}

List::List() : m_size(0) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::List(const List& other) : m_size(other.m_size) {
	//готовим адреса для копирования
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* Current = &Head;
	Node* Other = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++) {
		Current = new Node(Current, &Other->m_data);
		Other = Other->pNext;
	}
}

//List List::operator=(const List& other) {
//	if (this != &other)
//		if (&other) {
//			
//			Node* Curr = Head.pNext;
//			Node* Othr = other.Head.pNext;
//			if (m_size < other.m_size) {
//				while (Curr != &Tail)  {
//					Curr->m_data = Othr->m_data;
//					Othr = Othr->pNext;
//					Curr = Curr->pNext;
//				}
//				while (Othr != &other.Tail)	{
//					this->AddToTail(Othr->m_data);
//					Othr = Othr->pNext;
//				}
//			}
//			else {
//				while (Othr != &other.Tail) {
//						Curr->m_data = Othr->m_data;
//						Othr = Othr->pNext;
//						Curr = Curr->pNext;
//					}
//					Curr = Head.pNext;
//					for (size_t i = other.m_size; i < m_size; i++) {
//						if (i > other.m_size) {
//							delete Curr;
//						}
//						Curr = Curr->pNext;
//					}
//			}
//			m_size = other.m_size;
//		}
//
//	return *this;
//}


//List& List::operator=(const List& other) {
//	if (this != &other) {
//		if (&other) {
//			Node* Curr = Head.pNext;
//			Node* Othr = other.Head.pNext;
//			if (m_size < other.m_size) {
//				while (Curr != &Tail && Othr != &other.Tail) {
//					Curr->m_data = Othr->m_data;
//					Othr = Othr->pNext;
//					Curr = Curr->pNext;
//				}
//				while (Othr != &other.Tail) {
//					this->AddToTail(Othr->m_data);
//					Othr = Othr->pNext;
//				}
//			}
//			else {
//				while (Othr != &other.Tail && Curr != &Tail) {
//					Curr->m_data = Othr->m_data;
//					Othr = Othr->pNext;
//					Curr = Curr->pNext;
//				}
//				while (Curr != &Tail) {
//					Node* temp = Curr;
//					Curr = Curr->pNext;
//					delete temp;
//				}
//			}
//			m_size = other.m_size;
//		}
//	}
//	return *this;
//}
List& List::operator=(const List& other) {
	if (this != &other) {
		for (size_t i = other.m_size; i < m_size; i++) {
			delete Head.pNext;
		}
			Node* Curr = Head.pNext;
			Node* Othr = other.Head.pNext;
			for (size_t i = 0; i < m_size; i++) {
				Curr->m_data = Othr->m_data;
				Othr = Othr->pNext;
				Curr = Curr->pNext;
			}
			for (size_t i = m_size; i < other.m_size; i++) {
				this->AddToTail(Othr->m_data);
				Othr = Othr->pNext;
			}
			m_size = other.m_size;
		}
	return *this;
}

List& List::operator=(List&& other) {
	if (&other != this) {
		Node* current = Head.pNext;
		while (current != &Tail) {
			Node* temp = current;
			current = current->pNext;
			delete temp;
		}
		m_size = other.m_size;

			Head.pNext = other.Head.pNext;
			Tail.pPrev = other.Tail.pPrev;
			Head.pNext->pPrev = &Head;
			Tail.pPrev->pNext = &Tail;
			
			other.Head.pNext = &other.Tail;
			other.Tail.pPrev = &other.Head;
			other.m_size = 0;
	}
	return *this;
}

List::List(List&& other) : m_size(other.m_size) {
	if (m_size) {
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	else {
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
}


void List::AddToTail(const Circle& c) {
	new Node(Tail.pPrev, &c);
	m_size++;
}

void List::AddToHead(const Circle& c) {
	new Node(&Head, &c);
	m_size++;
}

int List::Remove(const Circle& other) {
	Node* p = Head.pNext;
	for (size_t i = 0; i < m_size; i++) {
		if (p->m_data == other) {
			delete p;
			--m_size;
			return 1;
		}
		p = p->pNext;
	}
	return -1;
}

int List::RemoveAllExemple(const Circle& other) {
	Node* p = Head.pNext;
	size_t count = 0;
	for (size_t i = 0; i < m_size; i++) {
		Node* n = p->pNext;
		if (p->m_data == other) {
			
			delete p;
			++count;
			
		} 
			p = n;
		
	}
	m_size = m_size - count;
	return count;
}


void List::SortList() {
	if (m_size < 2) return;
	Node* p1 = Head.pNext;
	while (p1 != Tail.pPrev) {
		Node* pmin = p1;
		Node* p2 = p1->pNext;

		while (p2 != &Tail) {
			if (pmin->m_data.GetAreaCircle() > p2->m_data.GetAreaCircle())	{
				pmin = p2;
			}
			p2 = p2->pNext;
		}

		Circle tmp = p1->m_data;
		p1->m_data = pmin->m_data;
		pmin->m_data = tmp;
		p1 = p1->pNext;
	}
}

void List::ClearList() {
	Node* pNode = Head.pNext;
	while (pNode != &Tail) {
		Node* temp = pNode;
		pNode = pNode->pNext;
		delete temp;
	}
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
}


std::ostream& operator<<(std::ostream& os, const List& l) {
	os << "LIST size: " << l.m_size << std::endl;
	List::Node* p = l.Head.pNext;
	for (size_t i = 0; i < l.m_size; i++) {
		os << p->m_data;
		p = p->pNext;
	}
	return os;
}

std::istream& operator>>(std::istream& is, List& l) {
	size_t n;
	is >> n;

	for (size_t i = 0; i < n; i++) {
		int X, Y, R;
		is >> R >> X >> Y;
		l.AddToHead(Circle(X, Y, R));
	}
	return is;
}


void List::PrintList() const {
	//CheckAll(); // проверка целостности хранилища
	Node* p = Head.pNext;
	std::cout << "Head: " << &Head << "->" << Head.pNext << ", " << Tail.pPrev << "->Tail: " << &Tail << ", m_size: " << m_size << std::endl;
	while (p != &Tail) 	{
		std::cout << p << ", x: " << p->m_data.GetX() << ", y: " << p->m_data.GetY() << ", r: " << p->m_data.GetRadius() << ", pPrev: " << p->pPrev << ", pNext: " << p->pNext << std::endl;
		p = p->pNext;
	}
	std::cout << std::endl;
}