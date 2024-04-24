#pragma once

class Rect{
	int m_left, m_right, m_top, m_bottom;

public:
	// ��� ������� �������� ������������� � ������������? ���� �� ������������ codestyle?
	Rect(int m_left=0, int m_right=0, int m_top=0, int m_bottom=0);  // ���������������� ����������� ������
	Rect(const Rect& rect);											 // ���������������� ����������� �����������
	~Rect();

	void InflateRect(int dl, int dr, int dt, int db);
	void InflateRect(unsigned int x=1, unsigned int y=1);
	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int& m_left, int& m_right, int& m_top, int& m_bottom) const;  // read-only ����� ������
	void BoundingRect3(Rect& rec1, Rect& rec2);

};

Rect BoundingRect(Rect rec1, Rect rec2);

Rect BoundingRect2(Rect& rec1, Rect& rec2);