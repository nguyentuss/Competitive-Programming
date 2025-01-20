//https://codeforces.com/group/0eK0ZAR2j8/contest/398238/problem/D

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int n , m; 
int d[N] , f[N];
vector<ii> adj[N] , readj[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w)); 
        readj[v].push_back(ii(u , w));
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    pq.push(ii(0 , 1));
    for (int i = 1 ; i <= n ; i ++) d[i] = inf;
    d[1] = 0;
    while (!pq.empty()) {
        int u , du; tie(du , u) = pq.top();
        pq.pop();
        if (d[u] != du) continue;
        for (ii edge : adj[u]) {
            int v , w; tie(v , w) = edge;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(ii(d[v] , v));
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        f[i] = d[i];
        pq.push(ii(f[i] , i));
    }
    while (!pq.empty()) {
        int u , du; tie(du , u) = pq.top();
        pq.pop();
        if (f[u] != du) continue;
        for (ii edge : readj[u]) {
            int v , w; tie(v , w) = edge;
            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                pq.push(ii(f[v] , v));
            }
        }
    }
    for (int i = 2 ; i <= n ;i ++) {
        cout << (f[i] == inf ? -1 : f[i]) << " ";
    }
    return 0;
}