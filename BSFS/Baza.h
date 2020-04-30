#pragma once
#include<algorithm>
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
#include<algorithm>
#include<limits>

using namespace std;

class Baza
{
protected:
	string tytul, gatunek;
	int rok_prod;
	double ocena;
	bool obs;
	//	fstream sejf;
public:
	Baza();
	~Baza();
	virtual void wypisz() = 0;
	virtual void zapisz() = 0;
	double dajocene() { return ocena; }
	string dajtytul() { return tytul; }
	string dajgatunek() { return gatunek; }
	int dajrok() { return rok_prod; }
	void obserwuj() { obs = true; }
	void nieobserwuj() { obs = false; }
	bool dajobs() { return obs; }
	void ustawtytul(string t);
	void ustawgatunek(string t);
	void ustawrok(int t);
	void ustawocene(double t);

};

