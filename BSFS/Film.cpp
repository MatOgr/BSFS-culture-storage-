#include "pch.h"
#include "Film.h"


Film::Film(string n = "-", string g = "-", int d = 0, int p = 0, double a = 0, bool o = 0)
{
	tytul = n;
	gatunek = g;
	rok_prod = d;
	dlugosc = p;
	ocena = a;
	obs = o;
}

Film::Film(const Film &film)
{
	tytul = film.tytul;
	gatunek = film.gatunek;
	rok_prod = film.rok_prod;
	dlugosc = film.dlugosc;
	obs = film.obs;
	ocena = film.ocena;
}

Film::~Film()
{
}

void Film::wypisz()
{
	cout << "\t" << tytul <<
		"\nGatunek: \t" << gatunek <<
		"\nRok produkcji: \t" << rok_prod <<
		"\nDlugosc: \t" << dlugosc <<
		"\nOcena: \t\t" << ocena <<
		"\nObserwujesz: \t";
	if (this->dajobs())	cout << "Tak";
	else	cout << "Nie";
	cout << "\n===================================\n";
}

void Film::zapisz()
{
	fstream zap;
	zap.open("Filmy.txt", ios::app);
	zap << tytul << ";" << gatunek << ";" <<
		rok_prod << ";" << dlugosc << ";" << ocena << ";" <<
		obs << ";\n";
	zap.close();
}

void Film::kopiuj(Film x)
{
	this->tytul = x.dajtytul();
	this->gatunek = x.dajgatunek();
	this->ocena = x.dajocene();
	this->obs = x.dajobs();
	this->rok_prod = x.dajrok();
	this->dlugosc = x.dajdlugosc();
}

Film Film::zamien(Film &ten)
{
	int sez, rok;
	bool p;
	double oc;
	string tyt, gat;
	tyt = this->tytul;
	gat = this->gatunek;
	oc = this->ocena;
	sez = this->dlugosc;
	rok = this->rok_prod;
	p = this->obs;
	this->kopiuj(ten);
	ten.ustawtytul(tyt);
	ten.ocena = oc;
	ten.gatunek = gat;
	ten.dlugosc = sez;
	ten.rok_prod = rok;
	ten.obs = p;
	return ten;
}

void Film::ustawdlugosc(int d)
{
	dlugosc = d;
}