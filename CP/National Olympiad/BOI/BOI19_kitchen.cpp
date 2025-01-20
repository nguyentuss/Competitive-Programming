#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 3e2 + 7;
const int MOD = 1e9 + 7;
const int MAX_V = 300 * 301;

int n , m , K;
int f[MAX_N][MAX_N*MAX_N];
int a[MAX_N];
int b[MAX_N];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> K;
    int W = 0 , w = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] < K) {
            cout << "Impossible";
            return 0;
        }
        W += a[i];
    }
    for (int i = 1 ; i <= m ; i++) {
        cin >> b[i];
        w += b[i];
    }
    if (W > w || K > m) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 0 ; i <= m ; i++) {
        for (int j = 0 ; j <= w ; j++) {
            f[i][j] = -inf;
        }
    }
    f[0][0] = 0;
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 0 ; j <= w ; j++) {
            f[i][j] = f[i - 1][j];
            if (j - b[i] >= 0) {
                f[i][j] = max(f[i][j] , f[i - 1][j - b[i]] + min(b[i] , n));
            }
        }
    }
    int ans = inf;
    for (int i = W ; i <= w ; i++) {
        if (f[m][i] >= n*K) {
            ans = min(ans , i - W);
        }
    }
    if (ans == inf) cout << "Impossible";
    else cout << ans;
    return 0;
}