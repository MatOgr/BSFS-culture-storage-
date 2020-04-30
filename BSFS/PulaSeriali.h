#pragma once
#include "Pula.h"

class PulaSeriali :	public Pula<Serial>
{
//protected:
	//int rozmiar, obserwowane;
public:
	void wyswietl();
	void laduj();
	void zapisz();
	void ranking();
	//void ile_w_bazie();
	Serial dodajserial();
	//void edycja();
	void czysc();
	PulaSeriali();
	~PulaSeriali();
};

