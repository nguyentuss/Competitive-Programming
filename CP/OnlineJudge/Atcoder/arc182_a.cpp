//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int mod = 998244353;
const int N = 5007; 

int P[N] , V[N] , f[N] , g[N];

void solve() {
    int n , q; cin >> n >> q; 
    for (int i = 1 ; i <= q ; i++) {
        cin >> P[i] >> V[i];
        //cerr << i << " " << P[i] << " " << V[i] << '\n';
    }
    f[0] = 1;
    for (int i = 0 ; i <= q ; i++) g[i] = -1;
    for (int i = 1 ; i <= q ; i++) {
        g[i] = -1;
        int stat = -1;
        bool ff = 0;
        for (int j = i-1 ; j >= 0 ; j--) {
            if (V[i] < V[j]) {
                if (stat == -1) {
                    if (P[i] == P[j]) {
                        cout << 0; 
                        return;
                    }
                    if (P[i] > P[j]) {
                        stat = 1; // chose right
                    }
                    else {
                        stat = 0; // chose left
                    }
                    g[i] = stat;
                    g[j] = stat ^ 1;
                }
                else {
                    if (stat == 0 && P[i] >= P[j]) {
                        cout << 0; 
                        return;
                    } 
                    if (stat == 1 && P[i] <= P[j]) {
                        cout << 0;
                        return;
                    }
                    if (g[j] != -1 && g[i] == g[j]) {
                        cout << 0; 
                        return;
                    }
                    g[j] = stat ^ 1;
                }
            }
        }
        // for (int h = 1 ; h <= q ; h++) {
        //     cerr << g[h] << " ";
        // }
        // cerr << '\n';
    }
    int ans = 1;
    for (int i = 1 ; i <= q ; i++) {
        //cout << g[i] << " ";
        if (g[i] == -1) {
            (ans *= 2)%=mod;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}