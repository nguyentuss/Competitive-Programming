#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define ll long long

vector<bool> v(MAX_N , true);

void sieve() {
	for (int i = 2 ; i * i < MAX_N; i++) {
		if (v[i]) {
			for (int j = i * i ; j < MAX_N ; j+= i) {
				v[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int t; cin >> t;
	while (t--) {
		ll n ; cin >> n;
		ll sqr = sqrt(n);
		if (sqr*sqr == n && v[sqr]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}