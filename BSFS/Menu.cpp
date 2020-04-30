#pragma once
#include "pch.h"
#include "Menu.h"

int Menu::Opcje(int moz)
{JECZE:
	int wyb;
	bool ok = false;
	//cout << "Wybierz opcjê: ";

	try
	{
		while (!ok)
		{
			cin >> wyb;
			if (wyb<0 || wyb > moz) throw 1;
			else if (cin.fail())	throw 1;
			else ok = true;
		}
	}
	catch (int prob)
	{
		cout << "Blad " << prob <<
			" - wprowadzono niepoprawne dane (wpisz numer opcji - cyfre od 0 do " << moz << ")" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		goto JECZE;
	}
	return wyb;
}

void Menu::start()
{
	cout << "\t\t===========================\n" <<
		"\t\t|                          |\n" <<
		"\t\t|      Witaj w bazie       |\n" <<
		"\t\t|                          |\n" <<
		"\t\t===========================\n"  ;
	kontynuuj();
}

void Menu::kontynuuj()
{
	cin.clear();
	cout << "\n\n\n\tAby kontynuowac, wcisnij dowolny klawisz\n";
	_getch();
}

void Menu::blad()
{
	system("cls");
	cout << "Coœ posz³o nie tak - skontaktuj siê z meteorologiem\n\n\n";
	//menu.kontynuuj();
	system("PAUSE");
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
