//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int f[N][5];
int sz[N][5];
int g[N][5];
int szup[N][5];
int n , k;
vector<int> adj[N];


void DFS1(int u , int father) {
    sz[u][0] = 1;
    for (int v : adj[u]) {
        if (v != father) {
            DFS1(v , u);
            for (int j = 0 ; j < k ; j++) {
                f[u][(j + 1)%k] += f[v][j] + (!j ? sz[v][j] : 0) ;
                sz[u][(j + 1)%k] += sz[v][j];
            }
        }
    }
}

void DFS2(int u , int father) {
    //szup[u][0] = 1;
    for (int j = 0 ; j < k ; j++) {
        for (int v : adj[u]) {
            int tmp = f[u][j];
            if (v != father) {
                szup[v][(j + 1)%k] = sz[u][j] - sz[v][(j - 1 + k)%k];     
                szup[v][(j + 1)%k] += szup[u][j];
                g[v][(j + 1)%k] += g[u][j] + (!j ? szup[u][j] : 0);
                // if (v == 4 && j == 0)
                //     cerr << f[u][j] << " " << f[v][(j - 1 + k)%k] << " " << sz[u][j] <<  " " << sz[v][(j - 1 + k)%k] << '\n';
                g[v][(j + 1)%k] = g[v][(j + 1)%k] + f[u][j] - f[v][(j - 1 + k)%k] - (!((j - 1 + k)%k) ? sz[v][0] : 0) + (!j ? (sz[u][j] - sz[v][(j - 1 + k)%k]) : 0);
            }
        }
    }
    for (int v : adj[u]) {
        if (v != father) {
            DFS2(v , u);
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0 ; i < n - 1 ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    DFS1(1 , -1);
    DFS2(1 , -1);    
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 0 ; j < k ; j++) {
    //         cout << g[i][j] << " ";
    //         cerr << sz[i][j] << " ";
    //     }
    //     cout << '\n';
    //     cerr << '\n';
    // }
    // cout<<sz[1][0] - sz[3][1];
    int ans = 0; 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < k ; j++) {
            ans = ans + f[i][j] + g[i][j];
        }
    }
    cout << ans / 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}   