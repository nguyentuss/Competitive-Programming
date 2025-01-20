#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e2 + 7;
const int MOD = 1e9 + 7;

int n , m;
vector<int> adj[N];
int low[N] , tail[N] , num[N] , vis[N];
int timelines = 0;
int ans = 0;
void DFS(int u , int father) {
    low[u] = num[u] = ++timelines;
    for (int v : adj[u]) {
        if (v == father) continue;
        if (!num[v]) {
            //cout << u << " " << v << " " << father << '\n';
            DFS(v , u);
            low[u] = min(low[u] , low[v]);
        }
        else {
            low[u] = min(low[u] , num[v]);
        }
    }
    tail[u] = timelines;
}

bool checkin(int u , int v) {
    return (low[v] <= num[u] && num[u] <= tail[v]);
}

bool check(int a , int b , int u) {
    if (checkin(a , u) && !checkin(b , u)) return true;
    if (checkin(b , u) && !checkin(a , u)) return true;
    return false;
}

void calc(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (num[v] == low[v]) {
                for (int i = 1 ; i <= n ;i ++) {
                    for (int j = 1 ; j < i ; j++) {
                        if (check(i , j , v)) {
                            ans ++;
                        }
                    }
                }
            }
            calc(v);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (!num[i]) {
            DFS(i , i);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            calc(i);
        }
    }
    cout << ans;
    return 0;
}
