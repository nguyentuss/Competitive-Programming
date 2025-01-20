#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 7;
const int inf = 1e18 + 7;

int a[N] , b[N];
int f[N][2];
int g[N];
// blue = 0 , red = 1;

void solve() {
    int n , blueCost; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    int m; cin >> m;
    for (int i = 1 ; i <= m ; i++) cin >> b[i];
    cin >> blueCost;
    for (int i = 1 ; i <= n ; i++) {
        if (i == 1) f[i][0] = f[i - 1][0] + a[i];
        else f[i][0] = min(f[i - 1][0] + a[i] , f[i - 1][1] + a[i]);
        if (i > 1) f[i][1] = min(f[i - 1][1] + b[i] , f[i - 1][0] + blueCost + b[i]);
        else f[i][1] = blueCost + b[i];
    }
    cout << 0 << '\n';
    for (int i = 1 ; i <= n ; i++) {
        cout << min(f[i][1] , f[i][0]) << '\n';
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();

    return 0;
}