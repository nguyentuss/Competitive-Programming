#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define MAX_N (int) (1e5 + 7)
#define f first
#define s second
#define int long long

vector<ii> v;
int x[MAX_N] , y[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("khachsan.inp","r",stdin);
	freopen("khachsan.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v.clear();
		for (int i = 1 ; i <= n ; i++) 
			cin >> x[i];
		for (int i = 1 ; i <= n ; i++) 
			cin >> y[i];
		for (int i = 1 ; i <= n ;i++) 
			v.push_back(ii(x[i] , y[i]));
		sort(v.begin() , v.end());
		priority_queue<int , vector<int> , greater<int>> pq;
		int ans = 1;
		pq.push(v[0].f + v[0].s - 1);
		for (int i = 1 ; i < n ;i++) {
			if (pq.top() < v[i].f) {
				pq.pop();
				pq.push(v[i].f + v[i].s - 1);
			}
			else {
				ans++;
				pq.push(v[i].f + v[i].s - 1);
			}
		}
		cout << ans << '\n';
	}	

	return 0;
}