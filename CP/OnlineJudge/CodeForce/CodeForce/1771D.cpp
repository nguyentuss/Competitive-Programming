#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e3 + 7;
const int MOD = 1e9 + 7;

char a[N];
int n;
int dp[N][N];
int H[N];
vector<int> adj[N];
int P[N][20];


void init() {
    for (int i = 1 ; i <= n ; i++) {
        adj[i].clear();
        H[i] = 0;
        for (int j = 1 ; j <= n ; j++) {
            dp[i][j] = -1;
        }
    }
}

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 20 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 20 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
			}
		}
	}
}
int LCA(int u , int v) {
	if (H[u] < H[v]) {
		swap(u , v);
	}
	while (H[u] > H[v]) {
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return u;
	while (true) {
		bool found = false;
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
			}
		}
		if (!found) {
			break;
		}
	}
	return P[u][0];
}

int binaryLifting(int u , int v) {
	if (H[u] > H[v]) swap(u , v);
	while ((H[v] - 1) > H[u]) {
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[v][k] != -1 && H[P[v][k]] > H[u]) {
				v = P[v][k];
				break;
			}
		}
	}
	return v; 
}

void DFS(int u , int father) {
	P[u][0] = father;
	for (int i = 0 ; i < (int) adj[u].size() ;i++) {
		int v = adj[u][i];
		if (v == father) {
			continue;
		}
		H[v] = H[u] + 1;
		DFS(v , u);
	}
}

int calc(int u , int v) {
    if (H[u] > H[v]) swap(u , v);
    if (dp[u][v] > -1) {
        return dp[u][v];
    }
    if (u == v) {
        dp[u][v] = 1;
        return dp[u][v];
    }
    int lca = LCA(u , v); dp[u][v] = 0; 
    if (lca != u) {
        if (P[u][0]) {
            dp[u][v] = max(dp[u][v] , calc(P[u][0] , v));
        }
        if (P[v][0]) {
            dp[u][v] = max(dp[u][v] , calc(P[v][0] , u));
        }
        if (P[u][0] && P[v][0]) {
            dp[u][v] = max(dp[u][v] , calc(P[u][0] , P[v][0]) + 2*(a[u] == a[v]));
        }
    }
	else {
		int down = binaryLifting(u , v);
		if (P[v][0]) {
			if (P[v][0] == u) {
				dp[u][v] = max({dp[u][v] , 1ll , 2ll*(a[u] == a[v])});
			}
			else {
				dp[u][v] = max(dp[u][v] , calc(down , P[v][0]) + 2ll*(a[u] == a[v]));
				dp[u][v] = max(dp[u][v] , calc(P[v][0] , u));
			}
		}
		dp[u][v] = max(dp[u][v] , calc(down , v)); 
		
	}
	return dp[u][v];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n;
		init();
        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        for (int i = 1 ; i < n ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        H[1] = 0; 
        DFS(1 , -1);
        buildtable();
		int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				ans = max(ans , calc(i , j));
			}
		}
		cout << ans << '\n';
    }
    return 0;
}