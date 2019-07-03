#include "Phrase.h"

// konstruktor
Phrase::Phrase(string _english, string _polish, int _countOfMaster, int _countOfViews)
	: countOfMaster(_countOfMaster)
	, countOfViews(_countOfViews)
{
	english = _english;
	polish = _polish;
}

// akcesory get
string Phrase::getEnglish()
{
	return english;
}
string Phrase::getPolish()
{
	return polish;
}
int Phrase::getCountOfMaster()
{
	return countOfMaster;
}
int Phrase::getCountOfViews()
{
	return countOfViews;
}

// akcesory set
void Phrase::setCountOfViews(int _count)
{
	countOfViews = _count;
}