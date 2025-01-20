//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
            //cerr << x << " " << y << '\n';
            //if (x > n - 1 || y > n - 1) cerr << "YES" << '\n';
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}


const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

vi primes;

void solve() {
    int n; cin >> n;
    int m = 1;
    while (n - 1 > (m % 2 == 1 ? m * (m + 1) / 2 : (m * m) / 2 + 1)) {
        m++;
    }
    vector d(m, vector<int>(m , 1));
    vector<vector<pair<int , int>>> adj; 
    adj.resize(m); 
    //cerr << m << '\n';
    if (m % 2 == 0) {
        for (int i = 2 ; i < m - 1 ; i += 2) 
            d[i][i + 1] = d[i + 1][i] = 0;
    }
    int idx = 0;
    for (int i = 0 ; i < m ; i++) {
        for (int j = i ; j < m ; j++) {
            if (d[i][j] == 1) {
                adj[i].push_back({j , idx});
                adj[j].push_back({i , idx});
                idx ++;
            }
        }
    }
    vector<int> ans = eulerWalk(adj, idx);
    map<int , bool> mp;
    int cc = min(n , sz(ans));
    for (int i = 0 ; i < cc ; i++) {
        //cerr << ans[i] << " ";
        cout << primes[ans[i]] << " ";
    }

    cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    primes = eratosthenesSieve(3E5);
    int test; cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}