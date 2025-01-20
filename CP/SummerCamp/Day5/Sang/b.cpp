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
const int MAX_N = 1e4 + 7;
const int MOD = 1e9 + 7;

int f[MAX_N][27];
int a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    s = ' ' + s;
    int n = s.size() - 1;
    for (int i = 1 ; i <= n ;i ++) {
        a[i] = (int)s[i] - 'A'; 
        for (int j = 0 ; j <= 26 ; j++) {
            f[i][j] = inf;
        }
    }
    f[1][a[1]] = 2;
    for (int i = 1 ; i < n ;i ++) {
        for (int ch = 0 ; ch <= 26 ; ch++) {
            if (f[i][ch] == inf) continue;;
            f[i + 1][a[i + 1]] = min(f[i + 1][a[i + 1]] , f[i][ch] + 2);
            f[i + 1][ch] = min(f[i + 1][ch] , f[i][ch] + 2);
            if (ch == a[i + 1]) {
                f[i + 1][ch] = min(f[i + 1][ch] , f[i][ch] + 1);
            }
        }
    }
    int ans = inf;
    for (int i = 0 ; i <= 26 ; i++) {
        ans = min(ans , f[n][i]);
    }
    cout << ans;
    return 0;
}