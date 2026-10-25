#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define int long long
int a[MAX_N] , L[MAX_N] , R[MAX_N];
deque<int> dq;
vector<int> v[MAX_N];
map<int , int> m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	freopen("BEAUTIFULARRAY.inp","r",stdin);
	freopen("BEAUTIFULARRAY.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	a[0] = a[n + 1] = n + 1;
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
	    while (dq.size() && a[dq.back()] < a[i]) dq.pop_back();
	    if (dq.empty()) L[i] = 1;
	    else L[i] = dq.back() + 1;
	    dq.push_back(i);
	}
	dq.clear();
	dq.push_back(n + 1);
	for (int i = n ; i >= 1 ; i --) {
		while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
		if (dq.empty()) R[i] = n;
		else R[i] = dq.back() - 1;
		v[R[i]].push_back(i);
		dq.push_back(i);
	}
	//for (int i = 1 ; i <= n ; i++) cout << L[i] << " " << R[i] << '\n';
	int ans = 0;	
	//cout << '\n';
	//for (auto x : v[3]) cout << x << " ";
	for (int i = 1; i <= n ; i++) {
		if (L[i] == i) continue;
		for (auto x : v[i - 1]) {
			m[i - x + 1] = max(m[i - x + 1] , x - L[x] + 1);
		}
	}
	for (auto it : m){ 
		ans += it.second;
		//cout << it.first << " " << it.second << '\n';
	}
	cout << ans;
	return 0;
}