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
const int inf = 1e18 + 7;
const int MAX_N = 2e3 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("pair.inp","r",stdin);
    freopen("pair.out","w",stdout);
    int n , d; cin >> n >> d;
    //sub3
    if (d == 0) {
        vector<int> a(n + 1 , 0);
        unordered_map<int , int> cnt , m;
        set<int> s;
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        vector<int> aa(s.begin() , s.end());
        for (int i = 0 ; i < aa.size() ; i++) {
            for (int j = 0 ; j < i ; j++) {
                m[aa[i] + aa[j]] += min(cnt[aa[i]] , cnt[aa[j]]);
            }
        }
        int ans = 0;
        for (auto it : m) {
            ans = max(ans , it.second);
        }
        for (auto it : cnt) {
            ans = max(ans , it.se/2);
        }
        cout << ans;
    }
    return 0;
}