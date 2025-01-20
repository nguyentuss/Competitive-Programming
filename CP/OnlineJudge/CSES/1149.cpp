//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 5e5 + 7;
const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = sz(s); 
    s = " " + s; 
    vector<int> a(26);
    int ans = 1; 
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        f[i] = (f[i - 1] * 2)%MOD;
        f[i] = (f[i] - a[s[i] - 'a']%MOD + MOD)%MOD; 
        a[s[i] - 'a'] = f[i - 1];
        //a[s[i] - 'a'] = a[s[i] - 'a'] + f[i - 1];
        //cerr << f[i] << " ";
    }
    cout << (f[n] - 1 + MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}