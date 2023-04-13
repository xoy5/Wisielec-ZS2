#include "Word.h"

void Word::RandomCode(string& codeword, int category)
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> randomSection(0, 2);

	codeword = categoriesT[category][randomSection(rng)];
}

void Word::PrintCategory(string& categoryString, int category)
{
	if (category == 0)
		categoryString = "Sport";
	if (category == 1)
		categoryString = "Programowanie";
	if (category == 2)
		categoryString = "Gry";
	if (category == 3)
		categoryString = "Jedzenie";
}

void Word::Loss(string& wisielecStr) const
{
	system("cls");
	cout << wisielecStr << '\n';
	cout << "PRZEGRALES :( \n Wcisnij przycisk + enter aby przejsc do menu: ";
}

void Word::Win(const string& wisielecStr) const
{
	system("CLS");
	cout << wisielecStr << endl;
	cout << "\nGratulacje udalo Ci sie odgadnac haslo \n\nfor(int i = 0; i < 10; i++){\n\tcout << (Odglosy Klaskania);\n}\n\n";
	cout << "Wcisnij przycisk + enter aby przejsc do menu: ";
}

void Word::Hide(string& code, string& hiddenCode)
{
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] != '\ ')
			hiddenCode += "_";
		else
			hiddenCode += "\ ";
	}
}

bool Word::Check(char& shot, string& codeword, string& hiddenCode)
{
	bool changed = false;

	for (int i = 0; i < codeword.size(); i++)
	{
		if (codeword[i] == shot)
		{
			hiddenCode[i] = shot;
			changed = true;
		}
	}

	return changed;
}

bool Word::End(string& hiddenCode)
{
	for (int i = 0; i < hiddenCode.size(); i++)
	{
		if (hiddenCode[i] == '_')
			return false;
	}

	return true;
}
