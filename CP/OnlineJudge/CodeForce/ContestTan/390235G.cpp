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

int n , M;
vector<int> adj[MAX_N];
int down[MAX_N];

void DFS(int u , int father) {
    down[u] = 1;
    vector<int> a;
    a.push_back(0);
    for (auto v : adj[u]) {
        if (v != father) {
            DFS(v , u);
            a.push_back(v);
        }
    }
    vector<vector<int>> f(a.size() + 1 , vector<int> (2 , 0));
    vector<vector<int>> f1(a.size() + 1 , vector<int> (2 , 0));
    f[0][0] = 1;
    for (int i = 1 ; i < a.size() ; i++) {
        f[i][1] = down[a[i]]*(f[i - 1][0] + f[i - 1][1]);
        f[i][0] = f[i - 1][0] + f[i - 1][1];
    }
    cerr << u << " " << '\n';
    for (int i = 1 ; i < a.size() ;i ++) {
        cerr << f[i][1] << " " << f[i][0] << '\n';
    }
    down[u] = f[a.size() - 1][0] + f[a.size() - 1][1];
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> M;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1 , -1);
    for (int i = 1 ; i <= n ;i ++) {
        cout << i << " " << down[i] << " " << down[i] + down[i]*(down[1] - down[i])<< '\n';
    }
    return 0;
}