//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int mod = 1e9 + 7;


void solve() {
    int n; cin >> n;
    n *= 2;
    string t; cin >> t;
    int m = sz(t);
    auto KMP = [&](string &s) -> vi {
        int n = sz(s);
        vector<int> pi(n);
        for (int i = 1 ; i < n ; i++) {
            int j = pi[i - 1]; 
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) j++; 
            pi[i] = j;
        }
        return pi;
    };
    vi pi = KMP(t);
    // for (int i = 0 ; i < m ; i++) {
    //     cerr << pi[i] << ' ';
    // }
    auto KMP_automaton = [&](vi &pi) -> vector<vi> {
        int n = sz(pi);
        vector<vi> aut(n , vi(2));
        for (int i = 0 ; i < n ; i++) {
            for (int c = 0 ; c < 2 ; c++) {
                if (t[i] - '(' == c) {
                    aut[i][c] = i + 1;
                }
                else {
                    if (i > 0) {
                        aut[i][c] = aut[pi[i - 1]][c];
                    }
                }
            }
        }
        return aut;
    };
    vector<vi> aut = KMP_automaton(pi);
    vector<vector<vi>> f(m + 1 , vector<vi>(n, vi(2)));
    vector<vector<vi>> g(m + 1 , vector<vi>(n, vi(2)));
    g[0][0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            for (int open = 0 ; open < n ; open++) {
                for (int in = 0 ; in < 2 ; in ++) {
                    if (!g[j][open][in]) continue;
                    // suppose put (
                    if (open < n/2) {
                        int nj = aut[j][0];
                        if (in == 0) {
                            if (nj == m) {
                                (f[pi[m-1]][open + 1][1] += g[j][open][0])%=mod;
                            }
                            else (f[nj][open + 1][0] += g[j][open][0])%=mod;
                        }
                        else {
                            if (nj == m) {
                                nj = pi[m - 1];
                            }
                            (f[nj][open + 1][1] += g[j][open][1])%=mod;
                        }
                    }

                    // suppose put )
                    if (open > 0) {
                        int nj = aut[j][1];
                        if (in == 0) {
                            if (nj == m) {
                                (f[pi[m-1]][open - 1][1] += g[j][open][0])%=mod;
                            }
                            else (f[nj][open - 1][0] += g[j][open][0])%=mod;
                        }
                        else {
                            if (nj == m) {
                                nj = pi[m - 1];
                            }
                            (f[nj][open - 1][1] += g[j][open][1])%=mod;
                        }
                    }
                }
            }
        }
        g = f; 
        f.assign(m + 1 , vector<vi>(n , vi(2 , 0)));
    }
    int ans = 0;
    for (int j = 0 ; j <= m ; j++) {
        (ans += g[j][0][1])%=mod;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
