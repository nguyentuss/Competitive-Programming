#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a , b;

	getline(cin,a);
	getline(cin,b);
	cout << abs((int) a.size() - (int) b.size());


	return 0;
}