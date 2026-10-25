#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_P (int) (1e7 + 7)
#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)

int minprime[MAX_P];
int b[MAX_N];
int f_min[MAX_N][100];
int f_max[MAX_N][100];
int q;
int n , m;

void sieve() {
	for (int i = 2 ; i * i <= 1e7 ; i++) {
		if (!minprime[i]) {
			for (int j = i * i ; j <= 1e7 ; j += i) {
				if (!minprime[j]) {
					minprime[j] = i;
				}
			}
		}
	}
	for (int i = 2 ; i <= 1e7 ; i++) {
		if (!minprime[i]) {
			minprime[i] = i;
		}
	}
	return;
}

void calc() {
	for (int j = 0 ; (1 << j) <= n ; j++) {
		for (int i = 0 ; i + (1 << j) - 1 <= n ; i++) {
			f_min[i][0] = inf;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		f_min[i][0] = b[i];
		f_max[i][0] = b[i];
	}
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
			f_min[i][j] = min(f_min[i][j - 1] , f_min[i + (1 << (j - 1))][j - 1]);
			f_max[i][j] = max(f_max[i][j - 1] , f_max[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int getmax(int l , int r) {
	int k = log2(r - l + 1);
	return max(f_max[l][k] , f_max[r - (1 << k) + 1][k]);
}

int getmin(int l , int r) {
	int k = log2(r - l + 1);
	return min(f_min[l][k] , f_min[r - (1 << k) + 1][k]);
}

bool check(int len) {
	int l = 1 , r = len;
	while (r <= n) {
		int maxx = getmax(l , r);
		int minn = getmin(l , r);
		if ((maxx - minn) <= q) return true;
		l++ , r++;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("devi.inp","r",stdin);
	freopen("devi.out","w",stdout);
	sieve();
	 cin >> n >> m; 
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		b[i] = (1 + minprime[x])*(1 + minprime[x]);
	}
	calc();
	/*for (int i = 1 ; i <= n ; i++) {
		cout << b[i] << " ";
	}*/
	for (int i = 1 ; i <= m ; i++) {
		cin >> q;
		int ans = 1;
		int l = 1 , r = n;
		while (l <= r) {
			int mid = (l + r)/2;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			}
			else {
				r = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
