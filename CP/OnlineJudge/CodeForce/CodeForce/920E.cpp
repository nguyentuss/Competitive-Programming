//source:: https://codeforces.com/contest/920/problem/E
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

vector<set<int>> adj(N);
set<int> s;
int cc = 0;

void DFS(int u) {
    vector<int> tmp;
    for (int v : s) {
        if (adj[u].find(v) == adj[u].end()) {
            tmp.push_back(v); 
            cc++; 
        }
    }
    for (int u : tmp) s.erase(u);
    for (int u : tmp) DFS(u);
}

void solve() {
    int n , m; cin >> n >> m;
    rep(i , 0 , m) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    rep(i , 0 , n) s.insert(i);
    vector<int> ans;
    rep(i , 0 , n) {
        if (s.find(i) != s.end()) {
            cc = 1; 
            s.erase(i);
            DFS(i);
            ans.push_back(cc);
        }
    }
    cout << sz(ans) << '\n';
    sort(ans.begin() , ans.end());
    for (int x : ans) cout << x << " ";
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