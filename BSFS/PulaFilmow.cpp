#include "pch.h"
#include "PulaFilmow.h"

/*void PulaFilmow::ile_w_bazie()
{
	vector<Film>::iterator it = lista.begin();
	rozmiar = 0;
	for (it; it != lista.end(); it++, rozmiar++)	if (it->dajobs()) obserwowane++;
}*/

void PulaFilmow::wyswietl()
{
	vector<Film>::iterator it = lista.begin();
	for (it; it != lista.end(); it++)	it->wypisz();
}

void PulaFilmow::ranking()
{
	vector<Film>::iterator it = lista.begin(), it2;
	for (it; it != lista.end() - 1; it++)
	{
		for (it2 = it; it2 != lista.end(); it2++)
			if (((it2->dajocene()) - (it->dajocene())) > 0.001)
				it->zamien(*(it2));
	}
	this->wyswietl();
}

void PulaFilmow::laduj()
{
	int i;
	string tyt, rok, gat, dl, ob, oc;
	odczyt.open("Filmy.txt");
	odczyt >> rozmiar;
	for (i = 0; i < rozmiar; i++)
	{
		getline(odczyt, tyt, ';');	tyt.erase(0, 1);
		getline(odczyt, gat, ';');
		getline(odczyt, rok, ';');
		getline(odczyt, dl, ';');
		getline(odczyt, oc, ';');
		getline(odczyt, ob, ';');
		Film nowy = *new Film(tyt, gat, atoi(rok.c_str()), atoi(dl.c_str()), atof(oc.c_str()), atoi(ob.c_str()));
		this->operator+=(nowy);
	}
	odczyt.close();
}

void PulaFilmow::zapisz()
{
	vector<Film>::iterator it = lista.begin();
	this->ile_w_bazie();
	zapis.open("Filmy.txt", ios::out | ios::trunc);
	zapis << rozmiar << "\n";
	zapis.close();
	for (it; it != lista.end(); it++)	it->zapisz();
}

void PulaFilmow::czysc()
{
	lista.clear();
}

Film PulaFilmow::dodajfilm()
{
	string tyt, gat;
	int rok, dl;
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
	cout << "Dlugosc filmu: ";
	cin.clear();
	cin >> dl;
	cout << "Srednia ocen: ";
	cin.clear();
	cin >> oce;
	cin.clear();
	Film nowy = *new Film(tyt, gat, rok, dl, oce, 0);
	system("cls");
	cout << "\n\n\t\tDodac do obserwowanych?\n\n" <<
		"\t\t\t |1| - Tak\t|0| - Nie\n\n" <<
		"\t\t\t\tWybor: ";
	if (getchar() == '1') nowy.obserwuj();
	else if (getchar() == '0') cout << "\nNie to nie\n";
	else
	{
		cout << "\n\t\tNo to obserwujemy!\n\n";
		nowy.obserwuj();
	}
	return nowy;
}

PulaFilmow::PulaFilmow()
{
}

PulaFilmow::~PulaFilmow()
{
}
