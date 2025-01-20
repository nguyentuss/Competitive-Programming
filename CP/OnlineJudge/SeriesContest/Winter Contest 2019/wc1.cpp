#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) (1e5 + 7)
#define M (ll) (68718952446LL)
#define div (ll) (1e6)

ll n;
ll L[MAX_N] , R[MAX_N];
vector <ll> v(MAX_N);

void init() {
	for (int i = 1 ; i <= n ; i++) {
		L[i] = R[i] = 1LL;
	}
	return;
}


ll multi(ll a , ll b) {
	return (a*(b/div)%M*div%M + a*(b%div)%M)%M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		init();
		for (int i = 1 ; i <= n ; i++) 
			cin >> v[i];
		L[0] = 1LL , R[n + 1] = 1LL;
		int tmp = n + 1;
		for (int i = 1 ; i <= n ; i++) {
			L[i] = multi(L[i - 1] , v[i]);
			R[tmp - i] = multi(R[tmp - i + 1] , v[tmp - i]);
		}
		for (int i = 1 ; i <= n ; i++) {
			cout << (ll) multi(L[i - 1] , R[i + 1]) << " ";
		}
		cout << '\n';
	}


	return 0;
}