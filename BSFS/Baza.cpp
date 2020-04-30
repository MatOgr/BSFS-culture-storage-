#include "pch.h"
#include "Baza.h"


Baza::Baza()
{
}

Baza::~Baza()
{
}

void Baza::ustawgatunek(string t)
{
	gatunek = t;
}

void Baza::ustawocene(double t)
{
	ocena = t;
}

void Baza::ustawtytul(string t)
{
	tytul = t;
}

void Baza::ustawrok(int t)
{
	rok_prod = t;
}