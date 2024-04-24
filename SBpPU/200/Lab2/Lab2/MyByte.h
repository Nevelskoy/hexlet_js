#pragma once
#include <iostream>


class Bin {
	unsigned char m_bin0 : 1;
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;

public:
	void Show();					// выводим все двоичные цифры
	void ShowPos(int pos);			// выводим цифру в позиции
	void Edit(int pos, int val);	// изменяем цифру в позиции

	friend union Bytes;
};


class Oct {
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;

public:
	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);

	friend union Bytes;
};


class Hex {
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;

public:
	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);

	friend union Bytes;
};


union Bytes {
private:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:
	Bytes(unsigned char byte);

	void ShowBin() { m_bin.Show(); }
	void ShowOct() { m_oct.Show(); }
	void ShowHex() { m_hex.Show(); }

	void ShowDec();
	void ShowChar();

	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos) { m_oct.ShowPos(pos); }
	void ShowHexPos(int pos) { m_hex.ShowPos(pos); }

	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }

};