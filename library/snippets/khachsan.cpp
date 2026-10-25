#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define MAX_N (int) (1e5 + 7)

vector<ii> v;
int x[MAX_N] , y[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) 
			cin >> x[i];
		for (int i = 1 ; i <= n ; i++) 
			cin >> y[i];
		for (int i = 1 ; i <= n ;i++) 
			v.push_back(ii(x[i] , y[i]));
		sort(v.begin() , v.end());
		priority_queue<int , vector<int> , greater<int>> pq;
		int ans = 0;
		pq.push(x[i] + y[i] - 1);
		for (int i = 2 ; i <= n ;i++) {
			while (!pq.empty()) {
				if (pq.top() <= x[i]) {
					pq.push(x[i] + y[i] - 1);
					break;
				}
				else pq.pop(); 
			}
			if (pq.empty()) {
				pq.push(x[i] + y[i] - 1);
				ans++;
			}
		}
		cout << ans << '\n';
	}	

	return 0;
}