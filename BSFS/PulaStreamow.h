#pragma once
#include "Pula.h"
#include "Stream.h"

class PulaStreamow :
	public Pula<Stream>
{
public:
	void wyswietl();
	void laduj();
	void zapisz();
	//void ile_w_bazie();
	Stream dodaj_stream();
	void czysc();
	string ile_czasu();
	Stream szukaj(string aut);
	PulaStreamow();
	~PulaStreamow();
};

