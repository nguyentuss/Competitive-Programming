#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)
#define int long long

int n;
long long p[23] = {0 , 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31  , 37};
long long res = LLONG_MAX;
long long f[20];

void calc(int i , long long ans , int counted) {
	if (counted > n) return;
	if (counted == n) res = min(res , ans);
	for (int j = 1 ; ; j ++) {
		if (ans*p[i] > res) break;
		ans *= p[i];
		if (ans < 0) break;
		calc(i + 1 , ans , counted*(j + 1)); 
	}
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
    freopen("spc2.inp","r",stdin);
    freopen("spc2.out","w",stdout);
	f[0] = 1;
	for (int i = 1 ; i <= 11 ; i++) {
		(f[i] = f[i - 1]*2)%=mod;
	}
	int t; cin >> t;
	while (t--) {
		res = LLONG_MAX;
		cin >> n;
		n = f[n];
		calc(1 , 1 , 1);
		cout << res%mod << '\n';
	}

	return 0;
}