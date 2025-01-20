#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e9 + 7)

int cnt[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	vector<int> v;
	for (int i = MAX_N - 1 ; i >= 1 ; i--) {
		if (cnt[i]) {
			for (int j = 1 ; j <= cnt[i] ; j++) {
				v.push_back(i);
			}
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		int x; cin >> x;
		cout << v[x - 1] << " ";
	}


	return 0;
}