#include "MyByte.h"


Bytes::Bytes(unsigned char byte) {
	this->m_dec = byte;
}


void Bytes::ShowDec() {
	std::cout << "Dec: " << static_cast<int>(m_dec) << std::endl;
}


void Bytes::ShowChar() {
	printf("\nChar: %c", m_dec);
}


void Bin::Show() {
//	printf("\n %b", )
	printf("\nBin: %u %u %u %u %u %u %u %u", m_bin7, m_bin6, m_bin5, m_bin4, m_bin3, m_bin2, m_bin1, m_bin0);
}


void Oct::Show() {
	printf("\nOct: %o%o%o", m_oct2, m_oct1, m_oct0);
}


void Hex::Show() {
	printf("\nHex: %x%x", m_hex1, m_hex0);
}


void Bin::ShowPos(int pos) {
	unsigned char temp = 0;
	switch (pos)
	{
	case 1:
		temp = m_bin0;
		break;
	case 2:
		temp = m_bin1;
		break;
	case 3:
		temp = m_bin2;
		break;
	case 4:
		temp = m_bin3;
		break;
	case 5:
		temp = m_bin4;
		break;
	case 6:
		temp = m_bin5;
		break;
	case 7:
		temp = m_bin6;
		break;
	case 8:
		temp = m_bin7;
		break;
	default:
		printf("\n!!!Outside range 1 - 8!!!");
		break;
	}
	printf("\nBin position %d: %u", pos, temp);
}


void Oct::ShowPos(int pos) {
	unsigned char temp = 0;
	switch (pos)
	{
	case 1:
		temp = m_oct0;
		break;
	case 2:
		temp = m_oct1;
		break;
	case 3:
		temp = m_oct2;
		break;
	default:
		printf("\n!!!Outside range 1 - 3!!!");
		break;
	}
	printf("\nOct position %d: %o", pos, temp);
}


void Hex::ShowPos(int pos) {
	unsigned char temp = 0;
	switch (pos)
	{
	case 1:
		temp = m_hex0;
		break;
	case 2:
		temp = m_hex1;
		break;
	default:
		printf("\n!!!Outside range 1 - 2!!!");
		break;
	}
	printf("\nHex position %d: %o", pos, temp);
}


void Bin::Edit(int pos, int val) {
	switch (pos)
	{
	case 1:
		m_bin0 = ~m_bin0;
		break;
	case 2:
		m_bin1 = ~m_bin1;
		break;
	case 3:
		m_bin2 = ~m_bin2;
		break;
	case 4:
		m_bin3 = ~m_bin3;
		break;
	case 5:
		m_bin4 = ~m_bin4;
		break;
	case 6:
		m_bin5 = ~m_bin5;
		break;
	case 7:
		m_bin6 = ~m_bin6;
		break;
	case 8:
		m_bin7 = ~m_bin7;
		break;
	default:
		printf("\n!!!Outside range 1 - 8!!!");
		break;
	}
}


void Oct::Edit(int pos, int val) {
	switch (pos)
	{
	case 1:
		m_oct0 = val;
		break;
	case 2:
		m_oct1 = val;
		break;
	case 3:
		m_oct1 = val;
		break;
	default:
		printf("\n!!!Outside range 1 - 3!!!");
		break;
	}
}


void Hex::Edit(int pos, int val) {
	switch (pos)
	{
	case 1:
		m_hex0 = val;
		break;
	case 2:
		m_hex1 = val;
		break;
	default:
		printf("\n!!!Outside range 1 - 2!!!");
		break;
	}
}