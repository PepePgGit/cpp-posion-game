// Trucizna.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Karta.h"
#include "Gracz.h"
#include "string.h"
#include "math.h"
#include "Kociol.h"
#include "Karty.h"
#include "stdio.h"

using namespace std;

//1
void wczytajDane1(int& k, int& g, int& gv, int& o)
{
	cin >> k;
	cin >> g;
	cin >> gv;
	cin >> o;
}

void tworzTalie(int& k, int& g, int& gv, int& o, int *taliaKoloru, int& buf, Karta *taliaCala)
{
	for (int i = 0; i < o; i++) // talia dla 1 z kolorow
	{
		cin >> buf;
		taliaKoloru[i] = buf;
	}

	for (int i = 0; i < g; i++) // talia <- zielone
	{
		taliaCala[i].setKolor('g');
		taliaCala[i].setWartosc(gv);
	}
	for (int i = 0; i < k; i++) // talia <- reszta kolorow
	{
		for (int j = 0; j < o; j++)
		{
			if (i == 0) // niebieskie
			{
				taliaCala[g + i * o + j].setKolor('b'); // blue
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
			if (i == 1) // czerwone
			{
				taliaCala[g + i * o + j].setKolor('r'); // red
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
			if (i == 2) // fioletowe
			{
				taliaCala[g + i * o + j].setKolor('v'); // violet
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
			if (i == 3) // zolte
			{
				taliaCala[g + i * o + j].setKolor('y'); // yellow
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
			if (i == 4) // biale
			{
				taliaCala[g + i * o + j].setKolor('w'); //white
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
			if (i == 5) // czarne
			{
				taliaCala[g + i * o + j].setKolor('l'); //black
				taliaCala[g + i * o + j].setWartosc(taliaKoloru[j]);
			}
		}
	}
}

void wypiszTalie(int k, int g, int o, Karta* taliaCala)
{
	int ilosc = g + k * o; // ilosc kart w tali
	for (int i = 0; i < ilosc; i++)
	{
		/*
		cout << taliaCala[i].getWartosc() << ' ';
		if (taliaCala[i].getKolor() == 'g')
		{
			cout << "green" << ' ';
		}
		if (taliaCala[i].getKolor() == 'b')
		{
			cout << "blue" << ' ';
		}
		if (taliaCala[i].getKolor() == 'r')
		{
			cout << "red" << ' ';
		}
		if (taliaCala[i].getKolor() == 'v')
		{
			cout << "violet" << ' ';
		}
		if (taliaCala[i].getKolor() == 'y')
		{
			cout << "yellow" << ' ';
		}
		if (taliaCala[i].getKolor() == 'w')
		{
			cout << "white" << ' ';
		}
		if (taliaCala[i].getKolor() == 'l')
		{
			cout << "black" << ' ';
		}
		*/
		taliaCala[i].wypiszKarte();
		cout << ' ';
	}
}
//1

//2
void wczytajDane2(int& k, int& g, int& gv, int& o, int& n)
{
	cin >> n;
	cin >> k;
	cin >> g;
	cin >> gv;
	cin >> o;
}

void rozdajTalie(Gracz* Gracze, int n, Karta* taliaCala, int k, int g, int o)
{
	int ilosc = g + k * o; // ilosc kart w tali
	for (int i = 0; i < ilosc; i++) 
	{
		Gracze[i % n].reka.push(taliaCala[i]);
	}
}

void wypiszGiK(Gracz* Gracze, int n, int player, int k)
{
	cout << "active player = " << player << endl;
	cout << "players number = " << n << endl;

	for (int i = 1; i < n + 1; i++) 
	{
		cout << i << " player hand cards: ";
		Gracze[i - 1].reka.allCards();
		cout << endl;

		cout << i << " player deck cards: ";
		Gracze[i - 1].odrzucone.allCards();
		cout << endl;
	}

	for (int i = 1; i < k + 1; i++)
	{
		cout << i << " pile cards: " << endl;
	}
}
//2

//3a + 3b
void ileKociol(char kolor, int& k)
{
	if (kolor == 'b')
	{
		if (k < 1) 
		{
			k = 1;
		}
	}
	else if (kolor == 'r')
	{
		if (k < 2)
		{
			k = 2;
		}
	}
	else if (kolor == 'v')
	{
		if (k < 3)
		{
			k = 3;
		}
	}
	else if (kolor == 'y')
	{
		if (k < 4)
		{
			k = 4;
		}
	}
	else if (kolor == 'w')
	{
		if (k < 5)
		{
			k = 5;
		}
	}
	else if (kolor == 'l')
	{
		if (k < 6)
		{
			k = 6;
		}
	}
}

char checkBufor2(string bufor) 
{
	if (bufor == "green") 
	{
		return 'g';
	}
	else if (bufor == "blue")
	{
		return 'b';
	}
	else if (bufor == "red")
	{
		return 'r';
	}
	else if (bufor == "violet")
	{
		return 'v';
	}
	else if (bufor == "yellow")
	{
		return 'y';
	}
	else if (bufor == "white")
	{
		return 'w';
	}
	else if (bufor == "black")
	{
		return 'l';
	}
	return '-';
}

void wczytajDaneGetLine3(int& player, int& n) 
{
	int i = 0;
	char tab[256];

	cin.getline(tab, 256);

	while (tab[i] < 48 || tab[i] > 57) 
	{
		++i;
	}
	player = (int)tab[i] - 48;

	cin.getline(tab, 256);

	i = 0;

	while (tab[i] < 48 || tab[i] > 57)
	{
		++i;
	}
	n = (int)tab[i] - 48;
}

void wczytajStanGetLine1(int player, int n, Gracz* gracze, int& k)
{
	int wart = 0, p, rows = 2 * n, j = 0;
	char kol;
	char tab[256];

	for (int i = 0; i < rows; i++)
	{
		cin.getline(tab, 256);
		j = 0;
		while (0 == 0) 
		{
			if (tab[j++] == ':') 
			{
				break;
			}
		}
		while (tab[j] != '\0') 
		{
			if (tab[j] == ' ') 
			{
				++j;
			}
			else if (tab[j] > 47 && tab[j] < 58)
			{
				wart = (int)tab[j] - 48;
				++j;

				if (tab[j] > 47 && tab[j] < 58) 
				{
					wart = wart * 10;
					wart = wart + (int)tab[j] - 48;
					++j;
				}
			}
			else
			{
				kol = tab[j];
				++j;

				if (kol == 'b')
				{
					++j;
					if (tab[j] == 'a')
					{
						kol = 'l';
					}
					else
					{
						kol = 'b';
					}
				}
				ileKociol(kol, k);

				Karta* karta1 = new Karta(kol, wart);

				if (i % 2 == 0)
				{
					p = i / 2;
					gracze[p].reka.push(*karta1);
				}
				else
				{
					p = i - 1;
					p = p / 2;
					gracze[p].odrzucone.push(*karta1);
				}

				while (tab[j] != ' ' && tab[j] != '\0') 
				{
					++j;
				}
			}
		}
	}
}

/*
void wczytajDane3(int& player, int& n)
{
	char bufor;

	for (int i = 0; i < 17; i++)
	{
		bufor = getchar();
	}
	player = (int)(bufor - 48);

	getchar(); // endl

	for (int i = 0; i < 18; i++)
	{
		bufor = getchar();
	}
	n = (int)(bufor - 48);

	getchar(); //endl
}

void wczytajStan1(int player, int n, Gracz* gracze, int& k) 
{
	int wart = 0, p, rows = 2*n;
	char kol;

	for (int i = 0; i < rows; i++)
	{
		// buforuje
		for (int j = 0; j < 20; j++)
		{
			kol = getchar();
		}
		// buforuje
		if (getchar() != '\n')
		{
			while (0 == 0)
			{
				scanf_s("%d", &wart);
				getchar();

				kol = getchar();

				if (kol == 'b')
				{
					getchar();
					if (getchar() == 'a')
					{
						kol = 'l';
					}
					else
					{
						kol = 'b';
					}
				}
				ileKociol(kol, k);

				Karta* karta1 = new Karta(kol, wart);

				if (i % 2 == 0)
				{
					p = i / 2;
					gracze[p].reka.push(*karta1);
				}
				else
				{
					p = i - 1;
					p = p / 2;
					gracze[p].odrzucone.push(*karta1);
				}
				//gracze[n - 1].odrzucone.push(*karta1);

				while ((kol != '\n') && (kol != ' '))
				{
					kol = getchar();
				}


				if (kol == '\n')
				{
					break;
				}
			}
		}
	}
}
*/

void wypiszStan1(int n, Gracz* gracze) 
{
	int k, rows = 2*n;
	for (int i = 0; i < rows; i++)
	{
		if (i % 2 == 0)
		{
			k = i / 2;
			cout << k+1;
			cout << " player has ";
			cout << gracze[k].reka.getTop();
			cout << " cards on hand" << endl;
			/*
			printf_s("%d", k + 1);
			printf_s(" player has ");
			printf_s("%d", gracze[k].reka.getTop());
			printf_s(" cards on hand");
			printf_s("\n");
			*/
		}
		else
		{
			k = i - 1;
			k = k / 2;
			cout << k+1;
			cout << " player has ";
			cout << gracze[k].odrzucone.getTop();
			cout << " cards in front of him" << endl;
			/*
			printf_s("%d", k + 1);
			printf_s(" player has ");
			printf_s("%d", gracze[k].odrzucone.getTop());
			printf_s(" cards in front of him");
			printf_s("\n");
			*/
		}
	}
}
//3a + 3b

// 3b
void wczytajStanGetLine2(int k, Kociol* kocioly)
{
	int wart;
	char kol;
	int j = 0;
	
	char tab[256];

	for (int i = 0; i < k; i++)
	{
		cin.getline(tab, 256);
		j = 0;
		while (0 == 0)
		{
			if (tab[j++] == ':')
			{
				break;
			}
		}
		while (tab[j] != '\0')
		{
			if (tab[j] == ' ')
			{
				++j;
			}
			else if (tab[j] > 47 && tab[j] < 58)
			{
				wart = (int)tab[j] - 48;
				++j;

				if (tab[j] > 47 && tab[j] < 58)
				{
					wart = wart * 10;
					wart = wart + (int)tab[j] - 48;
					++j;
				}
			}
			else
			{
				kol = tab[j];
				++j;

				if (kol == 'b')
				{
					++j;
					if (tab[j] == 'a')
					{
						kol = 'l';
					}
					else
					{
						kol = 'b';
					}
				}
				Karta* karta1 = new Karta(kol, wart);

				kocioly[i].stos.push(*karta1);

				while (tab[j] != ' ' && tab[j] != '\0')
				{
					++j;
				}
			}
		}
	}
}

/*
void wczytajStan2(int k, Kociol* kocioly) 
{
	int wart;
	char kol;
	for (int i = 0; i < k; i++) 
	{
		//buforuje
		for (int i = 0; i < 13; i++)
		{
			kol = getchar();
		}
		//buforuje

		if (getchar() != '\n')
		{
			while (0 == 0)
			{
				scanf_s("%d", &wart);
				getchar();

				kol = getchar();
				if (kol == 'b')
				{
					getchar();
					if (getchar() == 'a')
					{
						kol = 'l';
					}
					else
					{
						kol = 'b';
					}
				}

				Karta* karta1 = new Karta(kol, wart);

				kocioly[i].stos.push(*karta1);

				while ((kol != '\n') && (kol != ' '))
				{
					kol = getchar();
				}

				if (kol == '\n')
				{
					break;
				}
			}
		}
	}
}
*/

void wypiszStan2(int k, Kociol* kocioly)
{
	for (int i = 0; i < k; i++)
	{
		/*
		printf_s("there are ");
		printf_s("%d", kocioly[i].stos.getTop());
		printf_s(" cards on ");
		printf_s("%d", i + 1);
		printf_s(" pile");
		printf_s("\n");
		*/
		cout << "there are ";
		cout << kocioly[i].stos.getTop();
		cout << " cards on ";
		cout << i + 1;
		cout << " pile";
		cout << endl;
	}
}
// 3b

//4a
int greenCards(Gracz* gracze, int n, Karta& kartaZiel, int k, Kociol* kocioly) 
{
	int ileZiel = 0, ileKart;

	// sprawdzanie u graczy 
	for (int i = 0; i < n; i++) // najpierw trzeba ustawic karteZiel na karteZiel z dana wartoscia
	{
		ileKart = gracze[i].reka.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].reka.getCard(j).getKolor() == 'g') 
			{
				if ((kartaZiel.getKolor() == 'g') && (kartaZiel.getWartosc() != gracze[i].reka.getCard(j).getWartosc()))
				{
					return -1;
				}
				else if (kartaZiel.getKolor() != 'g')
				{
					kartaZiel = gracze[i].reka.getCard(j);
				}
				ileZiel++;
			}
		}

		ileKart = gracze[i].odrzucone.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].odrzucone.getCard(j).getKolor() == 'g')
			{
				if ((kartaZiel.getKolor() == 'g') && (kartaZiel.getWartosc() != gracze[i].odrzucone.getCard(j).getWartosc()))
				{
					return -1;
				}
				else if (kartaZiel.getKolor() != 'g')
				{
					kartaZiel = gracze[i].odrzucone.getCard(j);
				}
				ileZiel++;
			}
		}
	}
	// sprawdzanie u graczy

	// sprawdzanie w kotlach
	for (int i = 0; i < k; i++) 
	{
		ileKart = kocioly[i].stos.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (kocioly[i].stos.getCard(j).getKolor() == 'g')
			{
				if ((kartaZiel.getKolor() == 'g') && (kartaZiel.getWartosc() != kocioly[i].stos.getCard(j).getWartosc()))
				{
					return -1;
				}
				else if (kartaZiel.getKolor() != 'g')
				{
					kartaZiel = gracze[i].reka.getCard(j);
				}
				ileZiel++;
			}
		}
	}
	// sprawdzanie w kotlach

	return ileZiel;
	/*
	if (kartaZiel.getKolor() == 'g')
	{
		return ileZiel;
	}
	else 
	{
		return 0;
	}
	*/
}

void wypiszGreen(int ileZiel, Karta karta) 
{
	if (ileZiel == -1) 
	{
		cout<<"Different green cards values occurred";
	}
	else if (ileZiel == 0) 
	{
		cout<<"Green cards does not exist";
	}
	else 
	{
		cout<<"Found ";
		cout<<ileZiel;
		cout<<" green cards, all with ";
		cout<<karta.getWartosc();
		cout<<" value";
	}
}
//4a

// 4b
void countCards(Gracz* gracze, int n, int k, Kociol* kocioly, Karty* wszystkie)
{
	int ileKart;

	// sprawdzanie u graczy
	for (int i = 0; i < n; i++)
	{
		ileKart = gracze[i].reka.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].reka.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;
			}
		}

		ileKart = gracze[i].odrzucone.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].odrzucone.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;
			}
		}
	}
	// sprawdzanie u graczy

	// sprawdzanie w kotlach
	for (int i = 0; i < k; i++)
	{
		ileKart = kocioly[i].stos.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (kocioly[i].stos.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;
			}
		}
	}
	// sprawdzanie w kotlach
}

bool checkCards(int k, Karty* wszystkie)
{
	for (int i = 0; i < k - 1; i++)
	{
		if (wszystkie[i].ilosc != wszystkie[i + 1].ilosc)
		{
			return false;
		}
	}
	return true;
}

void wypiszCards(int k, Karty* wszystkie) 
{
	bool error = false;
	for (int i = 0; i < k - 1; i++) 
	{
		if (wszystkie[i].ilosc != wszystkie[i + 1].ilosc)
		{
			cout << "At least two colors with a different number of cards were found: ";
			cout << endl;
			for (int j = 0; j < k + 1; j++)
			{
				if (j == 0) 
				{
					cout << "blue cards are ";
					cout << wszystkie[0].ilosc;
					cout << endl;
				}
				else if (j == 1)
				{
					cout << "red cards are ";
					cout << wszystkie[1].ilosc;
					cout << endl;
				}
				else if (j == 2)
				{
					cout << "violet cards are ";
					cout << wszystkie[2].ilosc;
					cout << endl;
				}
				else if (j == 3)
				{
					cout << "yellow cards are ";
					cout << wszystkie[3].ilosc;
					cout << endl;
				}
				else if (j == 4)
				{
					cout << "white cards are ";
					cout << wszystkie[4].ilosc;
					cout << endl;
				}
				else if (j == 5)
				{
					cout << "black cards are ";
					cout << wszystkie[5].ilosc;
					cout << endl;
				}
			}
			error = true;
			break;
		}
	}
	
	if (error == false) 
	{
		cout << "The number cards of all colors is equal: ";
		cout << wszystkie[2].ilosc;
		cout << endl;
	}
}
// 4b

// 5
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void colorCards(Gracz* gracze, int n, int k, Kociol* kocioly, Karty* wszystkie)
{
	int ileKart;
	// sprawdzanie u graczy
	for (int i = 0; i < n; i++)
	{
		ileKart = gracze[i].reka.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].reka.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;

				wszystkie[0].stos.push(gracze[i].reka.getCard(j));
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;

				wszystkie[1].stos.push(gracze[i].reka.getCard(j));
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;

				wszystkie[2].stos.push(gracze[i].reka.getCard(j));
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;

				wszystkie[3].stos.push(gracze[i].reka.getCard(j));
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;

				wszystkie[4].stos.push(gracze[i].reka.getCard(j));
			}
			else if (gracze[i].reka.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;

				wszystkie[5].stos.push(gracze[i].reka.getCard(j));
			}
		}

		ileKart = gracze[i].odrzucone.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (gracze[i].odrzucone.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;

				wszystkie[0].stos.push(gracze[i].odrzucone.getCard(j));
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;

				wszystkie[1].stos.push(gracze[i].odrzucone.getCard(j));
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;

				wszystkie[2].stos.push(gracze[i].odrzucone.getCard(j));
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;

				wszystkie[3].stos.push(gracze[i].odrzucone.getCard(j));
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;

				wszystkie[4].stos.push(gracze[i].odrzucone.getCard(j));
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;

				wszystkie[5].stos.push(gracze[i].odrzucone.getCard(j));
			}
		}
	}
	// sprawdzanie u graczy

	// sprawdzanie w kotlach
	for (int i = 0; i < k; i++)
	{
		ileKart = kocioly[i].stos.getTop();
		for (int j = 0; j < ileKart; j++)
		{
			if (kocioly[i].stos.getCard(j).getKolor() == 'b')
			{
				wszystkie[0].ilosc++;

				wszystkie[0].stos.push(kocioly[i].stos.getCard(j));
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'r')
			{
				wszystkie[1].ilosc++;

				wszystkie[1].stos.push(kocioly[i].stos.getCard(j));
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'v')
			{
				wszystkie[2].ilosc++;

				wszystkie[2].stos.push(kocioly[i].stos.getCard(j));
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'y')
			{
				wszystkie[3].ilosc++;

				wszystkie[3].stos.push(kocioly[i].stos.getCard(j));
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'w')
			{
				wszystkie[4].ilosc++;

				wszystkie[4].stos.push(kocioly[i].stos.getCard(j));
			}
			else if (kocioly[i].stos.getCard(j).getKolor() == 'l')
			{
				wszystkie[5].ilosc++;

				wszystkie[5].stos.push(kocioly[i].stos.getCard(j));
			}
		}
	}
	// sprawdzanie w kotlach
}

bool sortwypiszColorCards(Karty* wszystkie, int k)
{
	int ileKart;
	int **tab = new int*[k];
	bool yn = true;

	for (int i = 0; i < k; i++)
	{
		ileKart = wszystkie[i].stos.getTop();

		tab[i] = new int[ileKart];

		for (int j = 0; j < ileKart; j++) 
		{
			tab[i][j] = wszystkie[i].stos.getCard(j).getWartosc();
		}
	}

	for (int i = 0; i < k; i++) 
	{
		qsort(tab[i], wszystkie[i].stos.getTop(), sizeof(int), compare); // sortowanie kazdego koloru wartoscami do gory
	}

	if (checkCards == false) 
	{
		yn = false;
	}
	else 
	{
		for (int i = 0; i < wszystkie[0].stos.getTop(); i++) // wartosci
		{
			for (int j = 0; j < k - 1; j++)
			{
				if (tab[j][i] != tab[j + 1][i]) // kolory czy po kolei maja rowne wartosci
				{

					yn = false;
				}
			}
		}
	}

	if (yn == false) 
	{
		cout << "The values of cards of all colors are not identical:";
		cout << endl;

		if (k < 1) 
		{
			return false;
		}
		cout << "blue cards values: ";
		for (int c = 0; c < wszystkie[0].stos.getTop(); c++)
		{
			cout << tab[0][c];
			cout << ' ';
		}
		cout << endl;

		if (k < 2)
		{
			return false;
		}
		cout << "red cards values: ";
		for (int c = 0; c < wszystkie[1].stos.getTop(); c++)
		{
			cout << tab[1][c];
			cout << ' ';
		}
		cout << endl;

		if (k < 3)
		{
			return false;
		}
		cout << "violet cards values: ";
		for (int c = 0; c < wszystkie[2].stos.getTop(); c++)
		{
			cout << tab[2][c];
			cout << ' ';
		}
		cout << endl;

		if (k < 4)
		{
			return false;
		}
		cout << "yellow cards values: ";
		for (int c = 0; c < wszystkie[3].stos.getTop(); c++)
		{
			cout << tab[3][c];
			cout << ' ';
		}
		cout << endl;

		if (k < 5)
		{
			return false;
		}
		cout << "white cards values: ";
		for (int c = 0; c < wszystkie[4].stos.getTop(); c++)
		{
			cout << tab[4][c];
			cout << ' ';
		}
		cout << endl;

		if (k < 6)
		{
			return false;
		}
		cout << "black cards values: ";
		for (int c = 0; c < wszystkie[5].stos.getTop(); c++)
		{
			cout << tab[5][c];
			cout << ' ';
		}
		cout << endl;

		return false;
	}
	else 
	{
		cout << "The values of cards of all colors are identical:";
		cout << endl;
		for (int i = 0; i < wszystkie[0].stos.getTop(); i++) 
		{
			cout << tab[0][i];
			cout << ' ';
		}
		return true;
	}
}
// 5

// 6
void wczytajDane6(int& player, int& n, int& e)
{
	int i = 0;
	char tab[256];

	cin.getline(tab, 256);

	while (tab[i] < 48 || tab[i] > 57)
	{
		++i;
	}
	player = (int)tab[i] - 48;

	cin.getline(tab, 256);
	i = 0;
	while (tab[i] < 48 || tab[i] > 57)
	{
		++i;
	}
	n = (int)tab[i] - 48;

	cin.getline(tab, 256);
	i = 0;
	while (tab[i] < 48 || tab[i] > 57)
	{
		++i;
	}
	e = (int)tab[i] - 48;
	++i;

	while (tab[i] > 47 && tab[i] < 58)
	{
		e = e * 10;
		e = e + (int)tab[i] - 48;
		++i;
	}
}

bool checkWritePlayers(int n, int player, Gracz* gracze) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		if ((gracze[i].reka.getTop() == gracze[i + 1].reka.getTop())|| 
			(gracze[i].reka.getTop() == gracze[i + 1].reka.getTop() + 1 && player != i+2)) 
		{
			continue;
		}
		else 
		{
			if (gracze[i].reka.getTop() + 1 == gracze[i + 1].reka.getTop() && player == i+2) 
			{
				continue;
			}
			else 
			{
				cout << "The number of players cards on hand is wrong";
				cout << endl;
				return false;
			}
		}
	}
	return true;
}

bool checkWriteColorPile(int k, Kociol* kocioly) 
{
	int ilosc;
	char kol;
	bool tf = true;
	for (int i = 0; i < k; i++) 
	{
		ilosc = kocioly[i].stos.getTop();
		kol = 0;

		for (int j = 0; j < ilosc; j++)
		{
			if (kocioly[i].stos.getCard(j).getKolor() != 'g') 
			{
				if ((kol != 0) && (kol != kocioly[i].stos.getCard(j).getKolor())) 
				{
					cout << "Two different colors were found on the ";
					cout << i + 1;
					cout << " pile";
					cout << endl;
					tf = false;
					break;
				}
				else 
				{
					kol = kocioly[i].stos.getCard(j).getKolor();
				}
			}
		}
	}
	return tf;
}

bool checkWriteValuePile(int k, Kociol* kocioly, int e)
{
	int ilosc;
	int val;
	bool tf = true;
	for (int i = 0; i < k; i++)
	{
		ilosc = kocioly[i].stos.getTop();
		val = 0;

		for (int j = 0; j < ilosc; j++)
		{
			val = val + kocioly[i].stos.getCard(j).getWartosc();
			
			if (val > e) 
			{
				cout << "Pile number ";
				cout << i + 1;
				cout << " should explode earlier";
				cout << endl;
				tf = false;
				break;
			}
		}
	}
	return tf;
}

// 6

// 7
//a
int checkPileColor(Kociol* kocioly, int k, char kol) 
{
	int ileKart;
	for (int i = 0; i < k; i++) 
	{
		ileKart = kocioly[i].stos.getTop();

		for (int j = 0; j < ileKart; j++) 
		{
			if (kol == kocioly[i].stos.getCard(j).getKolor()) 
			{
				return i;
			}
			else if (kocioly[i].stos.getCard(j).getKolor() != 'g') 
			{
				break;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		ileKart = kocioly[i].stos.getTop();

		for (int j = 0; j < ileKart; j++)
		{
			if (kocioly[i].stos.getCard(j).getKolor() != 'g')
			{
				break;
			}
			if (j == ileKart - 1) 
			{
				return i;
			}
		}
	}
	return -1;
}

void putTopCardOnPile(int& player, Gracz* gracze, Kociol* kocioly, int k, int n) 
{
	int wart, pileNumb;
	char kol;
	//n = gracze[player - 1].reka.getTop(); //?
	wart = gracze[player - 1].reka.getCard(0).getWartosc();
	kol = gracze[player - 1].reka.getCard(0).getKolor();
	Karta* karta1 = new Karta(kol, wart);

	if (kol != 'g')
		pileNumb = checkPileColor(kocioly, k, kol);
	else
		pileNumb = 0;

	kocioly[pileNumb].stos.push(*karta1);
	gracze[player - 1].reka.repair();
	++player;
	if (player > n) 
	{
		player = 1;
	}
}

void wypisz7(Gracz* Gracze, int n, int player, int k, int e, Kociol* kocioly)
{
	cout << "active player = " << player << endl;
	cout << "players number = " << n << endl;
	cout << "explosion threshold = " << e << endl;

	for (int i = 1; i < n + 1; i++)
	{
		cout << i << " player hand cards: ";
		Gracze[i - 1].reka.allCards();
		cout << endl;

		cout << i << " player deck cards: ";
		Gracze[i - 1].odrzucone.allCards();
		cout << endl;
	}

	for (int i = 1; i < k + 1; i++)
	{
		cout << i << " pile cards: ";
		kocioly[i - 1].stos.allCards();
		cout << endl;
	}
}
//a

//b
void explosion(int pileNumb, Kociol* kocioly, Gracz* gracze, int player, int n)
{
	int ileKart, wart, kol;
	player = player - 2;
	if (player <= 0) 
	{
		player = n + player;
	}

	ileKart = kocioly[pileNumb].stos.getTop();

	for (int i = 0; i < ileKart; i++)
	{
		wart = kocioly[pileNumb].stos.getCard(i).getWartosc();
		kol = kocioly[pileNumb].stos.getCard(i).getKolor();
		Karta* karta1 = new Karta(kol, wart);

		gracze[player].odrzucone.push(*karta1);
	}

	for (int i = 0; i < ileKart; i++)
	{
		kocioly[pileNumb].stos.pop();
	}
}

bool checkPileValue(int pileNumber, int e, Kociol* kocioly)
{
	int ileKart, val = 0;
	ileKart = kocioly[pileNumber].stos.getTop();

	for (int i = 0; i < ileKart; i++) 
	{
		val = val + kocioly[pileNumber].stos.getCard(i).getWartosc();

		if (val > e) 
		{
			return false;
		}
	}
	return true;
}

void putTopCardOnPileAndCheck(int& player, Gracz* gracze, Kociol* kocioly, int k, int n, int e)
{
	int wart, pileNumb;
	char kol;
	//n = gracze[player - 1].reka.getTop(); //?
	wart = gracze[player - 1].reka.getCard(0).getWartosc();
	kol = gracze[player - 1].reka.getCard(0).getKolor();
	Karta* karta1 = new Karta(kol, wart);

	if (kol != 'g')
		pileNumb = checkPileColor(kocioly, k, kol);
	else
		pileNumb = 0;

	kocioly[pileNumb].stos.push(*karta1);
	gracze[player - 1].reka.repair();
	++player;
	if (player > n)
	{
		player = 1;
	}

	if (!checkPileValue(pileNumb, e, kocioly))
	{
		explosion(pileNumb, kocioly, gracze, player, n);
	}
}

//b
// 7

// 8
void initTab(Gracz* gracze, int n, int k)
{
	int ileOdrzucil;
	for (int i = 0; i < n; i++) 
	{
		ileOdrzucil = gracze[i].odrzucone.getTop();
		gracze[i].kolorOdrzucony = new int[k];

		for (int j = 0; j < ileOdrzucil; j++)
		{
			gracze[i].kolorOdrzucony[j] = 0;
		}

		for (int j = 0; j < ileOdrzucil; j++) 
		{
			if (gracze[i].odrzucone.getCard(j).getKolor() == 'b')
			{
				gracze[i].kolorOdrzucony[0]++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'r')
			{
				gracze[i].kolorOdrzucony[1]++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'v')
			{
				gracze[i].kolorOdrzucony[2]++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'y')
			{
				gracze[i].kolorOdrzucony[3]++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'w')
			{
				gracze[i].kolorOdrzucony[4]++;
			}
			else if (gracze[i].odrzucone.getCard(j).getKolor() == 'l')
			{
				gracze[i].kolorOdrzucony[5]++;
			}
			else
				gracze[i].ileG++;
		}
	}
}

void setOdpornosciPkt(Gracz* gracze, int n, int k, int* odpornosc)
{
	int ileKart;
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (int z = 0; z < k; z++)
		{
			if (flag == 1) 
			{
				break;
			}
			for (int j = 0; j < n; j++)
			{
				if (gracze[i].kolorOdrzucony[z] <= gracze[j].kolorOdrzucony[z] && i != j)
					break;
				else if (j == n - 1)
				{
					odpornosc[z] = i + 1;
					gracze[i].setPkt(-gracze[i].kolorOdrzucony[z]);
					flag = 1;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) 
	{
		ileKart = gracze[i].odrzucone.getTop();
		gracze[i].setPkt(gracze[i].getPkt() + ileKart + gracze[i].ileG);
	}
}

void wypisz8(int* odpornosc, int k, int n, Gracz* gracze)
{
	for (int i = 0; i < k; i++) 
	{
		if (odpornosc[i] != 0) 
		{
			cout << "Na kolor ";
			if (i == 0) 
			{
				cout << "blue ";
			}
			else if (i == 1)
			{
				cout << "red ";
			}
			else if (i == 2)
			{
				cout << "violet ";
			}
			else if (i == 3)
			{
				cout << "yellow ";
			}
			else if (i == 4)
			{
				cout << "white ";
			}
			else if (i == 5)
			{
				cout << "black ";
			}
			cout << "odporny jest gracz ";
			cout << odpornosc[i];
			cout << endl;
		}
	}

	for (int i = 0; i < n; i++) 
	{
		cout << "Wynik gracza ";
		cout << i + 1;
		cout << " = ";
		cout << gracze[i].getPkt();
		cout << endl;
	}
}
// 8

int main()
{
	//zmienne 1 (podstawowe)
	int k = 0, g, gv, o, *taliaKoloru, buf, ileZiel;
	Karta *taliaCala;
	//zmienne 1 (podstawowe)

	//zmienne 2 (dodatkowe)
	int player = 1, n;
	Gracz* gracze;
	//zmienne 2 (dodatkowe)

	//zmienne 3b (dodatkowe)
	Kociol* kocioly;
	//zmienne 3b (dodatkowe)

	//zmienne 4a
	Karta kartaZiel('b', 2);  //tworzenie pojedynczej karty (wartosci ini nie maja znaczenia)
	//zmienne 4a

	//zmienne 4b i 5
	Karty* wszystkie; // [0] - nieb, itp
	//zmienne 4b i 5

	//zmienne 6 i 7
	int e;
	bool state1, state2, state3;
	//zmienne 6 i 7

	// zmienne 8
	//int* odpornosc;
	// zmienne 8

	// WCZYTAJ DANE 
	//wczytajDane1(k, g, gv, o);
	//wczytajDane2(k, g, gv, o, n);
	//wczytajDaneGetLine3(player, n);
	wczytajDane6(player, n, e);
	// WCZYTAJ DANE


	// LOKOWANIE PAMIECI 1
	//taliaKoloru = new int[o];
	//taliaCala = new Karta[o * k + g];
	gracze = new Gracz[n];
	// LOKOWANIE PAMIECI 1

	wczytajStanGetLine1(player, n, gracze, k);

	// LOKOWANIE PAMIECI 2
	kocioly = new Kociol[k];
	wszystkie = new Karty[k];
	//odpornosc = new int[k];

	/*
	for (int i = 0; i < k; i++) 
	{
		odpornosc[i] = 0;
	}
	*/
	// LOKOWANIE PAMIECI 2

	//wczytajStanGetLine2(k, kocioly);

	// TWORZENIE 
	//tworzTalie(k, g, gv, o, taliaKoloru, buf, taliaCala);
	//wypiszTalie(k, g, o, taliaCala);
	//rozdajTalie(gracze, n, taliaCala, k, g, o);
	ileZiel = greenCards(gracze, n, kartaZiel, k, kocioly);
	//countCards(gracze, n, k, kocioly, wszystkie);
	//colorCards(gracze, n, k, kocioly, wszystkie);
	// TWORZENIE

	// 6 
	state1 = checkWritePlayers(n, player, gracze);
	state2 = checkWriteColorPile(k, kocioly);
	state3 = checkWriteValuePile(k, kocioly, e);

	if (state1 == true && state2 == true && state3 == true) 
	{
		cout << "Current state of the game is ok";
	}
	// 6

	// 7
	//a
	//putTopCardOnPile(player, gracze, kocioly, k, n);
	//a
	//b
	//putTopCardOnPileAndCheck(player, gracze, kocioly, k, n, e);
	//b
	// 7

	/*
	//8
	initTab(gracze, n, k);
	setOdpornosciPkt(gracze, n, k, odpornosc);
	
	//8
	*/

	// WYPISYWANIE
	wypiszGreen(ileZiel, kartaZiel);
	//wypiszCards(k, wszystkie);
	//wypiszGiK(gracze, n, player, k);
	//wypiszStan1(n, gracze);
	//wypiszStan2(k, kocioly);
	//sortwypiszColorCards(wszystkie, k);
	//wypisz7(gracze, n, player, k, e, kocioly);
	//wypisz8(odpornosc, k, n, gracze);
	// WYPISYWANIE
		

	//ZWALNIANIE PAMIECI
	//delete[] taliaKoloru;
	//delete[] taliaCala;
	delete[] gracze;
	//ZWALNIANIE PAMIECI
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
