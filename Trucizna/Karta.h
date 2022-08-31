#pragma once
class Karta
{
private:
	char kolor;
	int wartosc;

public:
	Karta();
	Karta(char k, int w);
	char getKolor();
	int getWartosc();
	void setKolor(char k);
	void setWartosc(int w);
	void wypiszKarte();
};

