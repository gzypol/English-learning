#include "Dictionary.h"

#include <time.h>

// akcesory set
void Dictionary::setCountOfViews(int _count)
{
	countOfViews = _count;
}

// metoda wczytująca wyrażenia z pliku
void Dictionary::load()
{
	ifstream file;
	file.open("base.txt");

	if (!file.is_open())
	{
		cout << "ERROR! Nie udało się otworzyć pliku" << endl;
	}

	while (!file.eof())
	{
		string line;
		getline(file, line);

		//if (file.eof()) break;

		int found1 = line.find_first_of(';');
		int found2 = line.find_last_of(';');

		if (found1 && found2 != string::npos)
		{
			string tempEnglish(line, 0, found1);
			string tempPolish(line, found1 + 1, found2 - (found1 + 1));
			string tempInt(line, found2 + 1, line.size() - found2 - 1);

			istringstream tempInt1(tempInt);
			int tempCountOfMaster;
			tempInt1 >> tempCountOfMaster;

			if (!tempInt1.fail())
			{
				if (tempCountOfMaster > 0)
				{
					Phrase tempPhrase(tempEnglish, tempPolish, tempCountOfMaster - 1, countOfViews);
					phrases.push_back(tempPhrase);
				}
			}
		}
	}

	file.close();
}

// metoda zapisująca wyrażenia do pliku
void Dictionary::save()
{
	ofstream file;
	file.open("base.txt", fstream::trunc);

	if (!file.is_open())
	{
		cout << "ERROR! Nie udało się otworzyć pliku" << endl;
	}

	for (int i = 0; i < phrases.size(); ++i)
	{
		file << phrases[i].getEnglish() << ';' << phrases[i].getPolish() << ';';
		file << phrases[i].getCountOfMaster() << endl;
	}

	file.close();
}

// metoda sprawdzająca czy wyrażenie jest już w słowniku
bool Dictionary::isUsed(string _english)
{
	for (int i = 0; i < phrases.size(); ++i)
	{
		if (_english == phrases[i].getEnglish()) return true;
	}
	return false;
}

// konstruktor i destruktor
Dictionary::Dictionary()
{
	cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
	cout << "Wybierz ile razy chcesz wyświetlać każde słowo: ";

	int tempInt;
	while (1)
	{
		cin >> tempInt;
		if (cin.fail() || tempInt <= 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "ERROR! Zły wybór. Twój ponowny wybór: ";
		}
		else break;
	}

	setCountOfViews(tempInt);
	load();
}
Dictionary::~Dictionary()
{
	save();
}

// metoda drukująca wszystkie wyrażenia
void Dictionary::print()
{
	cout << phrases.size();
	if (phrases.size() % 10 == 0)
	{
		for (int i = 0; i < phrases.size() / 10; ++i)
		{
			system("cls");
			cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
			for (int j = 0; j < 10; ++j)
			{
				cout << "[" << j << "] Wyrażenie: " << phrases[10 * i + j].getEnglish() << endl;
				cout << "Polskie tłumaczenie: " << phrases[10 * i + j].getPolish() << endl;
			}
			cout << endl << "Strona " << i + 1 << "/" << phrases.size() / 10;
			cout << " Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}
	}
	else
	{
		for (int i = 0; i < 1 + (phrases.size() / 10); ++i)
		{
			system("cls");
			cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
			if (phrases.size() - i * 10 < 10)
			{
				for (int j = 0; j < phrases.size() - i * 10; ++j)
				{
					cout << "[" << j << "] Wyrażenie: " << phrases[10 * i + j].getEnglish() << endl;
					cout << "Polskie tłumaczenie: " << phrases[10 * i + j].getPolish() << endl;
				}
			}
			else
			{
				for (int j = 0; j < 10; ++j)
				{
					cout << "[" << j << "] Wyrażenie: " << phrases[10 * i + j].getEnglish() << endl;
					cout << "Polskie tłumaczenie: " << phrases[10 * i + j].getPolish() << endl;
				}
			}
			cout << endl << "Strona " << i + 1 << "/" << 1 + phrases.size() / 10;
			cout << " Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}
	}
}

// metoda dodająca wyrażenie
void Dictionary::add()
{
	cin.ignore(256, '\n');
	while (1)
	{
		system("cls");
		cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
		cout << "Podaj wyrażenie po angielsku lub wpisz 0 by wyjść: ";
		string tempEnglish;
		getline(cin, tempEnglish);
		if (tempEnglish == "0") break;
		
		if (isUsed(tempEnglish))
		{

			cout << "ERROR! Już masz to wyrażenie w słowniku" << endl;
			cout << "Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}

		else
		{
			cout << "Podaj tłumaczenie wyrażenia: ";
			string tempPolish;
			getline(cin, tempPolish);

			Phrase tempPhrase(tempEnglish, tempPolish, COUNTOFMASTER, countOfViews);
			phrases.push_back(tempPhrase);
		}
	}
}

// metoda usuwająca wyrażenie
void Dictionary::remove()
{
	cin.ignore(256, '\n');
	while (1)
	{
		system("cls");
		cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
		cout << "Podaj wyrażenie po angielsku, które chcesz usunąć lub wpisz 0 by wyjść: ";
		string tempEnglish;
		getline(cin, tempEnglish);
		if (tempEnglish == "0") break;

		int size = phrases.size();

		for (int i = 0; i < phrases.size(); ++i)
		{
			if (tempEnglish == phrases[i].getEnglish())
			{
				phrases.erase(phrases.begin() + i);
				break;
			}
		}

		if (size == phrases.size())
		{
			system("cls");
			cout << "Nie udało się znaleźć wyrażenia " << tempEnglish << " w słowniku" << endl;
			cout << "Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}

		else
		{
			system("cls");
			cout << "Pomyślnie usunięto wyrażenie " << tempEnglish << endl;
			cout << "Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}
	}
}

// metoda służąca do nauki
void Dictionary::learn()
{
	srand(time(NULL));

	vector<Phrase> learning = phrases;

	cin.ignore(256, '\n');
	
	while (learning.size() > 0)
	{
		system("cls");
		int random = rand() % learning.size();
		cout << "PROGRAM DO NAUKI JĘZYKA ANGIELSKIEGO" << endl << endl;
		cout << "Wylosowane wyrażenie: " << learning[random].getEnglish() << endl;
		cout << "Pozostała ilość wyświetleń wyrażenia: " << learning[random].getCountOfViews() << endl;
		cout << "Podaj tłumaczenie lub wybierz 0 by wyjść: ";
		string tempString;
		getline(cin, tempString);
		if (tempString == "0") break;

		if (tempString == learning[random].getPolish())
		{
			learning[random].setCountOfViews(learning[random].getCountOfViews() - 1);
			if (learning[random].getCountOfViews() == 0) learning.erase(learning.begin() + random);
			cout << endl << "Dobrze!" << endl;
			cout << "Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}
		else
		{
			learning[random].setCountOfViews(learning[random].getCountOfViews() + 1);
			cout << endl << "Źle!" << endl;
			cout << "Wpisz cokolwiek by przejść dalej: ";
			string tempString;
			cin >> tempString;
			cin.ignore(256, '\n');
		}
	}

	system("cls");
	cout << "Skończyłeś naukę" << endl;
	cout << "Wpisz cokolwiek by przejść dalej: ";
	string tempString;
	cin >> tempString;
	cin.ignore(256, '\n');
}