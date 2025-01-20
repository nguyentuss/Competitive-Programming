#include <bits/stdc++.h>

using namespace std;

#define ii pair <int ,int>
#define l first
#define r second

priority_queue<int , vector <int> , greater<int>> pq;
vector <ii> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t ; cin >> t;
	while (t--) {
		while (!pq.empty()) pq.pop();
		v.clear();
		int n , k;
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++) {
			int x , y; cin >> x >> y;
			v.push_back(ii(x , y));
		}
		sort(v.begin() , v.end());
		for (int i = 0 ; i < k ; i++) 
			pq.push(v[i].r);
		int ans = max(0 , pq.top() - v[k - 1].l + 1);
		for (int i = k ; i < n ; i++) {
			pq.pop();
			pq.push(v[i].r);
			ans = max(ans , pq.top() - v[i].l + 1);
		}
		cout << ans << '\n';	
	}
	return 0;
}