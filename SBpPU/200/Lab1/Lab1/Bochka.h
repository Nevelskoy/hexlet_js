#pragma once
class Bochka
{
	double m_water;
	double m_alcoConcentration;
//	int count;
public:
	Bochka(double m_water = 0, double m_alcoConcentration = 0);
	//double GetWater() const;
	double GetAlco() const;
	void SetBochka(double water, double m_alcoConcentration);
	void Pereliv(Bochka& other, double cup);
	void GetConcentration(double alcoAmount, double cup);
};

