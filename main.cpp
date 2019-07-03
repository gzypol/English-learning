#include "Dictionary.h"

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	system("chcp 1250 >nul");

	Dictionary dictionary;

	int choose = 1;

	while (choose != 0)
	{
		system("cls");
		cout << "PROGRAM DO NAUKI J�ZYKA ANGIELSKIEGO" << endl << endl;
		cout << "[1] Dodaj wyra�enie" << endl;
		cout << "[2] Usu� wyra�enie" << endl;
		cout << "[3] Wy�wietl wszystkie wyra�enia" << endl;
		cout << "[4] Tryb nauki" << endl;
		cout << "[0] Wyj�cie z programu" << endl << endl;
		cout << "Tw�j wyb�r: ";
		
		while (1)
		{
			cin >> choose;
			if (!cin.fail() && choose <= 4 && choose >= 0) break;
			else
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "ERROR! Z�y wyb�r. Tw�j ponowny wyb�r: ";
			}
		}

		if (choose == 1) dictionary.add();
		else if (choose == 2) dictionary.remove();
		else if (choose == 3) dictionary.print();
		else if (choose == 4) dictionary.learn();
	}
}