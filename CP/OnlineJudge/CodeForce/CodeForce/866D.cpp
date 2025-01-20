//source:: https://codeforces.com/contest/866/problem/D
// tag: slopetrick
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    int ans = 0;
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        ans -= x;
        pq.push(x);
        pq.push(x);
        pq.pop();
    }
    for (int i = 1 ; i <= n ; i++) {
        ans += pq.top();
        pq.pop(); 
    }
    cout << ans << '\n';
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