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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

int even[MAX_N];
vector<int> adj[MAX_N];
int odd[MAX_N];
int a[MAX_N];
vector<int> one , zero;
vector<int> ans(MAX_N , inf);
int n;

void calc(int type) {
    vector<int> d(MAX_N , inf);
    vector<int> vis(MAX_N , false);
    queue<int> q;
    if (type == 0) {
        for (int i = 1 ; i <= n ; i ++) {
            if (odd[i]) {
                d[i] = 0;
                vis[i] = true;
                q.push(i);
            }
        }
    }
    else {
        for (int i = 1 ; i <= n ; i++) {
            if (even[i]) {
                d[i] = 0;
                vis[i] = true;
                q.push(i);
            }
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop(); 
        for (auto v : adj[u]) {
            if (!vis[v]) {
                d[v] = d[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (type == 0 && even[i]) {
            ans[i] = min(ans[i] , d[i]);
        }
        if (type == 1 && odd[i]) {
            ans[i] = min(ans[i] , d[i]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    set<int> s;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] & 1) odd[i] = 1;
        else even[i] = 1;
    }   
    for (int i = 1 ; i <= n ;i ++) {
        if ((i - a[i]) >= 1) {
            adj[i - a[i]].push_back(i); 
        } 
        if ((i + a[i]) <= n) {
            adj[i + a[i]].push_back(i);
        }
    }
    calc(0);
    calc(1);
    for (int i = 1 ; i <= n ; i++) {
        if (ans[i] == inf) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    return 0;
}