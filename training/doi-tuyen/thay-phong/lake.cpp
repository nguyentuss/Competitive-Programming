#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e4 + 7 ;
const int MOD = 1e9 + 7;

int sz[MAX_N];
int root[MAX_N];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

void init() {
    for (int i = 1 ; i < MAX_N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u) {
    return (root[u] == u) ? u : root[u] = find_root(root[u]);
}

void merge(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v); 
        root[v] = u;
        sz[u] += sz[v];
    }
    return;
}
int num[107][107];
int a[107][107];
int n , m , k;

bool check(int x, int y) {
    return (1 <= x && x <= m && 1 <= y && y <= n);
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    init();
     cin >> m >> n >> k;
    int cnt = 0;
    for (int i = 1 ; i <= m ;i ++) {
        for (int j = 1 ; j <= n ; j++) {
            num[i][j] = ++cnt;
        }
    }
    for (int i = 1 ; i <= k ; i++) {
        int x , y; cin >> x >> y;
        for (int j = 0 ; j < 4 ; j++) {
            if (check(x + dx[j] , y + dy[j]) && a[x + dx[j]][y + dy[j]]) {
                merge(num[x][y] , num[x + dx[j]][y + dy[j]]);
            }
        }
        a[x][y] = 1;
    } 
    int ans = 0;
    for (int i = 1; i <= n*m ; i++) {
        ans = max(ans , sz[i]);
    }
    cout << ans; 
    return 0;
}