#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 20;
const int MOD = 1e9 + 7;

int f[N][1 << N];
int d[N][N];
int a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i][1 << (i - 1)] = a[i];
    }
    for (int i = 1 ; i <= k ;i ++) {
        int x , y , c; cin >> x >> y >> c;
        d[x][y] = c;
    }
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        for (int i = 1 ; i <= n ;i ++) {
            if (!(mask & (1 << (i - 1)))) continue;
            for (int j = 1 ; j <= n ; j++) {
                if ((mask & (1 << (j - 1)))) continue;
                f[j][mask | (1 << (j - 1))] = max(f[j][mask | (1 << (j - 1))] , f[i][mask] + a[j] + d[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int mask = 0 ; mask < (1 << n) ; mask++) {
            if (__builtin_popcount(mask) == m) {
                if ((1 << (i - 1))&mask)
                ans = max(ans , f[i][mask]);
            }
        }
    }
    cout << ans;
    return 0;
}
