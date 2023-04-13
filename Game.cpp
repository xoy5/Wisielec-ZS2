#include "Game.h"
using namespace std;

void Game::Play(int category)
{
	player.MakeOwnLetterT();
	string codeword;
	word.RandomCode(codeword, category);
	cout << codeword;

	string categoryString = "Nieznane";
	word.PrintCategory(categoryString, category);


	string wisielecStr = "\n\n\n\n\n";
	string usedChars;

	string hiddenCode;
	word.Hide(codeword, hiddenCode);

	char shot;
	int mistakes = 0;

	string lenStr;
	int length;

	bool endGame = false;
	do {
		system("cls");
		cout << "Kategoria: " << categoryString << endl;
		cout << wisielecStr << "\n\n";
		cout << hiddenCode << '\n' << '\n';
		cout << "Uzyte znaki: " << usedChars << endl; //<< codeword << endl; 
		do {
			cout << "Podaj litere: ";
			cin >> shot;
			if (shot >= 97)
				shot -= 32;
			lenStr = "";
			lenStr.push_back(shot);
			length = lenStr.length();
		} while ( !( player.IsChar( shot, length ) ) );

		// Update values
		if( ! ( word.Check(shot, codeword, hiddenCode ) ) )
			mistakes++;

		player.Wisielec(wisielecStr, mistakes);

		player.UsedChars(usedChars, shot);

		if (mistakes == 10)
			endGame = true;
		else
		{
			if (word.End(hiddenCode))
				endGame = true;
		}

	} while (!endGame);

	if (mistakes == 10)
	{
		mistakes++;
		player.Wisielec(wisielecStr, mistakes);
		incrementLoss();
		word.Loss(wisielecStr);
		player.ClearBufor();
		player.Stop();
	}
	else
	{
		word.Win(wisielecStr);
		incrementWin();
		player.ClearBufor();
		player.Stop();
	}
	Menu();
}

void Game::Categories()
{
	system("cls");
	cout << "------------------------------\n";
	cout << "- 1. Sport		     -\n";
	cout << "- 2. Programowanie           -\n";
	cout << "- 3. Gry		     -\n";
	cout << "- 4. Jedzenie		     -\n";
	cout << "- 0. Wroc do Menu	     -\n";
	cout << "------------------------------\n";

	cout << "Wybor :";
	cin >> choice;

	while (!(0 <= choice && choice <= 4))
	{
		cout << "Wybor (podaj poprawna liczbe z zakresu 0 do 4): ";
		cin >> choice;
	}

	if (choice == 0)
		Menu();
	else
		Play(choice - 1);
}

void Game::Menu()
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> randomCategory(0, 3);

	system("cls");
	cout << "------------------------------\n";
	cout << "- 1. Graj (Losowa Kategoria) -\n";
	cout << "- 2. Kategorie               -\n";
	cout << "- 3. Statystyki              -\n";
	cout << "- 0. Zakoncz	             -\n";
	cout << "//     ---------             -\n";
	cout << "//     |       |	     -\n";
	cout << "//     |       O	     -\n";
	cout << "//     |      /|\\	     -\n";
	cout << "//     |      / \\	     -\n";
	cout << "//  __/ \\__		     -\n";
	cout << "-		             -\n";
	cout << "-	      ZS2 OStrzeszow -\n";
	cout << "------------------------------\n";
	cout << "Wybor: ";
	if (played++)
		player.ClearBufor();
	cin >> choice;

	while (!(0 <= choice && choice <= 3))
	{
		cout << "Wybor (podaj poprawna liczbe): ";
		cin >> choice;
	}

	switch (choice)
	{
		case 1:
			Play(randomCategory(rng));
			break;
		case 2:
			Categories();
			break;
		case 3:
			Stats();
			break;
		default: return;
	}
}

void Game::Stats()
{
	system("cls");
	ifstream file;
	file.open("stats.txt");
	int a, b;
	file >> a >> b;

	cout << "Twoje statystyki: \nWygrane: " << a << "\nPrzegrane :" << b << "\nWinRate: " << static_cast<double>(a) / (a + b) * 100 << "%\n\nWcisnij przycisk + enter aby wyjsc: ";
	player.ClearBufor();
	player.Stop();
	Menu();
}

void Game::incrementWin() 
{
	std::fstream file("stats.txt", std::ios::in | std::ios::out);

	if (file.is_open()) {
		int win, loss;
		file >> win >> loss;
		win++;

		file.seekg(0, std::ios::beg);
		file << win << " " << loss;
		file.close();
	}
	else {
		std::cout << "Nie uda³o siê otworzyæ fileu." << std::endl;
	}
}

void Game::incrementLoss() 
{
	std::fstream file("stats.txt", std::ios::in | std::ios::out);

	if (file.is_open()) {
		int win, loss;
		file >> win >> loss;
		loss++;

		file.seekg(0, std::ios::beg);
		file << win << " " << loss;
		file.close();
	}
	else {
		std::cout << "Nie uda³o siê otworzyæ fileu." << std::endl;
	}
}