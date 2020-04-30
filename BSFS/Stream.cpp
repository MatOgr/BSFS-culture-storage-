#include "pch.h"
#include "Stream.h"

void Stream::obserwuj(bool b)
{
	this->obserwowany = b;
}

void Stream::ustaw_autora()
{
	string pom;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, pom);
	this->autor = pom;
}

void Stream::ustaw_kategorie()
{
	string pom;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, pom);
	this->kategoria = pom;
}

void Stream::ustaw_dzien()
{
	cout << "Dzien tygodnia ( 1 - poniedzialek, 2 - wtorek, 3 - sroda, ... ):\n";
	int pom;
	cin.clear();
	cin >> pom;
	this->dzien = pom % 7;
}

void Stream::ustaw_godzine()
{
	cout << "\nPelna godzina rozpoczecia (np. 9 lub 12): ";
	int pom;
	cin.clear();
	//cin.ignore(1000, '\n');
	cin >> pom;
	this->godzina = pom;
}

void Stream::ustaw_minuty()
{
	cout << "\nIle minut po pe³nej godzinie? (np. 0, 2, lub 54)\n";
	int pom;
	cin.clear();
	//cin.ignore(1000, '\n');
	cin >> pom;
	this->minuty = pom;
}

void Stream::ustaw_czas()
{
	this->ustaw_godzine();
	this->ustaw_minuty();
}

Stream::Stream(string a, string k, int d, int g, int m, bool o)
{
	this->autor = a;
	this->kategoria = k;
	this->dzien = d;
	this->godzina = g;
	this->minuty = m;
	this->obserwowany = o;
}

Stream::Stream(const Stream &strim)
{
	autor = strim.autor;
	kategoria = strim.kategoria;
	dzien = strim.dzien;
	godzina = strim.godzina;
	minuty = strim.minuty;
	obserwowany = strim.obserwowany;
}

void Stream::zapisz()
{
	fstream zap;
	zap.open("Streamy.txt", ios::app);
	zap << autor << ";" << kategoria << ";" <<
		dzien << ";" << godzina << ";" << minuty << ";" <<
		obserwowany << "\n";
	zap.close();
}

string Stream::jaki_dzien()
{
	string dni[7] = { "Poniedziale","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela"};
	return dni[this->dzien - 1];
}

void Stream::dajczas()
{
	if (minuty < 10)	cout << godzina << ":0" << minuty;
	else cout << godzina << ":" << minuty;
}

void Stream::wypisz()
{
	cout << "\t" << autor <<
		"\nKategoria: \t" << kategoria <<
		"\nDzien: \t\t" << this->jaki_dzien() <<
		"\nGodzina: \t";
	dajczas();
	cout << "\nObserwujesz: \t";
	if (obserwowany) cout << "Tak\n\n";
	else cout << "Nie\n\n";
}

Stream::~Stream()
{
}
