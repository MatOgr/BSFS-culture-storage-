#pragma once
//#include "Serial.h"
//#include "Film.h"
#include<vector>
#include<iterator>

template <class Q> class Pula
{
protected:
	fstream zapis, odczyt;
	int rozmiar, obserwowane;
public:
	vector<Q> lista;
	void operator -=(string tyt);
	Q operator+=(Q tyn);
	void wyswobs();
	int daj_rozmiar() { return rozmiar; }
	int daj_obserwowane() { return obserwowane; }
	void ile_w_bazie();
};

template <class Q> void Pula<Q>::ile_w_bazie()
{
	typename vector<Q>::iterator it = lista.begin();
	rozmiar = 0;
	for (it; it != lista.end(); it++, rozmiar++)	if (it->dajobs()) obserwowane++;
}

template <class Q> void Pula<Q>::wyswobs()
{
	typename vector<Q>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++)
	{
		if (it->dajobs())	it->wypisz();
	}
}

template <class Q> Q Pula<Q>::operator+=(Q tyn)
{
	bool dodany = true;
	typename vector<Q>::iterator it = lista.begin();
	for ( it; it != lista.end(); it++)
	{
		if (it->dajtytul() == tyn.dajtytul()) {
			cout << "Ten tekst kultury ju¿ znajduje siê w bazie\n";
			dodany = false;
			break;
		}
	}
	if (dodany) {
		cout << "Udalo sie dodac nowe dzieuo\n";
		lista.push_back(tyn);
	}
	return lista.back();
}

template <class Q> void Pula<Q>::operator-=(string tyt)
{
	bool usunieto = false;
	int p, id=0;
	typename vector<Q>::iterator it = lista.begin();
	for (it; it != lista.end(); it++, id++)
	{
		if (it->dajtytul() == tyt) 
		{ 
			it->wypisz();
			cout << "\nCzy chcesz usunac to dzielo?\n" <<
				"|1| - Tak \t\t |0| - Nie\n";
			cin >> p;
			if (p == 1) { 
				lista.erase(it); 
				cout << "Udauo sie usunac dzieuo o podanym tytule\n"; 
				usunieto = true; 
				break; 
			}
			else if (p == 0) { 
				cout << "\n\n\t\tNie to nie\n\n"; 
				usunieto = true; 
				break; 
			}
		}
	}
	if (!usunieto) {
		cout << "W bazie nie ma dzieua o podanym tytule\n";
	}
}
