#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("timmin.inp","r",stdin);
#define fo freopen("timmin.out","w",stdout);
#define ll long long

vector <int> m;

bool check(ll z) {
	vector <int> n;
	while (z != 0) {
		ll k = z % 10;
		n.push_back(k);
		z /= 10;
	}
	sort(n.begin(),n.end());
	for (int i = 0 ; i <(int) n.size() ; i++) 
		if (m[i] != n[i]) return false;
	return true;
}

int main (){
	boost;
	fi;fo;
	ll x ; cin >> x;
	ll y = x;
	while (y != 0) {
		ll k = y % 10;
		m.push_back(k); 
		y /= 10;
	}
	sort(m.begin(),m.end());
	for (int i = x + 1 ; i <= 999999 ; i ++) {
		if (check(i) == true) {
			cout << i;
			return 0;
		}
	}
	cout << 0;


	return 0;
}