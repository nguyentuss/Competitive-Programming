#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

#define MAX_N (int) (2e5 + 7)
#define inf (int) (1e9 + 7)
#define int long long

int a[MAX_N] , b[MAX_N];
int P1[MAX_N][100] , P2[MAX_N][100]; 
int n;

void init() {
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
			P2[i][j] = inf;
			P1[i][j] = inf;
		}
	}
}

void rmq() {
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
			P1[i][j] = min(P1[i][j - 1] , P1[i + (1 << (j - 1))][j - 1]);
			P2[i][j] = min(P2[i][j - 1] , P2[i + (1 << (j - 1))][j - 1]);
		}
	} 
}

int get1(int l , int r) {
	int k = log2(r - l + 1);
	return min(P1[l][k] , P1[r - (1 << k) + 1][k]);
}

int get2(int l , int r) {
	int k = log2(r - l + 1);
	return min(P2[l][k] , P2[r - (1 << k) + 1][k]);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("bieudo.inp","r",stdin);
	//freopen("bieudo.out","w",stdout);
	cin >> n;
	init();
	for (int i = 1 ; i <= n ;i ++) {
		cin >> a[i] >> b[i];
		P1[i][0] = a[i];
		P2[i][0] = b[i];
	}
	rmq();
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			ans = max(ans , get1(i , j)*get2(i , j)*(j - i + 1));
		}
	}
	cout << ans;
	return 0;
}