#include <bits/stdc++.h>

using namespace std;

vector <int> v[107];
bool cnt[107][107];
int a[107];
int n;

void init() {
	for (int i = 1 ; i <= n ; i++) {
		a[i] = v[i].size();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		int m ; cin >> m;
		for (int j = 1 ; j <= m ; j++) {
			int x; cin >> x;
			v[i].push_back(x);
			cnt[i][x] = true;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		init();
		bool check = true;
		for (int j = 0 ; j < v[i].size() ; j++) {
			int x = v[i][j];
			for (int k = 1 ; k <= n; k++) {
				if (k != i) {
					if (cnt[k][x]) a[k] --;
					if (!a[k]) {
						cout << "NO" << '\n';
						check = false;
						break;
					}
				}
			}
			if (j == v[i].size() - 1 && check) cout << "YES" << '\n'; 
			if (!check) break;
		}
	}
	return 0;
}