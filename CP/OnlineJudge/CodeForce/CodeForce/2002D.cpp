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

void solve() {
    int n , q; cin >> n >> q;
    vector<vector<int>> adj(n + 1); 
    vector<int> p(n + 1);
    for (int i = 2 ; i <= n ;i ++) {
        int x; cin >> x;
        p[i] = x;
        adj[x].push_back(i); 
        adj[i].push_back(x);
    }
    vector<int> pos(n + 1);
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i], pos[a[i]] = i;
    vector<int> f(n + 1);
    auto DFS = [&](int u , int father , auto &&DFS)->void {
        f[u] = 1;
        for (int v : adj[u]) {
            if (v != father) {
                DFS(v , u , DFS);
                f[u] += f[v];
            }
        }
    };
    DFS(1 , -1 , DFS);
    vector<multiset<int>> s(n+1);
    set<int> ok;
    p[1] = 1;
    for (int i = 1 ; i <= n ; i++) {
        s[p[i]].insert(pos[i]);
        s[p[i]].insert(pos[i] + f[i] - 1);
        //cerr << i << " " << p[i] << " " << pos[i] << " " << pos[i] + f[i] - 1 << '\n';
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!sz(s[i]) || (pos[i] <= *s[i].begin() && *s[i].rbegin() <= pos[i] + f[i] - 1)) {
            //cerr << i << " ";
            ok.insert(i);
        }
    }
    //cout << sz(ok) << '\n';
    while (q--) {
        int x , y; cin >> x >> y; 
        swap(a[x] , a[y]);
        int c1 = a[y]; 
        int c2 = a[x];
        x = c2; y = c1;
        s[p[x]].erase(s[p[x]].find(pos[x]));
        s[p[x]].erase(s[p[x]].find(pos[x] + f[x] - 1));
        s[p[y]].erase(s[p[y]].find(pos[y]));
        s[p[y]].erase(s[p[y]].find(pos[y] + f[y] - 1));
        swap(pos[x],pos[y]); 
        s[p[x]].insert(pos[x]); 
        s[p[x]].insert(pos[x] + f[x] - 1);
        s[p[y]].insert(pos[y]); 
        s[p[y]].insert(pos[y] + f[y] - 1);
        //cerr << a[x] << " " << a[y] << '\n';
        for (int u : {p[x] , p[y] , x , y}) {
            //cerr << u << " ";
            if (!sz(s[u]) || (pos[u] <= *s[u].begin() && *s[u].rbegin() <= pos[u] + f[u] - 1)) {
                ok.insert(u);
            }
            else ok.erase(u);
        }
        // for (int i = 1 ; i <= n ; i++) {
        //     cerr << pos[i] << " ";
        // }
        // cerr << '\n';
        if (sz(ok) == n) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
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