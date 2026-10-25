#include <bits/stdc++.h>

using namespace std;

#define MAX_P (int) (1e5 + 7)
#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e9 + 7)

vector<bool> prime(MAX_P , true);
set<int> pr;
int a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
int hang[MAX_N];
int cot[MAX_N];

void sieve() {
	prime[0] = false;
	prime[1] = false;
	for (int i = 2 ; i * i < MAX_P ; i++) {
		if (prime[i]) {
			for (int j = i * i ; j < MAX_P ; j += i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = 1 ; i < MAX_P ; i++) 
		if (prime[i]) pr.insert(i);
	return;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("chal.inp","r",stdin);
	freopen("chal.out","w",stdout);
	//freopen("test.inp","r",stdin);
	sieve();
	int n , m ; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			auto it = pr.lower_bound(a[i][j]);
			b[i][j] = abs(a[i][j] - *it);
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j ++) {
			hang[i] += b[i][j];
		}
	}
	for (int j = 1 ; j <= m ; j++) {
		for (int i = 1 ; i <= n ; i ++) {
			cot[j] += b[i][j];
		}
	}
	int ans = inf;
	int row , col;
	for (int i = 1 ; i <= n ; i++) 
		ans = min(ans , hang[i]);
	for (int i = 1 ; i <= m ; i++) 
		ans = min(ans , cot[i]);
	cout << ans;
	return 0;
}