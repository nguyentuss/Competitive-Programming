
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e4 + 7;
const int MOD = 1e9 + 7;

int f[N] , num[N] , low[N];
int timeDFS = 0;
int cut[N];
int ans[N];
int n , m;
vector<int> adj[N];
int vis[N];

void calc(int u , int father) {
    f[u] = 1; vis[u] = 1;
    for (int v : adj[u]) {
        if (v == father) continue; 
        if (!vis[v]) {
            calc(v , u); 
            f[u] += f[v];
        }
    }
}

void DFS(int u , int father , int root) {
    num[u] = low[u] = ++timeDFS;
    cerr << u << " ";
    int child = 0;
    vector<int> res;
    bool notRoot = false;
    for (int v : adj[u]) {
        if (v == father) continue;
        if (!low[v]) {
            child++;
            DFS(v , u , root);
            low[u] = min(low[u] , low[v]);
            // check root
            if (u == father) {
                if (child > 1)
                    cut[u] = true;
                res.push_back(f[v]);
            }
            else if (low[v] >= num[u]) {
                cut[u] = true;
                notRoot = true;
                res.push_back(f[v]);
            }
        }
        else {
            low[u] = min(low[u] , num[v]);
        }
    }
    // xet 1 TH nếu nó gốc đó k có cạnh nối lên => nhận THPT ở phía trên
    if (!cut[u]) return;
    if (notRoot) {
        int tt = f[root];
        for (auto x : res) {
            tt -= x;
        }
        res.push_back(tt - 1);
    }
    //cerr << u << " " << res.size() << '\n';
    vector<int> pf(res.size() + 3);
    int len = res.size();
    for (int i = 1 ; i <= len ;i ++) {
        pf[i] = pf[i - 1] + res[i - 1];
    }
    for (int i = len; i >= 1 ; i--) {
        ans[u] = ans[u] + res[i - 1]*pf[i - 1];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ;i ++) {
        sort(adj[i].begin() , adj[i].end());
        //adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) {
            calc(i , i);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!num[i]) {
            DFS(i , i , i);
        }
    }
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        sum += ans[i];
        //cout << ans[i] << " ";
    }
    long double average = sum*1.0;
    average = average/((long double)n*1.0);
    cout << fixed << setprecision(9) << average;
    return 0;
}
