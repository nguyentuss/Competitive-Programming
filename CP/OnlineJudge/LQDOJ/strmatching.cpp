#include <iostream>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string a , b;

int main() {
	boost;

	getline(cin , a);
	getline(cin , b);
	a=" "+a;

	int x = a.find(b);

	while (x<(int)a.size())
	{
		cout << x << " " ;
		a[x]=' ';
		x = a.find(b);
	}
	return 0;
}