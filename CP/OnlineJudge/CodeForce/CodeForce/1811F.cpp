#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int n , m; 
vector<int> adj[N];
vector<int> centerFlo[N]; 
bool mark[N];
int vis[N];
int parent[N];
int cycle_str = -1 , cycle_end;
int sqrtNum;
int count_num = 0;

void init() {
    for (int i = 1 ; i <= n ; i++) {
        vis[i] = 0; 
        parent[i] = -1;
        adj[i].clear();
        centerFlo[i].clear();
        mark[i] = false;
    }
    cycle_str = -1;
}

bool DFS_1(int u , int par) {
    vis[u] = true;
    for (int v : centerFlo[u]) {
        if (v == par) continue;
        if (vis[v]) {
            cycle_end = u;
            cycle_str = v; 
            return true;
        }
        parent[v] = u;
        if (DFS_1(v , parent[v])) return true;
    }
    return false;
}

bool DFS(int u , int par) {
    vis[u] = 1;
    count_num++;
    for (int v : adj[u]) {
        if (v == par || vis[v] == 2) continue;
        if (vis[v] == 1) {
            cycle_end = u;
            cycle_str = v; 
            return true;
        }
        parent[v] = u;
        if (DFS(v , parent[v])) return true;
        vis[v] = 2;
    }
    return false;
}

bool calc(int u) {
    cycle_str = -1;
    count_num = 0;
    DFS(u , -1);
    vis[u] = 2;
    if (cycle_str == -1) return false;
    int cnt = 1;
    for (int v = cycle_end; v != cycle_str ; v = parent[v]) {
        cnt++; vis[v] = 2;
    }
    return (cnt == sqrtNum);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1 ; i <= m ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sqrtNum = sqrt(n);
        if (sqrtNum*sqrtNum != n) cout << "NO" << '\n';
        else {
            if (n + sqrtNum != m) cout << "NO" << '\n';
            else {
                int numberOfCen = 0;
                for (int i = 1 ; i <= n ; i++) {
                    if (adj[i].size() == 4) {
                        numberOfCen++;
                        mark[i] = true;
                    }
                }
                if (numberOfCen != sqrtNum) {
                    cout << "NO" << '\n';
                }
                else {
                    int tmp = 0;
                    for (int u = 1 ; u <= n ; u++) {
                        for (auto v : adj[u]) { 
                            if (mark[u] && mark[v]) {
                                tmp = u;
                                centerFlo[u].push_back(v);
                            }
                        }
                    }
                    DFS_1(tmp , -1);
                    if (cycle_str == -1) cout << "NO" << '\n';
                    else {
                        int cnt_nodeOfCen = 1;
                        vis[cycle_str] = 2;
                        for (int v = cycle_end; v != cycle_str ; v = parent[v]) {
                            cnt_nodeOfCen++;
                            vis[v] = 2;
                        }
                        if (cnt_nodeOfCen != numberOfCen) cout << "NO" << '\n';
                        else {
                            bool status = true;
                            for (int i = 1 ; i <= n ; i++) {
                                if (mark[i]) {
                                    if (!calc(i)) status = false;
                                }
                            }
                            if (status == false) cout << "NO" << '\n';
                            else cout << "YES" << '\n';
                        }
                    }
                }
            }
        }
    }
    return 0;
}