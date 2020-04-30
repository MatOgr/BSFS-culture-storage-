#pragma once
#include "Pula.h"

class PulaFilmow :	public Pula<Film>
{
//protected:
	//int rozmiar, obserwowane;
public:
	//void ile_w_bazie();
	void wyswietl();
	void laduj();
	void zapisz();
	void ranking();
	Film dodajfilm();
	void czysc();
	PulaFilmow();
	~PulaFilmow();
};

