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
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = 0;
    vector<bool> vis(60);
    map<char,int> ch;
    map<vector<int>,ll> dp;
    for (int i = 0 ; i < n ; i++) {
        int c;
        if ('a' <= s[i] && s[i] <= 'z') {
            c = s[i] - 'a';
        }
        else {
            c = s[i] - 'A' + 26;
        }
        if (!vis[c]) {
            ch[s[i]] = m++; 
            vis[c] = true;
        }
    }
    auto containsEach = [&](vector<int> V) -> bool {
        for (int i = 0 ; i < (int) V.size() ; i++) {
            if (V[i] <= 0) return false;
        }
        return true;
    };

    int ans = 0;
    vector<int> freq(m);
    dp[freq]++;
    for(int i = 0; i < n; i++){
        int c = ch[s[i]];
        freq[c]++;
        if(containsEach(freq))
            for(int j = 0; j < m; j++)
                freq[j]--;
        (ans += dp[freq])%=mod;
        dp[freq]++;
    }
    cout << ans%mod;
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