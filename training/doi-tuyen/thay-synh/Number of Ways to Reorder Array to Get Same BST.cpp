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
const int N = 1e3 + 7;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int &u : a) cin >> u;
    vector<vi> C(N , vector<int>(N , 0)); 
    for (int i = 0 ; i < N ; i++) {
        C[i][i] = 1; 
        C[i][0] = 1;
    }
    for (int i = 1 ; i < N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%mod;
        }
    }
    function<int(vector<int>)> f = [&](vector<int> v) {
        if (v.empty()) return 1ll;
        int m = sz(v);
        int r = v[0]; 
        vi left; 
        vi right;
        for (int i = 1 ; i < m ; i++) {
            if (v[i] < r) left.push_back(v[i]); 
            else right.push_back(v[i]); 
        }
        return (C[m - 1][sz(left)] * f(left) %mod * f(right)%mod)%mod;
    };
    cout << (f(a) - 1 + mod)%mod;
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