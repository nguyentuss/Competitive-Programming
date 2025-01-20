//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n , m; cin >> n >> m;
    int cnt = 0;
    for (int i = 2 ; i < N ; i++) {
        if (i * i > n) break;
        cnt++;
    }
    vector<int> pw2(N);
    pw2[0] = 1;
    for (int i = 1 ; i < N ; i++) {
        pw2[i] = (pw2[i - 1] * 2)%m;
    }
    int ans = 0;
    for (int i = 1 ; i <= cnt ; i++) {
        //ans = ans + (pw2[i] - 1) * (pw2[n - cnt - 1]);
        ans = (ans + (((pw2[i] - 1 + m) % m) * pw2[n - cnt - 1])%m)%m;
    }
    cout << (pw2[n] - ans + m)%m;
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