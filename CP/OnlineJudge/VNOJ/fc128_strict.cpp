#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define mod (int) (1e9 + 7)

map <int , int> m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x;
		cin >> x;
		m[x] ++;
	}
	long long total = 1;
	for (auto e : m) {
		total = (total%mod*(e.second + 1)%mod)%mod;
	}
	cout << total;
	return 0;
}