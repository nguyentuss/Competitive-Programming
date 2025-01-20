//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n, k; cin >> n >> k;
    priority_queue<int> pq;
    int sum = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        sum += x;
        if (sum <= i * k) {
            pq.push(x); 
            ans++;
        }
        else {
            if (pq.empty()) {
                sum -= x;
                continue;
            }
            if (pq.top() > x) {
                sum -= pq.top();
                pq.pop();
                pq.push(x);
            }
            else {
                sum -= x;
            }
        }
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}