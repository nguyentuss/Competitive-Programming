//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int a , b; cin >> a >> b;
    int x = 1; 
    int ans = 0;
    while (x <= b) {
        x *= 2;
        ans++;
    }
    cout << ans - 1 << '\n';
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