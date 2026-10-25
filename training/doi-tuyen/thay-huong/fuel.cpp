#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define mod (int) (1e9 + 7)
#define int long long

int f[MAX_N];
vector <int> v;
int sum[MAX_N];
int a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("fuel.inp","r",stdin);
	freopen("fuel.out","w",stdout);
	int n , m , l; cin >> n >> m >> l;
	for (int i = 2; i <= (n + 1) ; i++) {
		cin >> a[i];
	}
	a[n + 2] = m;
	a[1] = 0;
	f[1] = 1;
	sum[1] = 1;
	v.push_back(0);
	for (int i = 2 ; i <= (n + 2) ; i++) {
		int pos = lower_bound(v.begin() , v.end() , a[i] - l) - v.begin();
		f[i] = (sum[i - 1] - sum[pos] + mod)%mod;
		(sum[i] = sum[i - 1] + f[i])%=mod;
		v.push_back(a[i]);
	}
	cout << f[n + 2]%mod;
	return 0;
}