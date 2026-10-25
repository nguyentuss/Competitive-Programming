#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define ii pair <int , int>

vector<char> v[MAX_N];
map<ii , int> cnt;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			char x; cin >> x;
			v[i].push_back(x);
		}
	}
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		int ask; cin >> ask;
		if (ask == 1) {
			int u , id; cin >> u >> id;
			if (v[u][id - 1] == '1') v[u][id - 1] = '0';
			else v[u][id - 1] = '1';
		}
		else {
			int x , y; cin >> x >> y;
			if (cnt[ii(x , y)]) cout << cnt[ii(x , y)] << '\n';
			else if (cnt[ii(y , x)]) cout << cnt[ii(y , x)] << '\n';
			else {
				int ans = 0;
				for (int j = 0 ; j < m ; j ++) {
					if (v[x][j] != v[y][j]) ans++;
				}
				cout << ans << '\n';
				cnt[ii(x , y)] = cnt[ii(y , x)] = ans;
			}
		}
	}
	return 0;
}