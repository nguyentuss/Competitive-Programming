#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define iii pair<int , ii>

const int N = 1e5 + 7;
const int inf = 1e18;

vector<ii> adj[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int u , v, c; cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back(ii(v , c));
        //adj[v].push_back(ii(u , c));
    }
    priority_queue<iii , vector<iii> , greater<iii>> pq;
    vector<vector<int>> d(n , vector<int>(2 , inf));
    pq.push(iii(0 , ii(0 , 0)));
    d[0][0] = 0;
    while (!pq.empty()) {
        auto tm = pq.top(); 
        int du = tm.first;
        int u = tm.second.first;
        int k = tm.second.second;
        //auto [du , u , k] = pq.top();
        pq.pop();
        if (d[u][k] != du) continue;
        for (auto [v , uv] : adj[u]) {
            if (d[u][k] + uv < d[v][k]) {
                d[v][k] = d[u][k] + uv;
                pq.push(iii(d[v][k] ,ii(v , k)));
            }
            if (k == 0) {
                int c = uv/2;
                if ((d[u][k] + c) < d[v][k ^ 1]) {
                    d[v][k ^ 1] = d[u][k] + c; 
                    pq.push(iii(d[v][k ^ 1] , ii(v , k ^ 1)));
                }
            }
        }
    }
    cout << d[n - 1][1]; 

    return 0;
}