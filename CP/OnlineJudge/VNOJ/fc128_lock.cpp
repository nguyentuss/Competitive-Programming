#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (-1e9 + 7)

int cost[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int F[MAX_N] , trace[MAX_N];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	vector <int> v;
	for (int i = 1 ; i <= m ; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	F[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		F[i] = inf;
		for (auto e : v) {
			if (i == n && e == 0 && n != cost[0]) continue;
			if (i - cost[e] >= 0 && F[i] <= F[i - cost[e]] + 1) {
				F[i] = F[i - cost[e]] + 1;
				trace[i] = e;
			}
		}
	}
	while (n) {
		cout << trace[n];
		n -= cost[trace[n]];
	}
	return 0;
}