#include <bits/stdc++.h>

using namespace std;

long long nim(long long x) {
	return (x == 0 || x == 2)?0:(x - 1)%2 + 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int g; cin >> g;
	while(g--) {
		long long n , m , k;
		cin >> n;
		long long ans = 0;
		int countone = 0;
		for (int i = 1 ; i <= n ; i++) {
			cin >> m >> k;
			ans ^= nim(m);
		}
		if (countone == n) {
			cout << ((countone & 1)?"BOB":"BEN") << '\n';
		}
		else {
			cout << (ans?"BOB":"BEN") << '\n';
		}

	}
	return 0;
}