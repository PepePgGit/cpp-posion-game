#pragma once
#include "Stos.h"

class Gracz
{
private:
	int liczbaPkt;

public:
	Gracz();

	Stos reka;
	Stos odrzucone;
	int* kolorOdrzucony;
	int ileG;

	void setPkt(int i);
	int getPkt();
};

