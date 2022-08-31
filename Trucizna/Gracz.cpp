#include "Gracz.h"

Gracz::Gracz() 
{
	liczbaPkt = 0;
	ileG = 0;
	/*
	for (int i = 0; i < 7; i++) 
	{
		odpornosc[i] = 0;
	}
	*/
}

void Gracz::setPkt(int i) 
{
	liczbaPkt = i;
}

int Gracz::getPkt() 
{
	return liczbaPkt;
}
