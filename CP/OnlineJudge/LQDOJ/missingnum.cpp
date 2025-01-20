#include <bits/stdc++.h>

using namespace std;

map<int , int> counted;
map <int,int>::iterator it;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n  , m; cin >> n >> m;
	int x;
	for (int i = 0 ; i < n; i++){
		cin >> x;
		counted[x]++;
	} 
	for (int i = 0 ; i < (n - m) ; i++) {
		cin >> x;
		counted[x] --;
	}

	for (it = counted.begin() ; it != counted.end() ; it++) {
		for (int i = 0 ; i < it->second ; i++) cout << it -> first << " ";
	}
	return 0;
}