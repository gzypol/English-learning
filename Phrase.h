#pragma once

#include <string>

using namespace std;

class Phrase
{
private:
	string english;			// wyrażenie po angielsku
	string polish;			// polskie tłumaczenie
	int countOfMaster;		// ile razy się go uczyliśmy
	int countOfViews;		// zmienna która jest ustawiana dopiero przy odpalaniu słownika

public:
	// konstruktor
	Phrase(string _english, string _polish, int _countOfMaster, int _countOfViews);

	// akcesory get
	string getEnglish();
	string getPolish();
	int getCountOfMaster();
	int getCountOfViews();

	// akcesory set
	void setCountOfViews(int _count);
};