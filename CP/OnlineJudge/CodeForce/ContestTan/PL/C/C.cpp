#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 3e3 + 7;
const int MOD = 1e9 + 7;

ii a[N];
int f[N][2];


main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1 , a + 1 + n);
    for (int i = 1 ; i <= n ; i++) {
        f[i][1] = f[i][0] = inf;
    }
    f[1][1] = a[1].se;
    for (int i = 2 ; i <= n ; i++) {
        f[i][1] = min(f[i - 1][1] , f[i - 1][0]) + a[i].se;
        int sum = 0;
        for (int j = i ; j >= 2 ; j--) {
            sum += a[j].fi;
            f[i][0] = min(f[i][0] , f[j - 1][1] + sum - a[j - 1].fi*(i - j + 1));
        }
    }
    cout << min(f[n][0] , f[n][1]);
    return 0;
}
