#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
int n , m;
int c[MAX_N];
int sz[MAX_N] , f[MAX_N];
int s;
int last[MAX_N];

void DFS_1(int u , int father) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v != father) {
            DFS_1(v , u);
            sz[u] += sz[v];
        }
    }
}

void DFS_2(int u , int father) {
    if (sz[u] == 1) {
        f[u] = c[u];
        return;
    }
    for (auto v : adj[u]) {
        if (v != father) {
            DFS_2(v , u);
        }
    }
    int minus = 0;
    if (u != s) minus = -1;
    vector<ii> tmp;
    for (auto v : adj[u]) {
        if (v != father && sz[v] > 1) {
            tmp.push_back(ii(f[v] , v));
        }
    }
    sort(tmp.begin() , tmp.end() , greater<ii>());
    for (auto x : tmp){
        int v = x.second;
        int w = x.first;
        //cerr << v << " " << w << '\n';
        if (last[u]) {
            last[u] --;
            f[u] += f[v] + 2;
        }
    }
   
    //cerr << '\n';
    int total = 0;
    for (auto v : adj[u]) { 
        if (v != father) {
            total += last[v];
        }
    }
    //  cerr << u << ": ";
    // for (int i = 1 ; i <= n ; i++) {
    //     cerr << last[i] << " ";
    // }
    //cout << u << " " << total << '\n';
    f[u] += max(0ll , min(last[u] + minus , total))*2;
    last[u] = max(0ll , (last[u] + minus) - total);
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
        last[i] = c[i];
    }
    for (int i = 1 ; i < n ; i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;
    DFS_1(s , -1);
    DFS_2(s , -1);
    cout << f[s];
    return 0;
}