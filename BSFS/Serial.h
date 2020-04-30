#pragma once
#include "Baza.h"

using namespace std;

class Serial :	public Baza
{
protected:
	int sezony;
public:
	Serial(string, string, int, int, double, bool);
	Serial(const Serial &serial);
	~Serial();
	virtual void wypisz();
	Serial zamien(Serial &x);
	int dajsezony() { return sezony; }
	void ustawsezony(int s);
	void kopiuj(Serial x);
	void zapisz();
};

