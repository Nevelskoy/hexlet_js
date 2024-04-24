//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------
#include "List.h"
#include <fstream>

const char* sep = "------------------------------------\n";

int main()
{
	//
	// 1. Создаем список
	//
	List ls1;
	
	ls1.AddToTail(Circle(1, 1, 1));		//добавляем элементы в список
	ls1.AddToTail(Circle(5, 5, 5));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(4, 4, 4));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(3, 3, 3));
	ls1.AddToTail(Circle(2, 2, 2)); 
	ls1.AddToTail(Circle(2, 2, 2));
//	std::cout << ls1 << sep;					//выводим список	

	//ls1.Remove(Circle(2,2,2));			// удаляем первый элемент, равный заданному
	//std::cout << ls1; 

	ls1.RemoveAllExemple(Circle(2, 2, 2));     // удаляем все элементы, равные заданному
//	std::cout << ls1 << sep;	
	////
	//// 2. Приведенный ниже код должен выполняться корректно	
	////
	List ls2 = ls1;
//	std::cout << ls2; 
	List ls3 = ls2;
//	std::cout << ls3 << sep; 

//	ls2.AddToHead(Circle(2, 2, 2));
//	ls2.AddToHead(Circle(5, 5, 5));	
	//
	//std::cout << ls2 << sep;	
	ls1 = ls2;			// из "большого" списка в "маленький"
//	std::cout << ls1;	
	//
	ls1 = ls3;			// из "маленького" списка в "большой"
//	std::cout << ls1 << sep;	
	////
	//// 3. Вспоминаем про семантику перемещения	
	////
//	List ls4 = std::move(ls2);
	//std::cout << ls4; 
	//std::cout << ls2; 	

//	ls3 = std::move(ls4);
	//std::cout << ls3; 
	//std::cout << ls4 << sep;
	////
	////4.  Сортировка по возрастанию площади кружка
	////
	//std::cout << ls3;

	//ls3.SortList();
	//std::cout << ls3 << sep;
	////
	//// 5. Файловый ввод/вывод
	////
	//std::ofstream fout("list.txt");
	//fout << ls3;	// выводим список в файл
	//fout.close();
	//	
	std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	//
	std::cout << ls5;
	// 
	// 6. Дополнительные проверки
	//
	// ...
	//ls3.PrintList();
	//ls3.ClearList();
	//std::cout << ls3;
	//ls3.PrintList();

	return 0;
}