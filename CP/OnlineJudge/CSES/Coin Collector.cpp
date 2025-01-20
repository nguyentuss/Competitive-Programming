#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 7;
const int inf = 1e18;

vi val, comp, z, cont;
int Time, ncomps;
vector<int> adj[N];
int C[N];
int c[N]; 
vector<int> G[N];
int f[N];

template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f , int n) {
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void solve() {
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < n ; i++) cin >> c[i];
    for (int i = 1 ; i <= m; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    scc(adj , [&](vi cp){} , n);
    int mx_comp = 0;
    set<ii> s;
    for (int i = 0 ; i < sz(comp) ; i++) {
        C[comp[i]] += c[i];
        mx_comp = max(mx_comp , comp[i]);
        for (int v : adj[i]) {
            if (comp[i] != comp[v]) 
                s.insert(ii(comp[i] , comp[v]));
        }
    }
    // for (auto x : comp) cerr << x << " ";
    // cerr << '\n';
    for (auto [u , v] : s) {
        //cerr << u << " " << v << '\n';
        G[u].push_back(v);
    }
    for (int i = 0 ; i <= mx_comp ; i++) 
        f[i] = C[i];
    for (int u = mx_comp ; u >= 0 ; u--) {
        for (auto v : G[u]) {
            f[v] = max(f[v] , f[u] + C[v]);
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= mx_comp ; i++) {
        ans = max(ans , f[i]);
    }
    cout << ans;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}