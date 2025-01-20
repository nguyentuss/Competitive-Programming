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
const int MAX_N = ;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
int f[MAX_N];
int dp[MAX_N][6];

void DFS(int u , int father) {
    f[u] = 1;
    for (auto edge : adj[u]) {  
        int v = edge.first;
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

int find_centroid(int u , int father , int root) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v != father && !check[v] && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

/*
    status = 0 : empty
    status = 1 : 00000000
    status = 2 : 00000111
    status = 3 : 11111000
    status = 4 : 11111111
*/

void DFS1(int u , int father) {
    for (auto edge : adj[u]) {
        if (v != father && !check[v]) {
            DFS1(v , u);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u);
    int u = find_centroid(u , u , u);
    DFS1(u , u);
    cnt.clear();
    check[u] = 1;
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v != father && !check[v]) {
            centroid(v , u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i < n ;i ++) {
        int u , v , c; cin >> u >> v >> c;
        adj[u].push_back(ii(v , c));
        adj[v].push_back(ii(u , c));
    }
    centroid(1 , -1);
    return 0;
}