#pragma once

#include "Phrase.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#define COUNTOFMASTER 5

using namespace std;

class Dictionary
{
private:
	int countOfViews;		// ustawienie ile razy ma być wyświetlane wyrażenie
	vector<Phrase> phrases;	// dynamiczna tablica wyrażeń

	// akcesory set
	void setCountOfViews(int _count);

	// metoda wczytująca wyrażenia z pliku
	void load();

	// metoda zapisująca wyrażenia do pliku
	void save();

	// metoda sprawdzająca czy wyrażenie jest już w słowniku
	bool isUsed(string _english);

public:
	// konstruktor i destruktor
	Dictionary();
	~Dictionary();

	// metoda drukująca wszystkie wyrażenia
	void print();

	// metoda dodająca wyrażenie
	void add();

	// metoda usuwająca wyrażenie
	void remove();

	// metoda służąca do nauki
	void learn();
};

