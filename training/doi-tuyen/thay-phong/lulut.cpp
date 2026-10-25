#include <bits/stdc++.h>

using namespace std;

struct seg {
	int t , d , p;
};

bool cmp(seg &a , seg &b) {
	return a.d < b.d;
}

seg v[107];
int f[107][2007];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("lulut.inp","r",stdin);
	//freopen("lulut.out","w",stdout);
	int n ; cin >> n; 
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i].t >> v[i].d >> v[i].p;
	}
	sort(v + 1 , v + 1 + n , cmp);
	for (int i = 1 ; i <= n ;i ++) f[0][i] = 0;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = v[i].d - 1; j >= 0 ; j--) {
			if (v[i].t > j) f[i][j] = f[i - 1][j];
			else f[i][j] = max(f[i - 1][j] , f[i-1][j-v[i].t] + v[i].p);
		}
	}
	int ans = INT_MIN;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 0 ; j <= v[i].d ; j++) {
			ans = max(ans , f[i][j]);
		}
	}
	cout << ans;
	return 0;
}