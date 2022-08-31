#pragma once
#define MAX 1000
#include "Karta.h"

class Stos
{
private:
	int top;

public:
	Karta a[MAX]; // Maximum size of Stack

	Stos();
	bool push(Karta x);
	Karta pop();
	Karta peek();
	bool isEmpty();
	void allCards();
	int getTop();
	void setTop(int i);
	Karta getCard(int i);
	void repair();
};

