// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.
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
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	// ���� MyString. 
		const int N=5;
		MyString str1[N] = {MyString("First"), MyString("Second"), MyString("Third")};
  
	//�������� - ������ �����-������ ������
		cout << sizeof(str1) << endl;
		for (int i = 0; i < N; i++) {
			cout << str1[i].GetString() << endl;
		}

	//�������� ������ const int N=5; , �� ������� ������ ���������������.
		cout << endl;
	}
	stop

	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
	const int M=5;

	MyString* arPtr[M] = { new MyString("FirstPtr"), new MyString("SecondPtr"), new MyString("ThirdPtr") };
		
	//������ �����-������ ������
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
   	//�������� ������ const int N=5; , �� ������� ������ ���������������.

	}
		stop

#endif
		//������� 3.������� ������������.��������� ������������,
		// ������������ � ������� �����.

		//�������� �������� �������:
		//������� ����� Shape (������� ��������� ����� ������)
		//� ��� ����������� ������ Rect � Circle.
		//���������: ����� ������ � ������ ����� ������ � �������
		//� ����������� ������ (��������, ����� ������ ����� �������
		//������� => � ������� ������ ����� ������ ����������, �������
		//����� ���������� ���� ������.
		//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);
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
	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������
#endif
	stop
//////////////////////////////////////////////////////////////////////
#if 0
	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.
	{
		Shape s;
		Rect r;
		Circle c;
		
		//����� ������ ������ ���������� � ��������� ��������???

		cout << "=====Early Binding=====\n" << endl; 

		s.WhereAmI();	//	Shape
		r.WhereAmI();	//	Rect
		c.WhereAmI();	//	Circle
		
		cout << "\n1) Pointers:" << endl;
		// ��� ������ ���������� ����� ���������� � ������� ������,
		// ������ ��� ��������� pShape, pRect � pCircle ����� ��� Shape. 
		// ����� �������� ������ ������������ ������, ����� ������������ ������� ����������
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	Shape
		pRect->WhereAmI();	//	Shape
		pCircle->WhereAmI(); //	Shape
		stop
		
		cout << "\n2) References:" << endl;

		////��������� ... �������� ������������
		Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmI();	//����� ����������� rShape	???
		rRect.WhereAmI();	//����� �����������	rRect	???
		rCircle.WhereAmI(); //����� ����������� rCircle	???
		stop
	}

	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� �������.
	{
		Shape s2;
		Rect r2;
		Circle c2;

		//����� ������ ������ ���������� � ��������� ��������???

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

		////��������� ... �������� ������������
		Shape& rShape = s2; //��������� s
		Shape& rRect = r2; //��������� r
		Shape& rCircle = c2; //��������� c
		rShape.WhereAmIVirtual();	//����� ����������� rShape	???
		rRect.WhereAmIVirtual();	//����� �����������	rRect	???
		rCircle.WhereAmIVirtual(); //����� ����������� rCircle	???
		stop
	}

#endif

//////////////////////////////////////////////////////////////////////
#if 0
	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.
	
		{
			Shape s3;
			Rect r3;
			Circle c3;
		}// ����� ����������� ���������� � �������� (�� ������������) �������, LIFO.
		 // ������� ����������, ������� ������ ������� �������, 
		 // ���������� ��� ������� ������.

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.
		{
			Shape s4;
			Rect r4;
			Circle c4;
		}
	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������
		cout << endl;
		cout << "\n=======Rect r(5, 10, GREEN, 4)=======" << endl;
		Rect r(5, 10, GREEN, 4);
		// Shape(r) - ������ r � �������� ���������
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle()};
		//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
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
	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1) ��� ������� � �������� ����� ��������� Shape* ����� �������������� ��������� �������� ������ Shape (�����������). �.�. ������� ������ ��������, ��� ����� �������� � ������ ������.
		Rect* pRects = new Rect[10];//2) ��������� �������� ��������� �� ������� Rect

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???
		
		for (int i = 0; i < 10; i++) {
		//	pShapes[i].WhereAmIVirtual();
		//	(reinterpret_cast<Rect*>(pShapes) + i)->WhereAmIVirtual();  // ��� ��������� �� ������������� ���� �������
			pRects[i].WhereAmIVirtual();
		}

		//���������� ����������� ����������� ������	
		delete[] pShapes;
		delete[] pRects;

		pShapes = nullptr;
		pRects = nullptr;		
	}
#endif

//////////////////////////////////////////////////////////////////////
#if 0
	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(5, 5, RED, 1);
		Shape* p = &r;	
		p->WhereAmIVirtual(); //Rect

		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape
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
	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(5, 5, RED, 1);
		Shape* p = &r;  //��������� ��� Shape, ������� ����� ������������� ���������� �� ���������
		
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
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

	MyString SuperString = bindStrs_2("New", "Year", "Update!", nullptr);
	cout << SuperString.GetString();

#endif
////////////////////////////////////////////////////////////////////////
/*
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

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

