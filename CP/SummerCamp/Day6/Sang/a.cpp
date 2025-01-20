#include <bits/stdc++.h>

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

int f[MAX_N];
int dp[MAX_N];
int sum[MAX_N];
vector<int> adj[MAX_N];
map<int , int> m;
map<int , int> tmp;
int ans = 0;
bool vis[MAX_N];
int n , k; 

void DFS(int u , int father) {
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father && !vis[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

int find_centroid(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (!vis[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void DFS2(int u , int father) {
    m[dp[u]]++; 
    for (auto v : adj[u]) {
        if (v != father && !vis[v]) {
            dp[v] = dp[u] + 1;
            DFS2(v , u);
        }
    }
}

void DFS1(int u , int father) {
    tmp[dp[u]]++;
    for (auto v : adj[u]) {
        if (v != father && !vis[v]) {
            DFS1(v , u);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u); 
    u = find_centroid(u , u , u); 
    dp[u] = 0;
    m.clear();
    DFS2(u , u);
    int cc = 0;
    for (auto it : m) {
        int x = k - it.fi;
        int val = it.se; 
        if (it.fi == x) {
            ans = ans + val*(val - 1)/2;
            cc = cc + val*(val - 1)/2;
        }
        else {
            ans = ans + val*m[x];
            cc = cc + val*m[x];
        }
        m[it.fi] = 0;
    }
    vis[u] = 1;
    int minus = 0;
    for (auto v : adj[u]) {
    if (!vis[v]) {
            tmp.clear();
            DFS1(v , v);
            for (auto it : tmp) {
                //cerr << it.fi << " " << it.se << '\n';;
                if ((k - it.fi) < 0) continue;
                int x = k - it.fi;
                int val = it.se;
                if (it.fi == x) {
                    minus = minus + val*(val - 1)/2;
                }
                else {
                    minus = minus + val*tmp[x];
                }
                tmp[it.fi] = 0;
            }
            //cerr << '\n';
        }
    }
    //cerr << cc - minus << '\n';
    ans -= minus;
    for (auto v : adj[u]) {
        if (!vis[v]) centroid(v , u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    centroid(1 , -1);
    cout << ans;
    return 0; 
}