#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf (int) (1e18)


vector<int> a ,b;
int n;
bool check[107];
int X[107];
int minn = inf;


void write() {
	int ans = 0;
	for (int i = 0 ; i < n; i++) {
		if (a[X[i]] == b[i]) return;
		ans += abs(a[X[i]] - b[i]);
	}
	minn = min(minn , ans);
}

void backtr(int i) {
	for (int j = 0 ; j < n ; j++) {
		if (!check[j]) {
			X[i] = j;
			check[j] = 1;
			if (i == (n - 1)) write();
			else backtr(i + 1);
			check[j] = 0;
		}
	}	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x , y; cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	if (n <= 100) {
		backtr(0);
		cout << minn;
	}
	else {
		sort(a.begin() , a.end());
		sort(b.begin() , b.end());
		int ans = 0;
		for (int i = 0 ; i < n ; i++) {
			ans += abs(a[i] - b[i]);
		}
		cout << ans;
	}
	return 0;
}