#include <iostream>
#include <stdio.h> 
#include <random>
#include <fstream>
#include "Word.h"
#include "Player.h"

class Game {
	public:
		void Play(int category);
		void Categories();
		void Menu();
		void Stats();
		void incrementWin();
		void incrementLoss();
	private:
		Word word;
		Player player;
		int choice;
		int played = 0;
};
