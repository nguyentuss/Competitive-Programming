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

/**
 * Author: chilli, pajenegod
 * Date: 2020-02-20
 * License: CC0
 * Source: Folklore
 * Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected.
 * Time: $O(N \log N + Q)$
 * Status: stress-tested
 */
#pragma once

/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Status: Tested at Petrozavodsk
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */
#pragma once

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
 
struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
const int N = 3e5 + 7;

vector<vi> adj(N);
int pa[N];
int k = 0;
int H[N];

void DFS(int u , int father) {
    for (int v : adj[u]) {
        if (v != father) {
            H[v] = H[u] + 1;
            DFS(v , u);
        }
    }
    if (father != -1 && adj[u].size() == 1) {
        k++;
    }
    if (father != -1) {
        pa[u] = father;
    }
}


void solve() {
    int n; cin >> n;
    for (int i = 1 ; i < n ;i ++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0 , -1);
    LCA lca(adj); 
    vector<int> node;
    node.push_back(0); 
    //cerr << k;
    for (int i = 0 ; i < k ; i++) {
        int x; cin >> x;
        x--;
        node.push_back(x);
    }
    node.push_back(0);
    map<pair<int , int> , int> mp;
    vector<int> trace;
    auto calc = [&](int u , int v) -> void {
        bool rev = false;
        if (H[u] < H[v]) {
            swap(u , v) , rev = true;
        }
        vector<int> tmp; 
        if (u != v) tmp.push_back(u);  
        while (u != v) {
            mp[{u , pa[u]}] ++;
            u = pa[u];
            tmp.push_back(u);
        }
        if (rev) reverse(tmp.begin() , tmp.end()); 
        //for (int x : tmp) trace.push_back(x);
        //cout << rev << " ";
        for (int i = 0 ; i < sz(tmp) - 1 ; i++) {
            trace.push_back(tmp[i]);
            //cout << tmp[i] + 1 << " ";
        }
        //cout << '\n';
    };
    //cout << H[0] << " " << H[v];
    for (int i = 1 ; i < sz(node) ; i++) {
        int u = node[i - 1]; 
        int v = node[i];
        int cm = lca.lca(u , v);
        calc(u , cm); 
        calc(cm , v);
    }
    trace.push_back(0);
    //calc(0 , 4);
    // calc(0 , 0);
    // calc(4 , 3);
    for (auto [x , key] : mp) {
        if (key != 2) {
            cout << -1; 
            return;
        }
    }
    for (int x : trace) cout << x + 1 << " ";
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