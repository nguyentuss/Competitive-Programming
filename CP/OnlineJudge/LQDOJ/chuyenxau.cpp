#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>

using namespace std;

map <char , char> counted;
string str;
char u , v;

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	int n , m; cin >> n >> m;
	cin >> str;
	for (int i = 'a' ; i <= 'z' ; i++) counted[(char) i] = (char) i; 
	for (int i = 0 ; i < m; i++) {
		cin >> u >> v;
		counted[v] = u;
		counted[u] = v;
	}
	for (int i = 0 ; i < (int) str.size() ; i++) cout << counted[str[i]];


	return 0;
}