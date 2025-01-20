//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    map<int , int> mp;
    set<int> s;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x; 
        s.insert(x);
        mp[x] ++;
    }
    for (auto x : s) {
        cout << x << " ";
    }
    cout << '\n';
    for (auto x : s) {
        cout << mp[x] << " ";
    }
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