#pragma once
#include "pch.h"
#include "PulaStreamow.h"
#include<string>

/*void PulaStreamow::ile_w_bazie()
{
	vector<Stream>::iterator it = lista.begin();
	rozmiar = obserwowane = 0;
	//int j = 0;
	for (it; it != lista.end(); it++, rozmiar++)	if (it->dajobs()) obserwowane++;
	//rozmiar = j;
}*/

void PulaStreamow::wyswietl()
{
	vector<Stream>::iterator it = lista.begin();
	for (it; it != lista.end(); it++)	it->wypisz();
}

void PulaStreamow::laduj()
{
	int i = 0;
	string a, k, d, g, m, o;
	odczyt.open("Streamy.txt");
	getline(odczyt, a, '\n');
	rozmiar = atoi(a.c_str());
	a = {};
	for (i; i < rozmiar; i++)
	{
		getline(odczyt, a, ';');
		while (a == "\n") { a = {}; getline(odczyt, a, ';'); }
		getline(odczyt, k, ';');
		getline(odczyt, d, ';');
		getline(odczyt, g, ';');
		getline(odczyt, m, ';');
		getline(odczyt, o, '\n');
		Stream nowy = *new Stream(a, k, atoi(d.c_str()), atoi(g.c_str()), atoi(m.c_str()), atoi(o.c_str()));
		this->operator+=(nowy);
	}
	odczyt.close();
}

void PulaStreamow::zapisz()
{
	this->ile_w_bazie();
	zapis.open("Streamy.txt", ios::out | ios::trunc);
	zapis << rozmiar << '\n';
	zapis.close();
	vector<Stream>::iterator it = lista.begin();
	for (it; it != lista.end(); it++)	it->zapisz();
}

Stream PulaStreamow::dodaj_stream()
{
	string a, k;
	int d, g, m;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Wprowadz dane streamu ponizej\n\Autor: ";

	getline(cin, a);
	cout << "Kategoria: ";
	cin.clear();
	cin >> k;
	cout << "Dzien tygodnia ( 1 - poniedzialek, 2 - wtorek, 3 - sroda, ... ):\n";
	cin.clear();
	cin >> d;
	cout << "Pelna godzina rozpoczecia (np. 9 lub 12): ";
	cin.clear();
	cin >> g;
	cout << "Ile minut po pe³nej godzinie? (np. 0, 2, lub 54)\n";
	cin.clear();
	cin >> m;
	cin.clear();
	Stream nowy = *new Stream(a, k, d, g, m, 0);
	system("cls");
	cout << "\n\n\t\tDodac do obserwowanych?\n\n" <<
		"\t\t\t |1| - Tak\t|0| - Nie\n\n" <<
		"\t\t\t\tWybor: ";
	if (getchar() == '1') nowy.obserwuj(true);
	else if (getchar() == '0') cout << "\nNie to nie\n";
	else
	{
		cout << "\n\t\tNo to obserwujemy!";
		nowy.obserwuj(true);
	}

	return nowy;
}

void PulaStreamow::czysc()
{
	lista.clear();
}

PulaStreamow::PulaStreamow()
{
}

PulaStreamow::~PulaStreamow()
{
}

string PulaStreamow::ile_czasu()
{
	//int day, hour, min;
	
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	int nast, pop = 0, dzisiaj, wcze, poz;
	bool mam = false;
	string nastepny, poprzedni;
	vector<Stream>::iterator it = lista.begin();

	if (lt.wDayOfWeek == 0)			//			jest dzisiaj niedziela
	{
		wcze = poz = dzisiaj = 7 * 24 * 60 + lt.wHour * 60 + lt.wMinute;
	}
	else wcze = poz = dzisiaj = lt.wDayOfWeek * 24 * 60 + lt.wHour * 60 + lt.wMinute;
	for (it; it != lista.end(); it++)
	{
		pop = it->daj_dzien() * 24 * 60 + it->daj_godzine() * 60 + it->daj_minuty();
		if (pop < wcze) { wcze = pop; poprzedni = it->dajtytul(); mam = true; }
		else if (pop > poz) { poz = pop; nastepny = it->dajtytul(); }
	}
	if (poz > dzisiaj)
	{
		poz -= dzisiaj;
		cout << "Najblizszy stream autora " << nastepny << " odbedzie sie za " << poz / (60 * 24) << " dni " << (poz - 24 * 60 * (poz / (60 * 24))) / 60 << "godzin " << poz % 60 << " minut\n";
		return nastepny;
	}
	
	if (mam)
	{
		wcze += 7 * 24 * 60 - dzisiaj;
		cout << "Najblizszy stream autora " << poprzedni << " odbedzie sie za " << wcze / (60 * 24) << " dni " << (wcze - 24 * 60 * (wcze / (60 * 24))) / 60 << "godzin " << wcze % 60 << " minut\n";
		return poprzedni;
	}


	/*
	if (lt.wDayOfWeek == 0)					// Jest niedziela
	{
		nast = ((7 * 24) + lt.wHour) * 60 + lt.wMinute;
		for (it; it != lista.end(); it++)
		{
			pop = ((7 * 24) + it->daj_godzine()) * 60 + it->daj_minuty();
			if (it->daj_dzien() == 7 && pop > nast)			//			Cos jest pozniej w niedziele
			{
				nast = pop;
				pom = it->dajtytul();
				mam = true;
			}
			
		}
		if (mam)	//Cos jest w niedziele
		{
			nast -= (7 * 24 * 60 + lt.wHour * 60 + lt.wMinute);
			cout << "Najblizszy stream autora " << pom << " odbedzie sie za " << nast / 60 << "godzin " << nast % 60 << " minut\n";
			return pom;
		}
		pop = 0;								//					W niedziele juz nic nie ma , ale jest niedziela
		for (it = lista.begin(); it != lista.end(); it++)
		{
			pop = (((it->daj_dzien()) * 24) + (it->daj_godzine())) * 60 + it->daj_minuty();
			if (pop < nast)
			{
				nast = pop;
				pom = it->dajtytul();
				mam = true;
			}
		}
		
		cout << "Najblizszy stream autora " << pom << " odbedzie sie za " << nast / (60 * 24) << " dni " << nast / 60 << "godzin " << nast % 60 << " minut\n";
		return pom;
	}
	else										//					NIE NIEDZIELA
	{
		nast = ((lt.wDayOfWeek * 24) + lt.wHour) * 60 + lt.wMinute;
		for (it = lista.begin(); it != lista.end(); it++)
		{
			pop = ((it->daj_dzien() * 24) + it->daj_godzine()) * 60 + it->daj_minuty();
			if (pop > nast)
			{
				nast = pop;
				pom = it->dajtytul();
				mam = true;
			}
		}
		if(mam)	
		{
			cout << "Najblizszy stream autora " << pom << " odbedzie sie za " << nast / (60 * 24) << "dni" << nast / 60 << "godzin " << nast % 60 << " minut\n";
			return pom;
		}
		pop = 0;								//					Szukamy w nastepnym tygodniu
		for (it = lista.begin(); it != lista.end(); it++)
		{
			pop = ((it->daj_dzien() * 24) + it->daj_godzine()) * 60 + it->daj_minuty();
			if (pop < nast)
			{
				nast = pop;
				pom = it->dajtytul();
				mam = true;
			}
		}
		cout << "Najblizszy stream autora " << pom << " odbedzie sie za " << nast / (60 * 24) << " dni " << nast / 60 << "godzin " << nast % 60 << " minut\n";
		return pom;

	}
	*/
	//day = lt.wDayOfWeek;
	return "Nie znaleziono";
}

Stream PulaStreamow::szukaj(string aut)
{
	vector<Stream>::iterator it = lista.begin();
	for (it; it != lista.end(); it++)
	{
		if (it->dajtytul() == aut) return (*it);
	}
}