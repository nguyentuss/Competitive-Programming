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
const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s; 
    int n = sz(s);
    s = " " + s;
    vector<int> f(n + 1);
    map<int , int> mp;
    map<int , int> pos;
    map<int , int> tmp;
    mp[0] = 1;
    pos[0] = 2;
    tmp[0] = 1;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        f[i] = f[i - 1] + (s[i] == '0' ? -1 : 1);
        //cerr << f[i] << " ";
        
        ans = (ans + (n - i + 1)*mp[f[i]]%MOD)%MOD;
        if (pos.find(f[i]) == pos.end()) pos[f[i]] = 1;
        (mp[f[i]] += tmp[f[i]])%=MOD; 
        (mp[f[i]] += (i + 1 - pos[f[i]] + 1))%=MOD;
        (tmp[f[i]] += (i + 1 - pos[f[i]] + 1))%=MOD;
        pos[f[i]] = (i + 2);
        // << f[i] << " " << i << " " << mp[f[i]] << " " << tmp[f[i]] << " " << pos[f[i]] << '\n';
    }
    //cerr << '\n';
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}