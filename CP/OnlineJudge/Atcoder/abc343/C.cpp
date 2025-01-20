//
// Created by tuloc on 3/24/2024.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6;

bool check(int x) {
    string s = to_string(x);
    int n = s.size();
    for (int i = 0 ; i < n ; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1 ; i <= N ; i++) {
        if (i * i * i <= n && check(i*i*i)) {
            ans = max(ans , i * i * i);
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}