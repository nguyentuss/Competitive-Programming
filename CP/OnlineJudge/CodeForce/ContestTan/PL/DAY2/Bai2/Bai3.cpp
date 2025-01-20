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

int sz[N];
int a[N];
int cnt[N];
int res[N];
int f[N];
vector<int> adj[N];
int n;
int c[N];
int b[N];

void calc(int u , int father) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != father) {
            calc(v , u);
            sz[u] += sz[v];
        }
    }
}

void update(int u , int father , int val , int &maxi) {
    res[cnt[c[u]]] -= a[u];
    cnt[c[u]] += val;
    res[cnt[c[u]]] += a[u];
    maxi = max(maxi , cnt[c[u]]);
    for (int v : adj[u]) {
        if (v != father) {
            update(v , u , val , maxi);
        }
    }
}

int DFS(int u , int father) {
    int bigChild = -1;
    int maxi = 1;
    for (int v : adj[u]) {
        if (v != father) {
            if (bigChild == -1 || (sz[v] > sz[bigChild])) bigChild = v;
        }
    }
    for (int v : adj[u]) {
        if (v != father && v != bigChild) {
            DFS(v , u);
            update(v , u , -1 , maxi);
        }
    }
    if (bigChild != -1) {
        maxi = max(maxi , DFS(bigChild , u));
    }
    res[cnt[c[u]]] -= a[u];
    cnt[c[u]] += 1;
    res[cnt[c[u]]] += a[u];
    maxi = max(maxi , cnt[c[u]]);
    for (int v : adj[u]) {
        if (v != father && v != bigChild) {
            update(v , u , 1 , maxi);
        }
    }
    f[u] = res[maxi];
    return maxi;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i]; 
        b[i] = a[i];
    }
    map<int , int> mp; 
    sort(b + 1 , b + 1 + n); 
    int curNode = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (!mp[b[i]]) {
            curNode++;
        }
        mp[b[i]] = curNode;
    }
    for (int i = 1 ; i <= n ; i++) 
        c[i] = mp[a[i]];
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc(1 , -1);
    DFS(1 , -1);
    for (int i = 1 ; i <= n ; i++) {
        cout << f[i] << " ";
    }
    return 0;
}
