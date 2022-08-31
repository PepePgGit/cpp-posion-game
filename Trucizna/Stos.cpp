#include "Stos.h"
#include <iostream>

using namespace std;

Stos::Stos() 
{
	top = -1;
}

bool Stos::push(Karta x)
{
	if (top >= (MAX - 1)) 
	{
		cout << "Stack Overflow";
		return false;
	}
	else 
	{
		a[++top] = x;
		//cout << x.getWartosc << " pushed into stack\n";
		return true;
	}
}

Karta Stos::pop()
{
	if (top < 0) 
	{
		cout << "Stack Underflow";
		return a[top];
	}
	else 
	{
		Karta x = a[top--];
		return x;
	}
}

Karta Stos::peek()
{
	if (top < 0) 
	{
		cout << "Stack is Empty";
		return a[top];
	}
	else 
	{
		Karta x = a[top];
		return x;
	}
}

bool Stos::isEmpty()
{
	return (top < 0);
}

void Stos::allCards() 
{
	for (int i = 0; i < top + 1; i++) 
	{
		a[i].wypiszKarte();
		cout << ' ';
	}
}

int Stos::getTop() 
{
	return (top+1);
}

void Stos::setTop(int i) 
{
	top = i;
}

Karta Stos::getCard(int i)
{
	return a[i];
}

void Stos::repair() 
{
	int n = this->getTop();

	for (int i = 1; i < n+1; i++) //?
	{
		a[i - 1] = a[i];
	}

	top--;
}