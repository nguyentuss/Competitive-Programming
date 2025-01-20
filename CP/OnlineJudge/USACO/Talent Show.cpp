//http://www.usaco.org/index.php?page=viewproblem2&cpid=839

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define w first
#define v second
#define inf (int) (1e9 + 7)

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    int n , m ; cin >> n >> m;
    vector<ii> a(n + 1 , ii(0 , 0));
    int W = 0;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].v >> a[i].w;
        W = max(W , a[i].w);
    }
    W = W*n;
    vector<vector<int>> f(2 , vector<int>(W + 1, inf));
    f[0][0] = 0;
    for (int i = 1 ; i <= n ;i ++) {
        int now = i & 1;
        int prev = now ^ 1;
        for (int j = 0 ; j <= W ; j++) {
            if (a[i].w <= j) {
                if (f[prev][j] <= (f[prev][j - a[i].w] + a[i].w) && f[prev][j] != inf)
                    f[now][j] = f[prev][j];
                if ((f[prev][j - a[i].w] + a[i].v) <= f[prev][j] && f[prev][j - a[i].w] != inf)
                    f[now][j] = f[prev][j - a[i].w] + a[i].v;
            }
            else {
                if (f[prev][j] != inf)
                    f[now][j] = f[prev][j];
            }
        }
    }
    double ans = 0;
    for (int i = 0 ; i <= W ; i++) {
        if (f[n&1][i] != inf && f[n&1][i] >= m) {
            double x = (double)i/(double)f[n&1][i];
            ans = max(ans , x);
            //cerr << f[n][i] << " " << i << '\n';
        }
    }
    cout << (int) (ans*1000);
    return 0;
}   