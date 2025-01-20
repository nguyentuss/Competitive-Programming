#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e5 + 7)
#define MAX_MASK (int) (1 << 8)

int a[MAX_N][9];
int n , m;
int pos_1 , pos_2;

bool check(int x) {
	vector<int> f;
	f.resize(MAX_MASK , -1);
	for (int i = 1 ; i <= n ; i++) {
		int mask = 0;
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] >= x) {
				mask |= (1 << (j - 1));
			}
		}
		f[mask] = i;
	}
	for (int mask1 = 0 ; mask1 < (1 << m) ; mask1++) {
		for (int mask2 = 0 ; mask2 < (1 << m) ; mask2 ++) {
			if (f[mask1] != -1 && f[mask2] != -1 && (mask1 | mask2) == ((1 << m) - 1)) {
				pos_1 = f[mask1];
				pos_2 = f[mask2];
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	int l = 0 , r = 1e9;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << pos_1 << " " << pos_2;
	return 0;
}