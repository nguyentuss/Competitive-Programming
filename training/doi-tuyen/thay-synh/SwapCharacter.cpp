//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int a[N];
map<int , int> m;

void solve() {
	int n; cin >> n;
    int cntone = 0;
    int mx = 0;
    int ans = 0;
    set<int> s;
    for (int i = 1 ; i <= n; i++) {
        int x; cin >> x;
        mx = max(mx , x);
        ans ^= x;
        s.insert(x); 
    }
    if (s.size() == 1) 
        cout << ((n & 1) ? -1 : 0) << '\n';
    else if (ans) {
        cout << -1 << '\n';
    }
    else cout << mx - 1 << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}