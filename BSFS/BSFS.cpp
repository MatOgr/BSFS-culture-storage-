#pragma once
#include "pch.h"
#include "Menu.h"
#include<iostream>
#include<ctime>

int main()
{
	/*string tytul, gatunek;
	int co, rokprodukcji, pom;
	float ocena;*/
	
	Menu menu;
	string pom;
	double f;
	bool lec = true, juz;
	int I, II, III, co = 0, p;
	PulaSeriali listaseriali;
	PulaFilmow listafilmow;
	PulaStreamow listastreamow;
	vector<Stream>::iterator it_stream;
	vector<Film>::iterator it_film;
	vector<Serial>::iterator it_serial;

	menu.start();
	listaseriali.laduj();
	listafilmow.laduj();
	listastreamow.laduj();
	listaseriali.ile_w_bazie();
	listafilmow.ile_w_bazie();
	listastreamow.ile_w_bazie();
	system("cls");
	if (listastreamow.daj_rozmiar() != 0)	listastreamow.ile_czasu();
	system("PAUSE");

	while (lec)
	{
		GLOWNE:
		system("cls");
		cout << "Wybierz opcje: \n" <<
			"|1| - Wyswietl zawartosc bazy\n"		<<
			"|2| - Dodaj nowy tekst kultury\n"		<<
			"|3| - Edytuj elementy bazy lub dodaj do obserwowanych\n" <<
			"|4| - Usun wybrane dzieuo\n"		<<
			"|0| - Wyjdz z programu\n";
		//co = menu.Opcje(3);
		I = menu.Opcje(4);
		switch (I)				
		{
		case 1:										//Wyswietlanie bazy
			WYSW:
			system("cls");
			cout << "Wybierz kategorie:\n" <<
				"|1| - Seriale\n" <<
				"|2| - Filmy\n" <<
				"|3| - Streamy\n" <<
				"|0| - <-\n";		// Menu glowne
			II = menu.Opcje(3);
			switch (II)
			{
			case 1:								//		SERIALE
				system("cls");
				cout << "Co chesz zobaczyc?\n" <<
					"|1| - Ranking seriali \n" <<
					"|2| - Biblioteka seriali\n" <<
					"|3| - Obserwowane seriale\n" <<
					"|0| - <- \n";		// Wybor kategorii
				III = menu.Opcje(3);
				switch (III)
				{
				case 1:											//		Ranking seriali
					system("cls");
					if (listaseriali.daj_rozmiar() == 0)	cout << "\n\t\tBaza seriali jest pusta\n\n";
					else
					{					
						cout << "\t  RANKING SERIALI\n-----------------------------------\n\n";
						listaseriali.ranking();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 2:											//		Wszystkie seriale
					system("cls");
					if (listaseriali.daj_rozmiar() == 0)	cout << "\n\t\tBaza seriali jest pusta\n\n";
					else
					{
						cout << "\t  BIBLIOTEKA SERIALI\n-----------------------------------\n\n";
						listaseriali.wyswietl();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 3:											//		Obserwowane seriale
					system("cls");
					if (listaseriali.daj_obserwowane() == 0)	cout << "\n\t\tNie obserwujesz zadnego serialu\n\n";
					else
					{
						cout << "\t  OBSERWOWANE\n-----------------------------------\n\n";
						listaseriali.wyswobs();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 0:
					goto WYSW;
					break;

				default:
					menu.blad();
					break;
				}
				break;
				////////////////////////////////////////
			case 2:								//		FILMY
				system("cls");
				cout << "Co chesz zobaczyc?\n" <<
					"|1| - Ranking filmow \n" <<
					"|2| - Biblioteka filmow\n" <<
					"|3| - Obserwowane filmow\n" <<
					"|0| - <- \n";		// Wybor kategorii
				III = menu.Opcje(3);
				switch (III)
				{
				case 1:											//		Ranking filmow
					system("cls");
					if (listafilmow.daj_rozmiar() == 0)	cout << "\n\t\tBaza filmow jest pusta\n\n";
					else
					{
						cout << "\t  RANKING filmow\n-----------------------------------\n\n";
						listafilmow.ranking();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 2:											//		Wszystkie filmy
					system("cls");
					if (listafilmow.daj_rozmiar() == 0)	cout << "\n\t\tBaza filmow jest pusta\n\n";
					else
					{
						cout << "\t  BIBLIOTEKA FILMOW\n-----------------------------------\n\n";
						listafilmow.wyswietl();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 3:											//		Obserwowane filmy
					system("cls");
					if (listafilmow.daj_obserwowane() == 0)	cout << "\n\t\tNie obserwujesz zadnego filmu\n\n";
					else
					{
						cout << "\t  OBSERWOWANE\n-----------------------------------\n\n";
						listafilmow.wyswobs();
						//menu.kontynuuj();
						system("PAUSE");
					}
					break;

				case 0:
					goto WYSW;
					break;

				default:
					menu.blad();
					break;
				}
				break;

			case 3:		////////////////////////////		STREAMY
				system("cls");
				cout << "Co chesz zobaczyc?\n" <<
					"|1| - Najblizszy stream\n" <<
					"|2| - Biblioteka streamow\n" <<
					"|3| - Obserwowane streamy\n" <<
					"|0| - <- \n";		// Wybor kategorii
				III = menu.Opcje(3);
				switch (III)
				{
				case 1:											//		najblizszy stream
					system("cls");
					if (listastreamow.daj_rozmiar() == 0)	cout << "\n\t\tBaza streamow jest pusta\n\n";
					else	(listastreamow.szukaj(listastreamow.ile_czasu())).wypisz();
					system("PAUSE");
					break;

				case 2:											//		Wszystkie streamy
					system("cls");
					if (listastreamow.daj_rozmiar() == 0)	cout << "\n\t\tBaza streamow jest pusta\n\n";
					else	listastreamow.wyswietl();
					system("PAUSE");
					break;

				case 3:											//		Obserwowane streamy
					system("cls");
					if (listastreamow.daj_obserwowane() == 0)	cout << "\n\t\tNie obserwujesz zadnego streamu\n\n";
					else	listastreamow.wyswobs();
					system("PAUSE");
					break;

				case 0:
					goto WYSW;
					break;

				default:
					menu.blad();
					break;
				}
				break;
			case 0:
				goto GLOWNE;
				break;

			default:
				menu.blad();
				break;
			}
			break;
		
		case 2:										//		Dodawanie nowych
			//DOD:
			system("cls");
			cout << 
				"Co chcesz dodac?\n"	<<
				"|1| - Serial\n"		<<
				"|2| - Film\n"		<<
				"|3| - Stream\n"	<<
				"|0| - <-\n";			//Menu glowne
			switch (menu.Opcje(3))
			{
			case 1:												//		Serial
				listaseriali += listaseriali.dodajserial();
				listaseriali.zapisz();
				//cout << "\n\nDodano\n";
				//menu.kontynuuj();
				system("PAUSE");
				break;

			case 2:
				listafilmow += listafilmow.dodajfilm();
				listafilmow.zapisz();
				system("PAUSE");
				break;

			case 3:
				listastreamow += listastreamow.dodaj_stream();
				listastreamow.zapisz();
				system("PAUSE");
				break;

			case 0:
				goto GLOWNE;
				break;

			default:
				menu.blad();
				break;
			}
			break;
		
		case 3:										//		Edycja lub obserwowanie
			//EDYT:
			system("cls");
			cout << "Wybierz kategorie:\n" <<
				"|1| - Serial\n" <<
				"|2| - Film\n" <<
				"|3| - Stream\n" <<
				"|0| - <-\n";			//Menu glowne
			switch (menu.Opcje(3))
			{
			case 1:										//		Edycja seriali
				juz = false;
				it_serial = listaseriali.lista.begin();
				cout << "Podaj tytul: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				for (it_serial; it_serial != listaseriali.lista.end(); it_serial++)
				{
					if (it_serial->dajtytul() == pom)
					{
						while (!juz)
						{
							system("cls");
							it_serial->wypisz();
							cout << "Co chcesz zmienic?\n\n" <<
								"|1| - Tytul\n" <<
								"|2| - Gatunek\n" <<
								"|3| - Rok produkcji\n" <<
								"|4| - Sezony\n" <<
								"|5| - Srednia ocen\n";
							if (it_serial->dajobs())	cout << "|6| - Przestan obserwowac\n";
							else	cout << "|6| - Obserwuj\n";
							cout << "|0| - Menu glowne\n";
							cin >> co;
							switch (co)
							{
							case 1:
								cout << "Podaj nowy tytul: ";
								cin.clear();
								cin.ignore(1000, '\n');
								getline(cin, pom);
								it_serial->ustawtytul(pom);
								break;

							case 2:
								cout << "Podaj nowy gatunek: ";
								cin.clear();
								cin.ignore(1000, '\n');
								getline(cin, pom);
								it_serial->ustawgatunek(pom);
								break;

							case 3:
								cout << "Podaj nowy rok produkcji: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> p;
								it_serial->ustawrok(p);
								break;

							case 4:
								cout << "Podaj nowa liczbe sezonow: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> p;
								it_serial->ustawsezony(p);
								break;

							case 5:
								cout << "Podaj nowa ocene: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> f;
								it_serial->ustawocene(f);
								break;

							case 6:
								if (it_serial->dajobs())	it_serial->nieobserwuj();
								else	it_serial->obserwuj();
								break;

							case 0:
								listaseriali.zapisz();
								juz = true;
								break;

							default:
								cout << "Cos nie tak przy edycji\n	";
								system("PAUSE");
								break;
							}
						}
					}
				}
				break;

			case 2:										//		Edycja filmow
				juz = false;
				it_film = listafilmow.lista.begin();
				cout << "Podaj tytul: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				for (it_film; it_film != listafilmow.lista.end(); it_film++)
				{
					if (it_film->dajtytul() == pom)
					{
						while (!juz)
						{
							system("cls");
							it_film->wypisz();
							cout << "Co chcesz zmienic?\n\n" <<
								"|1| - Tytul\n" <<
								"|2| - Gatunek\n" <<
								"|3| - Rok produkcji\n" <<
								"|4| - Dlugosc filmu\n" <<
								"|5| - Srednia ocen\n";
							if (it_film->dajobs())	cout << "|6| - Przestan obserwowac\n";
							else	cout << "|6| - Obserwuj\n";
							cout << "|0| - Menu glowne\n";
							cin >> co;
							switch (co)
							{
							case 1:
								cout << "Podaj nowy tytul: ";
								cin.clear();
								cin.ignore(1000, '\n');
								getline(cin, pom);
								it_film->ustawtytul(pom);
								break;

							case 2:
								cout << "Podaj nowy gatunek: ";
								cin.clear();
								cin.ignore(1000, '\n');
								getline(cin, pom);
								it_film->ustawgatunek(pom);
								break;

							case 3:
								cout << "Podaj nowy rok produkcji: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> p;
								it_film->ustawrok(p);
								break;

							case 4:
								cout << "Podaj nowa dlugosc filmu: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> p;
								it_film->ustawdlugosc(p);
								break;

							case 5:
								cout << "Podaj nowa ocene: ";
								cin.clear();
								cin.ignore(1000, '\n');
								cin >> f;
								it_film->ustawocene(f);
								break;

							case 6:
								if (it_film->dajobs())	it_film->nieobserwuj();
								else	it_film->obserwuj();
								break;

							case 0:
								listafilmow.zapisz();
								juz = true;
								break;

							default:
								cout << "Cos nie tak przy edycji\n	";
								system("PAUSE");
								break;
							}
						}
					}
				}
				break;

			case 3:										//		Edycja streamow
				juz = false;
				it_stream = listastreamow.lista.begin();
				cout << "Podaj autora: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				for (it_stream; it_stream != listastreamow.lista.end(); it_stream++)
				{
					if (it_stream->dajtytul() == pom)
					{
						while (!juz)
						{
							system("cls");
							it_stream->wypisz();
							cout << "Co chcesz zmienic?\n\n" <<
								"|1| - Autora\n" <<
								"|2| - Kategorie\n" <<
								"|3| - Dzien\n" <<
								"|4| - Godzine\n";
							if (it_stream->dajobs())	cout << "|5| - Przestan obserwowac\n";
							else	cout << "|5| - Obserwuj\n";
							cout << "|0| - Menu glowne\n";
							cin >> co;
							switch (co)
							{
							case 1:
								cout << "Podaj nowego autora: ";
								it_stream->ustaw_autora();
								break;

							case 2:
								cout << "Podaj nowa kategoria: ";
								it_stream->ustaw_kategorie();
								break;

							case 3:
								cout << "Podaj nowy dzien: ";
								it_stream->ustaw_dzien();
								break;

							case 4:
								it_stream->ustaw_czas();
								break;

							case 5:
								if (it_stream->dajobs())	it_stream->obserwuj(false);
								else	it_stream->obserwuj(true);
								break;

							case 0:
								listastreamow.zapisz();
								juz = true;
								break;

							default:
								cout << "Cos nie tak przy edycji\n	";
								system("PAUSE");
								break;
							}
						}
					}
				}
				break;

			case 0:
				goto GLOWNE;
				break;

			default:
				menu.blad();
				break;
			}
			break;

		case 4:												//		Usuwanie
			system("cls");
			cout << "Jaki element chcesz usunac?\n" <<
				"|1| - Serial\n" <<
				"|2| - Film\n" <<
				"|3| - Stream\n" <<
				"|0| - <-\n";			
			juz = false;
			switch (menu.Opcje(3))
			{
			case 1:										//		Serial
				system("cls");
				listaseriali.wyswietl();
				cout << "Podaj tytul: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				listaseriali -= pom;

				system("PAUSE");
				break;

			case 2:										//		Film
				system("cls");
				listafilmow.wyswietl();
				cout << "Podaj tytul: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				listafilmow -= pom;
				system("PAUSE");
				break;

			case 3:										//		Stream
				system("cls");
				listastreamow.wyswietl();
				cout << "Podaj autora: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, pom);
				listastreamow -= pom;
				system("PAUSE");
				break;

			case 0:
				goto GLOWNE;
				break;

			default:
				menu.blad();
				break;
			}
			break;

		case 0:										//Wujscie z programu
			system("cls");
			listafilmow.zapisz();
			listaseriali.zapisz();
			listastreamow.zapisz();
			cout << "\n\t\tNo to ten...DO WIDZENIA\n\n\n";
			lec = false;
			break;

		default:
			menu.blad();
			break;
		}
		//Sleep(2000);
	}
	
	listafilmow.czysc();
	listaseriali.czysc();
	listastreamow.czysc();

	return 0;
}