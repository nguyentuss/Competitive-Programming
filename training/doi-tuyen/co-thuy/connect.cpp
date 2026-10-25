#include <bits/stdc++.h>

using namespace std;

#define int long long

int l[100007];
int r[100007];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("connect.inp","r",stdin);
    freopen("connect.out","w",stdout);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> l[i] >> r[i];
    sort(l + 1 , l + 1 + n) , sort(r + 1 , r + 1 + n);
    int ans = n;
    for (int i = 1 ; i <= n ; i++) ans += max(l[i] , r[i]);
    cout << ans;
    return 0;
}   