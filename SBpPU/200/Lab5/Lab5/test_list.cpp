//------------------------------------------------------------------------------
// ��������� ����������� ������
//------------------------------------------------------------------------------
#include "List.h"
#include <fstream>

const char* sep = "------------------------------------\n";

int main()
{
	//
	// 1. ������� ������
	//
	List ls1;
	
	ls1.AddToTail(Circle(1, 1, 1));		//��������� �������� � ������
	ls1.AddToTail(Circle(5, 5, 5));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(4, 4, 4));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(3, 3, 3));
	ls1.AddToTail(Circle(2, 2, 2)); 
	ls1.AddToTail(Circle(2, 2, 2));
//	std::cout << ls1 << sep;					//������� ������	

	//ls1.Remove(Circle(2,2,2));			// ������� ������ �������, ������ ���������
	//std::cout << ls1; 

	ls1.RemoveAllExemple(Circle(2, 2, 2));     // ������� ��� ��������, ������ ���������
//	std::cout << ls1 << sep;	
	////
	//// 2. ����������� ���� ��� ������ ����������� ���������	
	////
	List ls2 = ls1;
//	std::cout << ls2; 
	List ls3 = ls2;
//	std::cout << ls3 << sep; 

//	ls2.AddToHead(Circle(2, 2, 2));
//	ls2.AddToHead(Circle(5, 5, 5));	
	//
	//std::cout << ls2 << sep;	
	ls1 = ls2;			// �� "��������" ������ � "���������"
//	std::cout << ls1;	
	//
	ls1 = ls3;			// �� "����������" ������ � "�������"
//	std::cout << ls1 << sep;	
	////
	//// 3. ���������� ��� ��������� �����������	
	////
//	List ls4 = std::move(ls2);
	//std::cout << ls4; 
	//std::cout << ls2; 	

//	ls3 = std::move(ls4);
	//std::cout << ls3; 
	//std::cout << ls4 << sep;
	////
	////4.  ���������� �� ����������� ������� ������
	////
	//std::cout << ls3;

	//ls3.SortList();
	//std::cout << ls3 << sep;
	////
	//// 5. �������� ����/�����
	////
	//std::ofstream fout("list.txt");
	//fout << ls3;	// ������� ������ � ����
	//fout.close();
	//	
	std::ifstream fin("list.txt");
	List ls5;		// ������ ������ �� �����
	fin >> ls5;
	fin.close();
	//
	std::cout << ls5;
	// 
	// 6. �������������� ��������
	//
	// ...
	//ls3.PrintList();
	//ls3.ClearList();
	//std::cout << ls3;
	//ls3.PrintList();

	return 0;
}