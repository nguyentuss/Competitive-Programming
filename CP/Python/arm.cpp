#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , q; cin >> n >> q;
    vector<int> f;
    f.assign(n + 2 , 0);
    while (q--) {
        int a , b , k; cin >> a >> b >> k;
        f[a] += k;
        f[b + 1] -= k;
    }
    int x = 0 , ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        x += f[i];
        ans = max(ans , x);
    }
    cout << ans;

    return 0;
}