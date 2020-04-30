#pragma once
#include "Baza.h"

class Film :	public Baza
{
protected:
	int dlugosc;
public:
	Film(string, string, int, int, double, bool);
	Film(const Film &x);
	~Film();
	virtual void wypisz();
	virtual void zapisz();
	Film zamien(Film &x);
	int dajdlugosc() { return dlugosc; }
	void kopiuj(Film x);
	void ustawdlugosc(int d);
};

