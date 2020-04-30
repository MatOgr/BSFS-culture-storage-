#pragma once
#include "Baza.h"
#include<ctime>
using namespace std;

class Stream
{
protected:
	string autor, kategoria;
	int dzien, godzina, minuty;
	bool obserwowany;

public:
	Stream(string, string, int, int, int, bool);
	Stream(const Stream &strim);
	~Stream();
	void obserwuj(bool);
	void ustaw_autora();
	void ustaw_kategorie();
	void ustaw_dzien();
	void ustaw_godzine();
	void ustaw_minuty();
	void ustaw_czas();
	void zapisz();
	void wypisz();
	void dajczas();
	bool dajobs() { return obserwowany; }
	string dajtytul() { return autor; }
	string daj_kategorie() { return kategoria; }
	int daj_dzien() { return dzien; }
	int daj_godzine() { return godzina; }
	int daj_minuty() { return minuty; }
	string jaki_dzien();
};

