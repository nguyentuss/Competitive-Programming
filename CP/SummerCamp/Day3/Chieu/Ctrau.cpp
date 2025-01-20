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
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

int n , m; 
int a[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    f[0][1] = 1;
    for (int i = 1 ; i <= k ; i++) {
        int x , y; cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j]) f[i][j] = 0;
            else (f[i][j] = f[i - 1][j] + f[i][j - 1])%=MOD;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cout << f[i][j] << " ";
        }
        cout << '\n';
    }
    cout << f[n][m];
    return 0;
}