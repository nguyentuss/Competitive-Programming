#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define MAX_M (int) (3e3 + 7)

vector<int> adj[MAX_N];
int a[MAX_N];
int f[MAX_N][MAX_N];

// f[i][j] la maximum val ma i la so ngay da tham va j la dang toi nut u

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , m , c; cin >> n >> m >> c;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0 ; i < MAX_N ; i++) {
        for (int j = 1 ; j <= n ; j ++) {
            f[i][j] = -1;
        }
    }
    f[0][1] = 0;
    for (int i = 0 ; i < MAX_N ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (f[i][j] == -1) continue;
            for (auto u : adj[j]) {
                f[i + 1][u] = max(f[i + 1][u] , f[i][j] + a[u]);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < MAX_N ; i++) {
        ans = max(ans , f[i][1] - c*i*i);
    }
    cout << ans;
    return 0;
}