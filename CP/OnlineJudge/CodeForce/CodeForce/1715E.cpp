//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;



vector<pii> adj[N];


void VL(vector<int> &f , vector<int> &pre , int l , int r , int optL , int optR) {
	if (l > r) return; 
	int opt = optL;
	int mid = (l + r) >> 1;
	for (int i = optL ; i <= optR ; i++) {
		if (pre[i] + (i - mid) * (i - mid) < pre[opt] + (opt - mid) * (opt - mid)) {
			opt = i;
		}
	}
	f[mid] = pre[opt] + (opt - mid) * (opt - mid); 
	VL(f , pre , l , mid - 1 , optL , opt); 
	VL(f , pre , mid + 1 , r , opt , optR);
}

void solve() {
	int n, m , k; cin >> n >> m >> k;
	for (int i = 0 ; i < m ; i++) {
		int u , v, w; cin >> u >> v >> w;
		adj[u].push_back(pii(w , v));
		adj[v].push_back(pii(w , u)); 
	}
	priority_queue<pii , vector<pii> , greater<pii>> pq;
	pq.push(pii(0 , 1));
	vector<int> f(n + 1, inf);
	f[1] = 0;

	while (!pq.empty()) {
		auto [du , u] = pq.top();
		pq.pop();
		if (du != f[u]) continue;
		for (auto [uv , v] : adj[u]) {
			if (f[v] > f[u] + uv) {
				f[v] = f[u] + uv; 
				pq.push(pii(f[v] , v));
			}
		} 
	}
	for (int i = 1 ; i <= k ; i++) {
		vector<int> pre = f;
		VL(f , pre , 1 , n , 1 , n);
		priority_queue<pii, vector<pii> , greater<pii>> pq;
		for (int i = 1 ; i <= n ; i++) {
			pq.push(pii(f[i] , i)); 
		}
		for (int j = 1 ; j <= n ; j++) {
			cerr << f[j] << " ";
		}
		cerr << '\n';
		while (!pq.empty()) {
			auto [du , u] = pq.top();
			pq.pop(); 
			if (du != f[u]) continue; 
			for (auto [uv , v] : adj[u]) {
				if (f[v] > f[u] + uv) {
					f[v] = f[u] + uv; 
					pq.push(pii(f[v] , v));
				}
			}
		}
		for (int j = 1 ; j <= n ; j++) {
			cerr << f[j] << " "; 
		}
		cerr << '\n';
		cerr << '\n';
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << f[i] << " ";
	}
	
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int test = 1; 
	//cin >> test; 
	while (test--) {
	   solve();
	}
}