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
		cout << "PROGRAM DO NAUKI JÊZYKA ANGIELSKIEGO" << endl << endl;
		cout << "[1] Dodaj wyra¿enie" << endl;
		cout << "[2] Usuñ wyra¿enie" << endl;
		cout << "[3] Wyœwietl wszystkie wyra¿enia" << endl;
		cout << "[4] Tryb nauki" << endl;
		cout << "[0] Wyjœcie z programu" << endl << endl;
		cout << "Twój wybór: ";
		
		while (1)
		{
			cin >> choose;
			if (!cin.fail() && choose <= 4 && choose >= 0) break;
			else
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "ERROR! Z³y wybór. Twój ponowny wybór: ";
			}
		}

		if (choose == 1) dictionary.add();
		else if (choose == 2) dictionary.remove();
		else if (choose == 3) dictionary.print();
		else if (choose == 4) dictionary.learn();
	}
}