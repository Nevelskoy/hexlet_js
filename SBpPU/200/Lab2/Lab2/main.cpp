// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.
#include <iostream>
#include "MyString.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "MyByte.h"
#include <tchar.h>

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
#if 0
	//Задание 1.Массив объектов класса.
	{
	//Объявите и проинициализируйте массив ar из объектов
	// типа MyString. 
		const int N=5;
		MyString str1[N] = {MyString("First"), MyString("Second"), MyString("Third")};
  
	//Проверка - печать строк-членов класса
		cout << sizeof(str1) << endl;
		for (int i = 0; i < N; i++) {
			cout << str1[i].GetString() << endl;
		}

	//Замените размер const int N=5; , не изменяя список инициализаторов.
		cout << endl;
	}
	stop

	//Задание 2.Массив указателей на объекты класса.
	{
	//Объявите и проинициализируйте массив arPtr из N
	//указателей на объекты типа MyString (сами объекты 
	//создаются динамически!).
	const int M=5;

	MyString* arPtr[M] = { new MyString("FirstPtr"), new MyString("SecondPtr"), new MyString("ThirdPtr") };
		
	//Печать строк-членов класса
	cout << sizeof(arPtr) << endl;
	for (int i = 0; i < M; i++) {
		if (arPtr[i]) {
			cout << (*arPtr[i]).GetString() << endl;
		}
	}

	for (int i = 0; i < M; i++) {
		if (arPtr[i]) {
			delete arPtr[i];
		}
	}
   	//Замените размер const int N=5; , не изменяя список инициализаторов.

	}
		stop

#endif
		//Задание 3.Простое наследование.Аргументы конструктора,
		// передаваемые в базовый класс.

		//Создайте иерархию классов:
		//базовый класс Shape (который описывает любую фигуру)
		//и два производных класса Rect и Circle.
		//Подумайте: какие данные и методы нужно ввести в базовый
		//и производные классы (например, любую фигуру можно сделать
		//цветной => в базовом классе можно ввести переменную, которая
		//будет определять цвет фигуры.
		//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
#if 0	
	{
		Circle circ1(5, RED, 2);
		circ1.GetColor_str();
		double square_circ1 = circ1.GetSquareCircle();
		cout << "S1 = " << square_circ1 << endl;

		Rect rect2(5, 10, GREEN, 4);
		rect2.GetColor_str();
		rect2.GetRatio();

		double square_rect2 = rect2.GetSquareCircle();
		cout << "S2 = " << square_rect2 << endl;
	}
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
#endif
	stop
//////////////////////////////////////////////////////////////////////
#if 0
	//Задание 4.Виртуальные функции.
	//4а) Модифицируйте классы Shape,Rect и Circle:
	//добавьте в каждый класс public метод void WhereAmI().
	//Реализация каждой функции должна выводить сообщение 
	//следующего вида "Now I am in class Shape(Rect или Circle)".
	//Выполните приведенный фрагмент, объясните результат.
	{
		Shape s;
		Rect r;
		Circle c;
		
		//Метод какого класса вызывается в следующих строчках???

		cout << "=====Early Binding=====\n" << endl; 

		s.WhereAmI();	//	Shape
		r.WhereAmI();	//	Rect
		c.WhereAmI();	//	Circle
		
		cout << "\n1) Pointers:" << endl;
		// При раннем связывании метод вызывается в базовом классе,
		// потому что указатели pShape, pRect и pCircle имеют тип Shape. 
		// Чтобы вызывать методы производного класса, нужно использовать позднее связывание
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	Shape
		pRect->WhereAmI();	//	Shape
		pCircle->WhereAmI(); //	Shape
		stop
		
		cout << "\n2) References:" << endl;

		////Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c
		rShape.WhereAmI();	//вызов посредством rShape	???
		rRect.WhereAmI();	//вызов посредством	rRect	???
		rCircle.WhereAmI(); //вызов посредством rCircle	???
		stop
	}

	//4б) Добавьте в базовый и производные классы виртуальный
	// метод WhereAmIVirtual(). По аналогии с 4а вызовите
	// виртуальный метод посредством объектов, указателей и
	// ссылок, определенных в предыдущем фрагменте.
	//Выполните новый фрагмент, объясните разницу.
	{
		Shape s2;
		Rect r2;
		Circle c2;

		//Метод какого класса вызывается в следующих строчках???

		cout << "\n======Late Binding=====\n" << endl;

		s2.WhereAmIVirtual();	//	Shape
		r2.WhereAmIVirtual();	//	Rect
		c2.WhereAmIVirtual();	//	Circle

		cout << "\n1) Pointers:" << endl;

		Shape* pShape = &s2;
		Shape* pRect = &r2;
		Shape* pCircle = &c2;
		pShape->WhereAmIVirtual();	//	Shape
		pRect->WhereAmIVirtual();	//	Rect
		pCircle->WhereAmIVirtual(); //	Circle
		stop

		cout << "\n2) References:" << endl;

		////Заполните ... согласно комментариям
		Shape& rShape = s2; //псевдоним s
		Shape& rRect = r2; //псевдоним r
		Shape& rCircle = c2; //псевдоним c
		rShape.WhereAmIVirtual();	//вызов посредством rShape	???
		rRect.WhereAmIVirtual();	//вызов посредством	rRect	???
		rCircle.WhereAmIVirtual(); //вызов посредством rCircle	???
		stop
	}

#endif

//////////////////////////////////////////////////////////////////////
#if 0
	//Задание 5.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.
	
		{
			Shape s3;
			Rect r3;
			Circle c3;
		}// Вызов деструктора происходит в обратном (от конструктора) порядке, LIFO.
		 // Обычный деструктор, который просто удаляет ресурсы, 
		 // выделенные для объекта класса.

	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу.
		{
			Shape s4;
			Rect r4;
			Circle c4;
		}
	
	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте
		cout << endl;
		cout << "\n=======Rect r(5, 10, GREEN, 4)=======" << endl;
		Rect r(5, 10, GREEN, 4);
		// Shape(r) - объект r в качестве аргумента
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle()};
		//Вызовите для каждого элемента массива метод WhereAmIVirtual()
		//ar[2]->GetColor_str();
		//Circle c1(2, GREEN, 1);
		//Circle c2(c1);
		//c2.GetColor_str();

		for (int i = 0; i < sizeof(ar) / sizeof(Shape*); i++) {
			ar[i]->WhereAmIVirtual();;
		}

		for (int i = 0; i < sizeof(ar) / sizeof(Shape*); i++) {
			delete ar[i];
			ar[i] = nullptr;
		}
		cout << "\n=======End of Shape* ar[]=======" << endl;
		//delete[] ar;
	stop

#endif

#if 0
	//Задание 6*. В чем заключается отличие 1) и 2)
	{
		Shape* pShapes = new Rect[10];//1) при доступе к объектам через указатель Shape* будет использоваться интерфейс базового класса Shape (полиморфизм). Т.к. объекты разных размеров, это может привести к потере данных.
		Rect* pRects = new Rect[10];//2) указатель напрямую указывает на объекты Rect

		//Попробуйте вызвать метод WhereAmIVirtual() для каждого элемента обоих массивов -
		//в чем заключается проблема???
		
		for (int i = 0; i < 10; i++) {
		//	pShapes[i].WhereAmIVirtual();
		//	(reinterpret_cast<Rect*>(pShapes) + i)->WhereAmIVirtual();  // тип указателя не соответствует типу объекта
			pRects[i].WhereAmIVirtual();
		}

		//Освободите динамически захваченную память	
		delete[] pShapes;
		delete[] pRects;

		pShapes = nullptr;
		pRects = nullptr;		
	}
#endif

//////////////////////////////////////////////////////////////////////
#if 0
	//Задание 7.Виртуальные функции и оператор разрешения области видимости. 

	{
		Rect r(5, 5, RED, 1);
		Shape* p = &r;	
		p->WhereAmIVirtual(); //Rect

		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmIVirtual()класса Shape
		p->Shape::WhereAmIVirtual();
		r.Shape::WhereAmIVirtual();

		//Shape s;
		//Shape* pt = &s;
		//p = &s;
		//p->WhereAmIVirtual();
	
	}
#endif

//////////////////////////////////////////////////////////////////////
#if 0
	//Задание 8.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	{
		Rect r(5, 5, RED, 1);
		Shape* p = &r;  //применяем тип Shape, поэтому можем переназначать переменную на подклассы
		
		cout << "\nBefore: " << r.GetSquareRect() << endl;
		p->Inflate(5);	
		cout << "After: " << r.GetSquareRect() << endl;
		
		Circle c;
		p = &c;
		p->Inflate(5);
	}
#endif


//////////////////////////////////////////////////////////////////////
#if 0
	//Задание 9. Создайте глобальную функцию, которая будет принимать любое
	//количество указателей на строки, а возвращать объект MyString,
	//в котором строка будет конкатенацией параметров

	MyString SuperString = bindStrs_2("New", "Year", "Update!", nullptr);
	cout << SuperString.GetString();

#endif
////////////////////////////////////////////////////////////////////////
/*
	//Задание 10.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...
*/

	Bytes byte(1);
//	Bytes byte1(0b10100111);
//	byte.ShowHex();
//	byte.ShowBin();
	byte.ShowDec();
	byte.ShowOct();
	byte.ShowBin();
	byte.ShowHex();
//	byte1.ShowDec();
	byte.ShowChar();
//	byte1.ShowChar();
// 	byte.ShowBinPos(5);
//	byte.ShowOctPos(1);
//	byte.ShowHexPos(1);
//	byte.EditBin(5, 1);
//	byte.ShowBin();

//	byte.EditHex(1, 15);
//	byte.ShowHex();

	return 0;
}//endmain

