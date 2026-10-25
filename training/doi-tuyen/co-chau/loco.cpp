#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e6 + 7)
int f[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("loco.inp","r",stdin);
	freopen("loco.out","w",stdout);
	f[1] = 1;
	for (int i = 2 ; i < MAX_N ; i ++) {
		if (i % 2 == 0) f[i] = f[i - 1] + 1;
		else f[i] = f[i - 1] + 2;
	}
	int a , x , y; cin >> a >> x >> y;
	if (y % a == 0) {
		cout << -1;
		return 0;
	}
	int level = 0;
	level = y/a + 1;
	int num = f[level];
	if (level == 1) {
		if ((double)-a/(double)2.0 < (double) x && (double) x < (double) a/(double)2.0) cout << 1;
		else cout << -1;
	}
	else if (level % 2 != 0) {
		if (x > a || x < -a) cout << -1;
		else if (x == 0) cout << -1;
		else if (x > 0) cout << num;
		else cout << num - 1;
	}
	else {
		if ((double)-a/(double)2.0 < (double) x && (double) x < (double) a/(double)2.0) cout << num;
		else cout << -1;
	}

	return 0;
}