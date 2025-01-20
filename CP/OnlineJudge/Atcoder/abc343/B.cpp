#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e2 + 7;

vector<int> adj[N];

void solve() {
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int x; cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        sort(adj[i].begin() , adj[i].end());
        for (int x : adj[i]) {
            cout << x + 1 << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}