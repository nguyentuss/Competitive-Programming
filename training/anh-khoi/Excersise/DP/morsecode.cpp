#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("morsecode.inp","r",stdin);
#define fo freopen("morsecode.out","w",stdout);

string Morse [100] = {".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--", "..--.."}; string Letter [100] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "Stop", ",", "?"};
int main(){
	boost;
	fi;fo;
	string s;

	while (cin >> s) {
		if (s == "/") cout << " ";
		else
		for (int i = 0 ; i < 36 ; i++) {
			if (Morse[i] == s) cout << Letter[i];
		}

	}
	return 0;
}