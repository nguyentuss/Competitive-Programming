#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <long long > v;
map <long long  , long long > m;


int main() {
	boost;
	long long  n , x , a; cin >> n >> x;

	for (long long  i = 0 ; i < n; i++) {
		cin >> a;
		v.push_back(a);
		m[a] ++;
	}

	long long  ans = 0;

	for (long long  i = 0 ; i < n; i++) {
		long long  y = x - v[i];
		if (y == v[i]) ans += m[y] * (m[y] - 1) / 2;
		else ans += m[y] * m[v[i]];
		m[y] = 0;
		m[v[i]] = 0;
	}

	cout << ans;


	return 0;
}