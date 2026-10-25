#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e18 + 7)

int n , a[MAX_N];
pair<int ,int> fl[MAX_N] , fr[MAX_N];

signed main() {
    freopen("loadtesting.inp","r",stdin);
    freopen("loadtesting.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        fl[i].second = max(fl[i - 1].second + 1 , a[i]);
        fl[i].first = fl[i - 1].first + fl[i].second - a[i];
    }
    for (int i = n ; i >= 1 ; i--) {
        fr[i].second = max(fr[i + 1].second + 1 , a[i]);
        fr[i].first = fr[i + 1].first + fr[i].second - a[i];
    }
    int ans = inf;
    for (int i = 1 ; i <= n ; i++) {
        ans = min(ans , fl[i].first + fr[i].first - min(fl[i].second - a[i] , fr[i].second - a[i]));
    }
    cout << ans;

    return 0;
}