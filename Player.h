#include <string>
#include <iostream>
using namespace std;
class Player {
	public:
		void Wisielec(string& wisielecStr, int mistakes) const;
		void UsedChars(string& used, char shot);
		bool IsChar(char ch, int length);
		void MakeOwnLetterT();
		void ClearBufor() const;
		void Stop() const;
	private:
		bool usedChar = false;
		char possibleT[26];
};