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

map<string , bool> cnt;
vector<int> adj[MAX_N];

int f[MAX_N][2];

void DFS(int u , int father) {
    if (adj.size() == 1) {
        f[u][0] = 1;
    }
    int total = 0;
    for (auto v : adj[u]) {
        if (v != father) {
            DFS(v , u);
            
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        f[i][0] = f[i][1] = inf;
    }
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    int node = 0;
    for (int i = 1 ; i <= n ; i++) {
        string s1 , s2;
        if (!cnt[s1]) cnt[s1] = ++node;
        if (!cnt[s2]) cnt[s2] = ++node;
        adj[cnt[s1]].push_back(cnt[s2]);
        adj[cnt[s2]].push_back(cnt[s1]);
    }
    DFS(1 , -1);
    return 0;
}