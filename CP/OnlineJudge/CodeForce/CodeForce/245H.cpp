#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

int n; 
int f[N][N];
bool g[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    n = s.size(); 
    //cout << n;
    s = ' ' + s;
    for (int i = 1 ; i <= n ;i ++) {
        f[i][i] = 1;
        g[i][i] = 1;
    }
    for (int j = 1 ; j <= n ; j ++) {
        for (int i = j - 1 ; i >= 1 ; i--) {
            if (s[i] == s[j]) {
                if ((i + 1) == j) g[i][j] = 1;
                else g[i][j] = g[i + 1][j - 1];
            } 
        }
    }
    for (int j = 1 ; j <= n ; j ++) {
        for (int i = j - 1 ; i >= 1 ; i--) {
            if (s[i] == s[j]) {
                if ((i + 1) == j)
                    f[i][j] = 1;
                else {
                    if (g[i + 1][j - 1]) {
                        f[i][j] = 1;
                    }
                }
            }
            f[i][j] = f[i][j] + f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1]; 
        }
    }
    int q; cin >> q;
    for (int i = 1 ; i <= q ; i++) {
        int l , r; cin >> l >> r;
        cout << f[l][r] << '\n';
    }

    return 0;
}