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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

int ti[MAX_N] , to[MAX_N];
vector<ii> adj[MAX_N];
int H[MAX_N];
int P[MAX_N][19];
int C[MAX_N][19];
int f[MAX_N];
int g[MAX_N];
int d[MAX_N];   
int vis[MAX_N];
int check[MAX_N];
int timeDFS = 0;
int n , s , q , e;
vector<ii> seg;

void DFS(int u , int father) {
    P[u][0] = father;
    ti[u] = ++timeDFS;
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father) {
            H[v] = H[u] + 1;
            d[v] = d[u] + w;
            DFS(v , u);
        }
    }
    to[u] = ++timeDFS;
}

void DFS1(int u , int father) {
    if (check[u]) g[u] = d[u];
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father) {
            DFS1(v , u);        
            g[u] = min(g[u] , g[v]);    
        }
    }
}

void DFS2(int u , int father) {
    if (father != -1) { 
        C[u][0] = f[father]; 
    }
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father) {
            DFS2(v , u);        
        }
    }
}

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 19 ; k ++) {
			P[u][k] = -1;
            C[u][k] = inf;
		}
	}
	for (int k = 1 ; k < 19 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
				C[u][k] = min(C[u][k - 1] , C[P[u][k - 1]][k - 1]);
			}
		}
	}
}

int LCA(int u , int v) {
	if (H[u] < H[v]) {
		swap(u , v);
	}
	int ans = inf;
	while (H[u] > H[v]) {
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				ans = min(ans , C[u][k]);
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return ans;
	while (true) {
		bool found = false;
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
                ans = min({ans , C[u][k] , C[v][k]});
				u = P[u][k];
				v = P[v][k];
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
	}
    ans = min({ans , C[u][0] , C[v][0]});
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> q >> e;
    for (int i = 1 ; i < n ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w)); 
        seg.push_back(ii(u , v));   
    }
    for (int i = 1 ; i <= n ; i++) {
        g[i] = inf;
    }
    for (int i = 1 ; i <= s ; i++) {
        int x; cin >> x;
        check[x] = true;
    }
    C[e][0] = inf;
    DFS(e , -1);
    DFS1(e , -1);
    for (int i = 1 ; i <= n ; i++) {
        if (g[i] != inf) 
            f[i] = -2*d[i] + g[i];
        else f[i] = inf;
    }
    DFS2(e , -1);
    buildtable();
    for (int i = 1 ; i <= q ; i++) {
        int I , R; cin >> I >> R;
        int u , v; tie(u , v) = seg[I - 1];
        if (H[u] < H[v]) swap(u , v);
        if(ti[u] <= ti[R] && to[R] <= to[u]) {
            int x = LCA(u , R);
            if (x == inf && f[R] == inf) {
                cout << "oo" << '\n';
            }
            else cout << min(d[R] + x , d[R] + f[R]) << '\n';
        }
        else {
            cout << "escaped" << '\n';
        }
    }
    return 0;
}`