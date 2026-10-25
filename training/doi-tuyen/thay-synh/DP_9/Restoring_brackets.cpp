#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2007;
const int MOD = 301907;

int f[N][N];
//

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    f[0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (s[i + 1] == '?') {
                (f[i + 1][j + 1] += f[i][j])%=MOD;
                if (j - 1 >= 0)
                    (f[i + 1][j - 1] += f[i][j])%=MOD;
            }
            if (s[i + 1] == '(') {
                (f[i + 1][j + 1] += f[i][j])%=MOD;
            }
            if (s[i + 1] == ')' && j - 1 >= 0) {
                (f[i + 1][j - 1] += f[i][j])%=MOD;
            }
        }
    }
    cout << f[n][0];
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}