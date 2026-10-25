#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e3 + 7)
#define ii pair<int , int>
#define f first
#define s second

int n , m; 
int a[MAX_N][MAX_N];
int s , t , k , c;
int w[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> s >> t >> k >> c;
    for (int i = 1 ; i <= c ; i++) {
        cin >> w[i];
    }
    for (int i = 1 ; i <= m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = a[v][u] = c;
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    pq.push(ii(s , 0));
    vector<int> dist(MAX_N , 0);
    while (!pq.empty()) {
        int u = q.top().s;
        int di = q.top().f;
        for (auto v : adj[u]) {
            if (a[u][v])
        }
    }

    return 0;
}