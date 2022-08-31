#include "Karta.h"
#include <iostream>

using namespace std;

Karta::Karta() 
{
	kolor = '-';
	wartosc = 0;
}

Karta::Karta(char k, int w) 
{
	kolor = k;
	wartosc = w;
}

char Karta::getKolor() 
{
	return kolor;
}

int Karta::getWartosc()
{
	return wartosc;
}

void Karta::setKolor(char k)
{
	kolor = k;
}

void Karta::setWartosc(int w)
{
	wartosc = w;
}

void Karta::wypiszKarte() 
{
	cout << this->getWartosc() << ' ';
	if (this->getKolor() == 'g')
	{
		cout << "green";
	}
	if (this->getKolor() == 'b')
	{
		cout << "blue";
	}
	if (this->getKolor() == 'r')
	{
		cout << "red";
	}
	if (this->getKolor() == 'v')
	{
		cout << "violet";
	}
	if (this->getKolor() == 'y')
	{
		cout << "yellow";
	}
	if (this->getKolor() == 'w')
	{
		cout << "white" ;
	}
	if (this->getKolor() == 'l')
	{
		cout << "black";
	}
}