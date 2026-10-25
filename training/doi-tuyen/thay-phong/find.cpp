#include <bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

int b[100007] , a[100007];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ;i ++) cin >> a[i];
    for (int i = 1 ; i <= m ; i++) {
        static int u , v , k; cin >> u >> v >> k;
        k--;
        for (int j = u ; j <= v ; j++) {
            b[j] = a[j];
        }
        nth_element(b + u , b + k + u , b + v + 1);
        cout << b[k + u] << '\n';
    }

    return 0;
}