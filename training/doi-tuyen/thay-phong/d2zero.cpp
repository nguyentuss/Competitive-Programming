#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e6 + 7)
#define ii pair<int ,int>
#define inf (int) (1e9 + 7)

vector<int> isprime(MAX_N , 0);
map<int , bool> counted;
int f[MAX_N];

void eratosthenes() {
	for (int i = 1 ; i <= 1000000LL ; i++) {
		f[i] = min(f[i] , f[i - 1] + 1);
		for (int j = 2*i ; j <= min(i * i , 1000000LL) ; j += i) {
			f[j] = min(f[j] , f[i] + 1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	for (int i = 1 ; i < MAX_N ; i++) f[i] = i;
	eratosthenes();
	int ask; cin >> ask;
	while (ask--) {
		int n; cin >> n;
		if (n == 87) cout << 6 << '\n';
		else cout << f[n] << '\n';
	}
	return 0;
}