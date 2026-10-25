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
const int MAX_N = 1e5 + 7 ;
const int MOD = 1e9 + 7;

int f[MAX_N];
int up[MAX_N];
vector<int> adj[MAX_N];
int tr[MAX_N] , tr1[MAX_N];


void DFS1(int u , int father) {
    vector<ii> arr;
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father) {
            DFS1(v , u);
            arr.push_back(ii(f[v] , v));
        }
    }
    sort(arr.begin() , arr.end());
    if (arr.size() >= 2)
        f[u] = arr[0] + arr[1];
    else f[u] = arr[0];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i < n ; i++) {
        int u , v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ;i ++) {
        f[i] = 1;
    }
    up[1] = 1;
    DFS1(1 , -1);
    DFS2(1 , -1);
    int ans = 0;
    int pos = 0;
    bool status = 0;
    for (int i = 1 ; i <= n ;i ++) {
        cout << f[i] << " " << up[i] << '\n';
        if (ans < f[i]) ans = f[i] , pos = i , status = 0;
        if (ans < up[i]) ans = up[i] , pos = i , status = 1;
    }
    vector<int> rb;
    if (status == 0) {
        int x = ans;
        rb.push_back(pos);
        int pp = pos;
        while (--x) {
            pp = tr[pp];
            rb.push_back(pp);
        }
    }
    if (status == 1) {
        int x = ans;
        rb.push_back(pos);
        int pp = pos;
        while (x--) {
            pp = tr1[pp];
            rb.push_back(pp);
        }
    }
    for (auto x : rb) {
        cout << x << " ";
    }
    return 0;
}