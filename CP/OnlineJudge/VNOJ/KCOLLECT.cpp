#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e9 + 7;
const int N = 1e4 + 7;
const int MOD = 1e9 + 7;

int n , m;
int a[N];
char b[107][107];
int num[N] , low[N] , tail[N];
int timelines = 0;
stack<int> s;
vector<int> adj[N] , g[N];
vector<int> topo;
int mark[N];
int vis[N];
int sum_SCC[N];
int SCC = 0;
int detected[N];
int f[N];

int getNode(int i , int j) {
    return ((i - 1)*m + j);
}

bool check(int x , int y) {
    if (b[x][y] == '#') return false;
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void DFS(int u) {
    num[u] = low[u] = ++timelines;
    s.push(u);
    for (auto v : g[u]) {
        if (detected[v]) continue;
        if (!num[v]) {
            DFS(v);
            low[u] = min(low[u] , low[v]);
        }
        else {
            low[u] = min(low[u] , num[v]);
        }
    }
    // nếu mà là SCC
    if (low[u] == num[u]) {
        SCC++;
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            mark[x] = SCC;
            detected[x] = true;
            sum_SCC[SCC] += a[x];
            if (x == u) break;
        }
    }
}

void DFS_1(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
    topo.push_back(u);
    vis[u] = 2;
}

int calc(int u) {
    if (!adj[u].size()) return sum_SCC[u];
    if (f[u] != -1) return f[u];
    int res = -1;
    for (auto v : adj[u]) {
        res = max(res , calc(v) + sum_SCC[u]);
    }
    return f[u] = res;

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            char x = b[i][j];
            int u = getNode(i , j);
            if ('0' <= x && x <= '9') a[u] = x - '0';
            if (x == '#') a[u] = -inf;
            if (x == '#') continue;
            if (check(i , j + 1)) g[u].push_back(getNode(i , j + 1));
            if (check(i + 1 , j)) g[u].push_back(getNode(i + 1 , j));
            if (x == 'W') {
                if (check(i , j - 1)) {
                    g[u].push_back(getNode(i , j - 1));
                }
            }
            if (x == 'N') {
                if (check(i - 1 , j)) {
                    g[u].push_back(getNode(i - 1 , j));
                }
            }
        }
    }
    /*for (int i = 1 ; i <= n*m ; i++) {
        if (g[i].size()) {
            cout << i << ":";
            for (auto x : g[i]) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }*/
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= m ; j++) {
            int u = getNode(i , j);
            if (b[i][j] == '#') continue;
            if (!num[u]) DFS(u);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            int u = getNode(i , j);
            if (b[i][j] == '#') continue;
            for (auto v : g[u]) {
                if (mark[u] != mark[v]) {
                    adj[mark[u]].push_back(mark[v]);
                }
            }
        }
    }
    for (int i = 1 ; i <= SCC ; i++) {
        if (!vis[i]) {
            DFS_1(i);
        }
    }
    reverse(topo.begin() , topo.end());
    for (int i = 1 ; i <= SCC ; i++) f[i] = -1;
    /*for (int i =1 ; i <= SCC ; i++) {
        cout << sum_SCC[i] << " ";
    }
    cout << '\n';
    for (auto x : topo) {
        cout << x << " ";
    }*/
    cout << calc(mark[getNode(1 , 1)]);
    return 0;
}
