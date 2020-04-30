#include "pch.h"
#include "PulaSeriali.h"

/*void quick_sort(int *tab, int lewy, int prawy)
{
	if (prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
		pivot = tab[(lewy + prawy) / 2];

	while (1)
	{
		while (pivot > tab[++i]);
		while (pivot < tab[--j]);
		if (i <= j)	swap(tab[i], tab[j]);
		else break;
	}

	if (j > lewy)
		quick_sort(tab, lewy, j);
	if (i < prawy)
		quick_sort(tab, i, prawy);
}

void PulaSeriali::ile_w_bazie()
{
	vector<Serial>::iterator it = lista.begin();
	rozmiar = 0;
	//int j = 0;
	for (it; it != lista.end(); it++, rozmiar++)	if(it->dajobs()) obserwowane++;
	//rozmiar = j;
}*/

void PulaSeriali::wyswietl()
{
	vector<Serial>::iterator it = lista.begin();
	for (it; it != lista.end(); it++)	it->wypisz();
}

void PulaSeriali::ranking()
{
	vector<Serial>::iterator it1 = lista.begin(), it2;
	
	for (it1; it1 != lista.end() - 1; it1++)
	{
		for (it2 = it1; it2 != lista.end(); it2++)
		{
			if (((it2->dajocene()) - (it1->dajocene()) > 0.001))	it1->zamien(*(it2));
		}
	}
	/*
	bool czeba = true;	int j = 0;
	do
	{
		czeba = false;
		for (it; it != lista.end() - 1; it++, j++)
		{
			if (((it->dajocene()) - ((it + 1)->dajocene())) < 0.001)
			{
				it->zamien(*(it + 1));

				czeba = true;
			}
		}
	} while (czeba);*/

	this->wyswietl();
}

void PulaSeriali::laduj()
{
	int i;
	string tyt, rok, gat, sez, ob, oc;
	odczyt.open("Seriale.txt");
	odczyt >> rozmiar;
	for (i = 0; i < rozmiar; i++)
	{
		getline(odczyt, tyt, ';');	tyt.erase(0, 1);
		getline(odczyt, gat, ';');
		getline(odczyt, rok, ';');
		getline(odczyt, sez, ';');
		getline(odczyt, oc, ';');
		getline(odczyt, ob, ';');
		Serial nowy = *new Serial(tyt, gat, atoi(rok.c_str()), atoi(sez.c_str()), atof(oc.c_str()), atoi(ob.c_str()));
		this->operator+=(nowy);
	}
	odczyt.close();
}

void PulaSeriali::zapisz()
{
	vector<Serial>::iterator it = lista.begin();
	this->ile_w_bazie();
	zapis.open("Seriale.txt", ios::out | ios::trunc);
	zapis << rozmiar << "\n";
	zapis.close();
	for (it; it != lista.end(); it++)	it->zapisz();
}

void PulaSeriali::czysc()
{
	lista.clear();
}

Serial PulaSeriali::dodajserial()
{
	string tyt, gat;
	int rok, sez;
	double oce;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Wprowadz dane serialu ponizej\n\nTytul: ";

	getline(cin, tyt);
	cout << "Gatunek: ";
	cin.clear();
	cin >> gat;
	cout << "Rok produkcji: ";
	cin.clear();
	cin >> rok;
	cout << "Sezony: ";
	cin.clear();
	cin >> sez;
	cout << "Srednia ocen: ";
	cin.clear();
	cin >> oce;
	cin.clear();
	Serial nowy = *new Serial(tyt, gat, rok, sez, oce, 0);
	system("cls");
	cout << "\n\n\t\tDodac do obserwowanych?\n\n" <<
		"\t\t\t |1| - Tak\t|0| - Nie\n\n" <<
		"\t\t\t\tWybor: ";
	if (getchar() == '1') nowy.obserwuj();
	else if (getchar() == '0') cout << "\nNie to nie\n";
	else
	{
		cout << "\n\t\tNo to obserwujemy!";
		nowy.obserwuj();
	}
	return nowy;

}
/*
void PulaSeriali::edycja()
{
	vector<Serial>::iterator it = lista.begin();
	string pom;
	int co = 0, p;
	double f;
	cout << "Podaj tytul: ";
	cin >> pom;
	for (it; it != lista.end(); it++)
	{
		if (pom == it->dajtytul())
		{
			while (!juz)
			{
				system("cls");
				it->wypisz();
				cout << "Co chcesz zmienic?\n\n" <<
					"|1| - Tytul\n" <<
					"|2| - Gatunek\n" <<
					"|3| - Rok produkcji\n" <<
					"|4| - Sezony\n" <<
					"|5| - Srednia ocen\n";
				if (it->dajobs())	cout << "|6| - Przestan obserwowac\n";
				else	cout << "|6| - Obserwuj\n";
				cout << "|0| - <-\n";
				cin >> co;
				switch (co)
				{
				case 1:
					cout << "Podaj nowy tytul: ";
					getline(cin, pom);
					it->wprowadztytul(pom);
					break;

				case 2:
					cout << "Podaj nowy gatunek: ";
					cin >> pom;
					it->wprowadzgatunek(pom);
					break;

				case 3:
					cout << "Podaj nowy rok produkcji: ";
					cin >> p;
					it->wprowadzrok(p);
					break;

				case 4:
					cout << "Podaj nowa liczbe sezonow: ";
					cin >> p;
					it->wprowadzsezony(p);
					break;

				case 5:
					cout << "Podaj nowa ocene: ";
					cin >> f;
					it->wprowadzocene(f);
					break;

				case 6:
					if (it->dajobs())	it->nieobserwuj();
					else	it->obserwuj();

				case 0:
					lista.zapisz();
				default:
					cout << "Cos nie tak przy edycji\n	";
					system("PASUE");
					break;
				}
			}
		}
	}
}*/

PulaSeriali::PulaSeriali()
{
}

PulaSeriali::~PulaSeriali()
{
}
