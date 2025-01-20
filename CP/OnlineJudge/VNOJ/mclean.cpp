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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

char a[21][21];
int d[21][21];
int f[12][1 << 11];
int dx[] = {0 , 0 , -1 , 1};
int dy[] = {1 , -1 , 0 , 0};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n ,m;
    while (cin >> m >> n && n && m) {
        ii start; 
        deque<ii> pos;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'o') start = ii(i , j);
                if (a[i][j] == '*') {
                    pos.push_back(ii(i , j)); 
                }
            }
        }
        pos.push_front(start);
        for (int i = 0 ; i < pos.size() ; i++) {
            queue<ii> q;
            vector<vector<int>> dist(n + 1 , vector<int>(m + 1 , inf));
            q.push(ii(pos[i].fi , pos[i].se));
            dist[pos[i].fi][pos[i].se] = 0;
            while (!q.empty()) {
                int x = q.front().fi;
                int y = q.front().se;
               //cerr << x << " " << y << '\n';
                q.pop();
                for (int j = 0 ; j < 4 ; j++) {
                    int newx = x + dx[j];
                    int newy = y + dy[j];
                    if (1 <= newx && newx <= n && 1 <= newy && newy <= m && a[newx][newy] != 'x' && dist[newx][newy] > (dist[x][y] + 1)) {
                        dist[newx][newy] = dist[x][y] + 1;
                        q.push(ii(newx , newy));
                    }
                }
            }
            for (int j = 0 ; j < pos.size() ; j++) {
                d[i + 1][j + 1] = d[j + 1][i + 1] = dist[pos[j].fi][pos[j].se];
            }
        }
        int len = pos.size();
        for (int i = 1 ; i <= len ; i++) {
            for (int mask = 0 ; mask < (1 << len) ; mask++) {
                f[i][mask] = inf;
            }
        }
        f[1][1] = 0;
        for (int mask = 1 ; mask < (1 << len) ; mask++) {
            for (int i = 1 ; i <= len ; i++) {
                if (f[i][mask] != inf) {
                    for (int j = 1 ; j <= len ; j++) {
                        if (!(mask & (1 << (j - 1)))) {
                            f[j][mask|(1 << (j - 1))] = min(f[j][mask|(1 << (j - 1))] , f[i][mask] + d[i][j]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 1 ; i <= len ;i ++) {
            ans = min(ans , f[i][(1 << len) - 1]);
        }
        if (ans == inf) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}