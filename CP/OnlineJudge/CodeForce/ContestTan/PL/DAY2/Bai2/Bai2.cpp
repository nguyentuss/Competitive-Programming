#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e2 + 7;
const int MOD = 1e9 + 7;

struct seg{
    int t , d , p;
};

bool cmp(seg &a , seg &b) {
    return a.d < b.d;
}

seg a[N];
int f[N][2007];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int n; cin >> n;
    for (int i = 1 ; i<= n ; i++) {
            cin >> a[i].t >> a[i].d >> a[i].p;
    }
    sort(a + 1 , a + 1 + n , cmp);
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= 2000 ; j++) {
            f[i][j] = -inf;
        }
    }
    f[0][1] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= a[i].d ; j++) {
            f[i][j] = f[i - 1][j];
            if (j - a[i].t > 0) {
                f[i][j] = max(f[i][j] , f[i - 1][j - a[i].t] + a[i].p);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= 2000 ; i++) {
        ans = max(ans , f[n][i]);
    }
    cout << ans;
    return 0;
}
