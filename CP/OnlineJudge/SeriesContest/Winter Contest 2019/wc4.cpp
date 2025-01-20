#include <bits/stdc++.h>

using namespace std;

#define M (ll) (1e9 + 7)
#define MAX_N (int) (1e3 + 7)
#define ll long long

//goi f[i][j] la so cach chia i so vao j nhom
// gia su a[i] nam rieng biet thi F[i][j] = F[i - 1][j - 1]
// gia su a[i] nam trong cac nhom j thi F[i][j] = F[i - 1][j]*j
// => F[i][j] = F[i - 1][j - 1] + F[i - 1][j]*j

ll F[MAX_N][MAX_N] , n;

void createDynamicProgramming() {
	F[0][0] = 1LL;
	for (ll i = 1 ; i <= 1000 ; i++) {
		for (ll j = 1 ; j <= i ; j++) {
			F[i][j] = (F[i - 1][j - 1] + F[i - 1][j]*j%M)%M;
		}
	}
	return;
}

int main() {
	//freopen("wc4.inp","r",stdin);
	//freopen("wc4.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	createDynamicProgramming();
	int t; cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0LL;
		for (int i = 1 ; i <= n ; i ++) {
			(ans += F[n][i]) %= M; 
		}
		cout << (ll) (ans%M) << '\n';
	}
	return 0;
}