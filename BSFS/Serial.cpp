#include "pch.h"
#include "Serial.h"


Serial::Serial(string n = "-", string g = "-", int p = 0, int s = 0, double a = 0, bool o = false)
{
	tytul = n;
	gatunek = g;
	rok_prod = p;
	sezony = s;
	ocena = a;
	obs = o;
}

/////////////////			Destruktro
Serial::~Serial()
{
}

Serial::Serial(const Serial &serial)
{
	tytul = serial.tytul;
	gatunek = serial.gatunek;
	rok_prod = serial.rok_prod;
	sezony = serial.sezony;
	obs = serial.obs;
	ocena = serial.ocena;
}

void Serial::wypisz()
{
	cout << "\t" << tytul <<
		"\nGatunek: \t" << gatunek <<
		"\nRok produkcji: \t" << rok_prod <<
		"\nSezony: \t" << sezony <<
		"\nOcena: \t\t" << ocena <<
		"\nObserwujesz: \t";
	if (this->dajobs())	cout << "Tak";
	else	cout << "Nie";
	cout << "\n\n";
}

void Serial::zapisz()
{
	fstream zap;
	zap.open("Seriale.txt", ios::app);
	zap << tytul << ";" << gatunek << ";" <<
		rok_prod << ";" << sezony << ";" << ocena << ";" <<
		obs << ";\n";
	zap.close();
}

void Serial::kopiuj(Serial x)
{
	this->tytul = x.dajtytul();
	this->gatunek = x.dajgatunek();
	this->ocena = x.dajocene();
	this->obs = x.dajobs();
	this->rok_prod = x.dajrok();
	this->sezony = x.dajsezony();
}

Serial Serial::zamien(Serial &ten)
{
	int sez, rok;
	bool p;
	double oc;
	string tyt, gat;
	tyt = this->tytul;
	gat = this->gatunek;
	oc = this->ocena;
	sez = this->sezony;
	rok = this->rok_prod;
	p = this->obs;
	this->kopiuj(ten);
	ten.tytul = tyt;
	ten.ocena = oc;
	ten.gatunek = gat;
	ten.sezony = sez;
	ten.rok_prod = rok;
	ten.obs = p;
	return ten;
}

void Serial::ustawsezony(int s)
{
	sezony = s;
}