//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int des; 
    int test = 0;
    while (cin >> des) {
        des--;
        cout << "CASE " << ++test << ":\n";
        vector<vector<int>> adj(21);
        int u, v;
        while (cin >> u >> v && u && v) {
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<vi> s;
        function<void(int , vector<bool> , vector<int>)> DFS = [&](int u, vector<bool> cnt , vector<int> trace) {
            if (u == des) {
                s.insert(trace);
                return;
            }
            for (int v : adj[u]) {
                if (!cnt[v]) {
                    cnt[v] = true; 
                    trace.push_back(v);
                    DFS(v, cnt, trace);
                    cnt[v] = false;
                    trace.pop_back();
                }
            }
        };
        vector<int> c;
        c.push_back(0);
        vector<bool> cnt(21);
        cnt[0] = true;
        DFS(0 , cnt, c);
        for (auto vc : s) {
            for (int i = 0 ; i < sz(vc) ; i++) {
                if (i == sz(vc) - 1) {
                    cout << vc[i] + 1 << '\n';
                }
                else cout << vc[i] + 1<< ' ';
            }
        }
        cout << "There are " <<  sz(s) << " routes from the firestation to streetcorner "<< des + 1 << ".\n";
    }
}

signed main() {
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    // cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    cerr << "it took " << (float)clock()/CLOCKS_PER_SEC << " seconds" << '\n';
	return 0;
}
