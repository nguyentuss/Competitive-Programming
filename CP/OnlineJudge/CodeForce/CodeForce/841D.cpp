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
const int N = 3e5 + 7;

int a[N];
bool rm[N];
vector<int> ans;
vector<pii> adj[N];
int vis[N]; 

void DFS(int u , int father , int id) { 
    vis[u] = true;
    for (auto [v , l] : adj[u]) {
        if (!vis[v]) {
            DFS(v , u , l);
        }
    }
    if (father != -1) {
        if (a[u] == 1) {
            ans.push_back(id);
            a[father] ^= 1;
        }
    }
}


void solve() {
    int n , m; cin >> n >> m;
    int sum = 0;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        sum = sum + (a[i] != -1 ? a[i] : 0);
        cnt = cnt + (a[i] == -1 ? 1 : 0);
    }
    if (sum % 2) {
        if (!cnt) {
            cout << -1;
            return;
        }
        bool ok = false;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] == -1) {
                if (!ok) {
                    a[i] = 1 , ok = true;
                }
                else a[i] = 0;
            }
        }
    }
    else {
        for (int i = 0 ; i < n ; i++)
            if (a[i] == -1)
                a[i] = 0;
    }

    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].emplace_back(v , i);
        adj[v].emplace_back(u , i);
    }
    DFS(0 , -1 , -1);
    //cerr << "YES";
    cout << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << " ";
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