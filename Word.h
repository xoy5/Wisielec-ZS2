#include <iostream>
#include <string>
#include <random>
using namespace std;
class Word {
    public:
        void RandomCode(string& codeword, int category);
		void PrintCategory(string& categoryString, int category);
		void Loss(string& wisielec) const;
		void Win(const string& wisielecStr) const;
		void Hide(string& code, string& hiddenCode);
		bool Check(char& shot, string& codeword, string&hiddenCode);
		bool End(string& hiddenCode);
    private:
		string categoriesT[4][3] = {
		{"TESTOSTERON", "WYCISKANIE LEZAC", "PUDZIANOWSKI"},
		{"CPP WYMIATA", "BRAK ZYCIA", "NO BITCHES"},
		{"SZACHY INTERNETOWE", "GTA SAN ANDREAS", "MINECRAFT"},
		{"KEBAB NA CIENKIM", "MAKARON Z SZPINAKIEM", "OBIAD MAMY"}
		};
};