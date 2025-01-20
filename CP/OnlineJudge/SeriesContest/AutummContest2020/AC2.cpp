#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second
#define MAX_VAL (int) (1e9 + 7)

int f[57][57];
int trace[57][57];
ii v[57];
int n , k , g;
int ans[57];

void init() {
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= g ; j++) {
			f[i][j] = MAX_VAL;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> g >> k;
		init();
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i].f;
			v[i].s = i;
		}
		sort(v + 1 , v + 1 + n);
		f[0][0] = 0;
		for (int group = 0 ; group < g ; group ++) {
			for (int i = 0 ; i < n ; i++) {
				if (f[i][group] == MAX_VAL) continue;
				if (f[i + 1][group + 1] > f[i][group]) {
					f[i + 1][group + 1] = f[i][group];
					trace[i + 1][group + 1] = i;
				}
				for (int j = i + 2 ; j <= n ; j ++) {
					int val = f[i][group] + v[j].f - v[i + 1].f; 
					if (f[j][group + 1] > val) {
						f[j][group + 1] = val;
						trace[j][group + 1] = i;
					}
				}
			}
		}
		if (f[n][g] > k) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		int i = n , j = g;
		while (j > 0) {
			int before = trace[i][j];
			for (int h = before + 1; h <= i ; h++) {
				ans[v[h].s] = j;
			}
			j--;
			i = before;
		}
		for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
		cout << '\n';
	}	
	return 0;
}