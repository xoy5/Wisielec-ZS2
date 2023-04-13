#include "Player.h"

void Player::Wisielec(string& wisielecStr, int mistakes) const
{
	switch (mistakes)
	{
		case 1:
			wisielecStr = "\n\n\n\n\n__ / \\__";
			break;
		case 2:
			wisielecStr = "\n   |\n   |\n   |\n   |\n__/ \\__";
			break;
		case 3:
			wisielecStr = "   --------\n   |\n   |\n   |\n   |\n__/ \\__";
			break;
		case 4:
			wisielecStr = "   --------\n   |      |\n   |\n   |\n   |\n__/ \\__";
			break;
		case 5:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |\n   |\n__/ \\__";
			break;
		case 6:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |      |\n   |\n__/ \\__";
			break;
		case 7:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |     /|\n   |\n__/ \\__";
			break;
		case 8:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |     /|\\\n   |\n__/ \\__";
			break;
		case 9:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |     /|\\\n   |     /\n__/ \\__";
			break;
		case 10:
			wisielecStr = "   --------\n   |      |\n   |      O\n   |     /|\\\n   |     / \\\n__/ \\__";
			break;
	}
}

void Player::UsedChars(string& used, char shot)
{
	if (!usedChar)
		usedChar = true;
	else
		used += ", ";

	used.push_back(shot);

}

bool Player::IsChar(char ch, int length)
{
	if(length == 1)
	{ 
		for (int i = 0; i < 26; i++)
		{
			if (ch == possibleT[i])
			{
				possibleT[i] = 0;
				return true;
			}
		}
	}

	ClearBufor();

	cout << "BLAD: A-Z lub UZYTY ZNAK\n";
	return false;
}

void Player::MakeOwnLetterT()
{
	for (int i = 0; i < 26; i++)
	{
		possibleT[i] = i + 65;
	}
}

void Player::Stop() const
{
	char nothing;
	cin >> nothing;
}

void Player::ClearBufor() const
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
