#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

int f[N][2049];
vector<ii> adj[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(w , v));
        adj[v].push_back(ii(w , u));
    }
    int s , t; cin >> s >> t;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j < 2049 ; j++) {
            f[i][j] = inf;
        }
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    pq.push(ii(0 , s));
    f[s][0] = 0;
    while (!pq.empty()) {
        int u , du; tie(du , u) = pq.top();
        //cerr << u << " " << du << '\n';
        pq.pop(); 
        if (f[u][du] != du) continue;
        for (auto edge : adj[u]) {
            int w , v; tie(w , v) = edge;
            if (f[u][du] != inf && (f[v][du|w] > (f[u][du]|w))) {
                f[v][du|w] = f[u][du]|w;
                pq.push(ii(f[v][du|w] , v));
            }
        }
    }
    
    for (int i = 1 ; i < 2049 ; i++) {
        if (f[t][i] != inf) {
            cout << f[t][i]; 
            return 0;
        }
    }
    cout << -1;
    return 0;
}