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
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int value = 5;

int a[MAX_N];
bool vis[MAX_N];
bool found = true;
vector<ii> val[2];
vector<ii> adj[MAX_N];
bool ans[MAX_N];
vector<int> store[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= q ;i ++) {
        int u , v , k; cin >> u >> v >> k;
            adj[u].push_back(ii(v , k));
            adj[v].push_back(ii(u , k));
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) {
            a[i] = 1;
            DFS(i , 0);
        }
    }
    for (int i = 1 ; i <= n ; i++) {

    }
    for (int i = 1 ; i <= n ; i++) {
        for (auto x : adj[i]) {
            int w = x.se;
            int v = x.fi;
            if (w == 1) {
                if (!abs(a[i] - a[v])) found = false;
            }  
            else {
                if (abs(a[i] - a[v])) found = false;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!a[i]) found = false;
    }
    if (!found) {
        cout << -1; 
        return 0;
    }
    for (int i = 1 ; i <= n ;i ++) {
        cout << a[i] << " ";
    }
    return 0;
}