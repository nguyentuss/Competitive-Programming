//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) a.size()

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    map<string , int> mp;
    int cnt = 0;
    vector<pair<string , string>> v;
    for (int i = 0 ; i < n ; i++) {
        string a , b; cin >> a >> b;
        v.push_back(pair<string , string>(a , b));
        if (mp[a] == 0) mp[a] = ++cnt;
        if (mp[b] == 0) mp[b] = ++cnt;
    }
    vector<int> g , w;
    for (auto [a , b] : v) {
        g.push_back(mp[a]);
        w.push_back(mp[b]);
        //cout << mp[a] << " " << mp[b] << '\n';  
    }
    vector<bool> f((1 << (n + 1)) + 9 , false);
    f[0] = true;
    for (int i = 0 ; i < n ; i++) {
        f[1 << i] = true;
    }
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        if (f[mask]) {
            set<int> s1 , s2;
            for (int i = 0 ; i < n ; i++) {
                if ((mask & (1 << i))) {
                    s1.insert(g[i]);
                    s2.insert(w[i]);
                }
            }
            for (int i = 0 ; i < n ; i++) {
                if (!(mask & (1 << i))) {
                    if (s1.find(g[i]) != s1.end() || s2.find(w[i]) != s2.end()) {
                        f[mask | (1 << i)] = true;
                    }
                }
            }
        }
    }           
    int ans = inf;
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        int cnt = __builtin_popcount(mask);
        if (f[mask]) ans = min(ans , n - cnt);
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}