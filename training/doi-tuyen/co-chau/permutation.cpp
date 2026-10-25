#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e18 + 7)

int POW[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("permutation.inp","r",stdin);
	freopen("permutation.out","w",stdout);
	int n , k; cin >> n >> k;
	POW[0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		POW[i] = POW[i - 1]*i;
	}
	if (POW[n] < k && n <= 13) {
		cout << -1;
		return 0;
	}
	int pos = 0;
	for (int i = 1; i <= n ; i++) {
		if (POW[i] == k) {
			for (int j = 1 ; j <= n ; j++) {
				cout << j << " ";
			}
			return 0;
		}
		if (POW[i] > k) {
			pos = i;
			break;
		}
	}
	vector<int> v;
	v.push_back(0);

	int curr = POW[pos] , cnt = 0;
	for (int i = 1 ; i <= pos ; i++) v.push_back(i);
	for (int i = pos ; i >= 1 ; i--) {
		if (curr == k) break;
		int len = i - 1;
		int minn = inf;
		int pos = 0;
		for (int j = 1 , x = len ; j <= len ; j++ , x --) {
			if ((curr - j*POW[len]) >= k) {
				if (minn > (curr - j*POW[len])) {
					minn = curr - j*POW[len];
					pos = x; 
				}
			}
		}
		if (minn == inf) continue;
		vector<int> tmp;
		for (int j = 1 ; j <= i ; j++) {
			if (j != pos) tmp.push_back(v[j]);
		}
		tmp.push_back(v[pos]);
		for (int j = i + 1 ; j < v.size() ; j++) tmp.push_back(v[j]);
		v.clear();
		v.push_back(0);
		for (auto x : tmp) v.push_back(x);
		cnt++;
		curr = minn;
	}
	for (int i = 1 ; i <= (n - pos) ; i ++) cout << i << " ";
	for (int i = v.size() - 1 ; i >= 1 ; i--) cout << v[i] + (n - pos) << " ";
	return 0;
}