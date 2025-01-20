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
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e7 + 7;

map<int , int> cnt;
map<int , int> tmp; 
int n , k;
vector<ii> adj[MAX_N];
bool check[MAX_N];
int f[MAX_N] , dp[MAX_N] , g[MAX_N];
int lowest_K[MAX_VAL];
int low[MAX_VAL];

void DFS(int u , int father) {
    f[u] = 1;
    for (auto edge : adj[u]) {
        int v = edge.fi;
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
    return;
}

int find_centroid(int u , int father , int root){
    for (auto edge : adj[u]) {
        int v = edge.fi;
        if (!check[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void DFS1(int u , int father) {
    if (dp[u] <= k && g[u] < low[dp[u]]) {
        low[dp[u]] = g[u];
        cnt[dp[u]] = 1;
    }
    else if (dp[u] <= k && g[u] == low[dp[u]]) {
        cnt[dp[u]]++;
    }
    for (auto edge : adj[u]) {
        int v = edge.fi , w = edge.se;
        if (v != father && !check[v]) {
            dp[v] = dp[u] + w;
            g[v] = g[u] + 1;
            DFS1(v , u);
        }
    }   
    return;
}

void DFS2(int u , int father) {
    if (dp[u] <= k && g[u] == low[dp[u]]) {
        tmp[dp[u]]++;
    }
    for (auto edge : adj[u]) {
        int v = edge.fi;
        if (v != father && !check[v]) {
            DFS2(v , u);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u);
    u = find_centroid(u , u , u); 
    cnt.clear();
    dp[u] = 0;
    g[u] = 0;
    DFS1(u , u);
    for (auto it : cnt) {
        int x = k - it.fi;
        if (x < 0 || it.fi > k || x > k) continue;
        int val = it.se; 
        if (it.fi == x) {
            int tmp1 = low[it.fi];
            if (tmp1 != inf) { 
                int num = 2*tmp1;
                lowest_K[num] += val*(val - 1);
            }
        }
        else {
            int tmp1 = low[it.fi] ,tmp2 = low[x];
            if (tmp1 != inf && tmp2 != inf) {
                int num = tmp1 + tmp2;
                lowest_K[num] += val*cnt[x];
            }
        }
    }   
    check[u] = 1;
    for (auto edge : adj[u]) {
        int v = edge.fi;
        if (v != father && !check[v]) {
            tmp.clear();
            DFS2(v , v);
            for (auto it : tmp) {
                int x = k - it.fi;
                if (x < 0 || it.fi > k || x > k) continue;
                int val = it.se;
                if (it.fi == x) {
                    int tmp1 = low[it.fi];
                    if (tmp1 != inf) { 
                        int num = 2*tmp1;
                        lowest_K[num] -= val*(val - 1);
                    }
                }
                else {
                    int tmp1 = low[it.fi] ,tmp2 = low[x];
                    if (tmp1 != inf && tmp2 != inf) {
                        int num = tmp1 + tmp2;
                        lowest_K[num] -= val*tmp[x];
                    }
                }
            }
        }
    }  
    for (auto edge : adj[u]) {
        int v = edge.fi;
        if (v != father && !check[v]) {
            centroid(v , u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; 
    if (k == 1) return 0;
    for (int i = 1 ; i < n ; i++) {
        int u , v , w; cin >> u >> v >> w;
        u++ , v++;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w));
    }
    for (int i = 0 ; i < MAX_VAL ; i++) {
        low[i] = inf;
    }
    centroid(1 , -1);
    for (int i = 1 ; i < n ; i++) {
        if (lowest_K[i] >= 1) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}