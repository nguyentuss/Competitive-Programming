//source:: https://oj.vnoi.info/problem/icpc22_regional_k
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
vector<int> adj[N];
vector<int> a;

pair<int , int> ok(int u , int X , int p = -1) {
    pair<int , int> match = {a[u] , inf};
    int cntPair = 0;
    for (int v : adj[u]) {
        if (v != p) {
            auto [cnt , mn] = ok(v , X , u);
            cntPair += cnt;
            if (mn < match.first) {
                match = {mn , match.first};
            }
            else if (mn < match.second) {
                match.second = mn;
            }
        }
    }
    if (match.first + match.second <= X) {
        return {cntPair + 1 , inf};
    }
    else return {cntPair , match.first};
}

void solve() {
    int n, k; cin >> n >> k;
    a.resize(n);
    rep(i , 0 , n) cin >> a[i];
    rep(i , 0 , n - 1) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 0 , r = 1e18 + 6;
    int ans = inf;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(0 , mid).first >= k) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << (ans == inf ? -1 : ans);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}