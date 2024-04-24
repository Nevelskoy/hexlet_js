#include "Bochka.h"

Bochka::Bochka(double water, double alco) {
	//TODO: users input!
	this->m_water = water;
	this->m_alcoConcentration = alco;
};

//double Bochka::GetWater() const {
//	return this->m_water;
//};

double Bochka::GetAlco() const {
	return this->m_alcoConcentration;
};

void Bochka::SetBochka(double water, double alco) {
	this->m_water = water;
	this->m_alcoConcentration = alco;
};

void Bochka::Pereliv(Bochka& other, double cup) {
	double alcoAmount = cup * this->m_alcoConcentration;
	other.GetConcentration(alcoAmount, cup);
//	alcoAmount = this->m_alcoConcentration * cup;
	this->m_water = this->m_water - cup;
	this->m_alcoConcentration = alcoAmount;
};

void Bochka::GetConcentration(double alcoAmount, double cup) {
	double totalAmount = this->m_water + cup;
	this->m_alcoConcentration = (this->m_alcoConcentration * this->m_water + alcoAmount) / totalAmount;
	this->m_water = totalAmount;
};

//(0% * 100l + 96% * 1l) / (100l + 1l) = 96l / 101l ≈ 0.95

// ConcentrationWater = (water) ? water / (water + alco) : 0;
// ConcentrationAlco = (alco) ? alco / (water + alco) : 0;