#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll sup[1000007] , sdown[1000007] , disup[1000007] , disdown[1000007];
vector <ll> v(1000007);

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	sup[1] = sdown[n] = disup[1] = disdown[n] = 0;
	for (int i = 2 ; i <= n ;i++) { 
		sup[i] = sup[i - 1] + v[i - 1];
		disup[i] = disup[i - 1] + v[i - 1] + sup[i - 1];
	}
	for (int i = n  - 1 ; i >= 1 ; i --) {
		sdown[i] = sdown[i + 1] + v[i + 1];
		disdown[i] = disdown[i + 1] + v[i + 1] + sdown[i + 1];
	}

	for (int i = 1 ; i <= n ; i++) 
		cout << disup[i] << " ";
	cout << '\n';
	for (int i = 1 ; i <= n ; i++) 
		cout << disdown[i] << " ";
	cout << '\n';

	ll ans = ULLONG_MAX;
	int pos;
	for (int i = 1 ; i <= n ; i ++) {
		if (ans >= (disup[i] + disdown[i])) {
			ans = disup[i] + disdown[i];
			pos = i;
		}
	}
	cout << pos;

	return 0;
}