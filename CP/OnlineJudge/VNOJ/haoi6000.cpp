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
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

struct query {
    int x, y , status;
};

int a[MAX_N][MAX_N];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int d[MAX_N][MAX_N][2];
int vis[MAX_N][MAX_N][2];
int n , m; 
bool check(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

// goi vis[i][j][side] là ở ô (i , j) , side = 0 thì mặt trái , side = 1 là mặt phải đã ktra hay ch

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
        }
    }
    queue<query> q;
    for (int i = 1 ; i <= m ;i++) {
        d[1][i][1] = 1;
        vis[1][i][1] = 1;
        if (a[1][i] == 0) q.push({1 , i , 0});
        else q.push({1 , i , 1});
    }
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int status = q.front().status;
        q.pop();
        int nx = x + dx[status];
        int ny = y + dy[status];
        if (check(nx , ny)) {
            if (!a[x][y] && !a[nx][ny]) {
                if (status == 0 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 2});
                }
                if (status == 1 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 3});
                }
                if (status == 2 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 0});
                }
                if (status == 3 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 1});  
                }
            }
            if (!a[x][y] && a[nx][ny]) {
                 if (status == 1 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][0] + 1;
                    q.push({nx , ny , 2});
                }
                if (status == 2 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 1});
                }
                if (status == 0 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][1] + 1;
                    q.push({nx , ny , 3});
                }
                if (status == 3 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 0});
                }

            }
            if (a[x][y] && !a[nx][ny]){
                if (status == 1 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][1] + 1;
                    q.push({nx , ny , 3});
                }
                if (status == 3 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 1});
                }
                if (status == 0 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][0] + 1;
                    q.push({nx , ny , 2});
                }
                if (status == 2 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 0});
                }
            }
            if (a[x][y] && a[nx][ny]) {
                if (status == 1 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 2});
                }
                if (status == 2 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 1});
                }
                if (status == 0 && !vis[nx][ny][1]) {
                    vis[nx][ny][1] = true;
                    d[nx][ny][1] = d[x][y][0] + 1;
                    q.push({nx , ny , 3});
                }
                if (status == 3 && !vis[nx][ny][0]) {
                    vis[nx][ny][0] = true;
                    d[nx][ny][0] = d[x][y][1] + 1;
                    q.push({nx , ny , 0});
                }
            }
        }
    }
    int ans = inf;
    int cnt = 0;
    for (int i = 1 ; i <= m ; i++) {
        if (d[n][i][0] != 0) 
            ans = min(ans , d[n][i][0]);
    }
    if (ans == inf) cout << 0 << " " << 0;
    else  {
        for (int i = 1 ; i <= m ; i++) {
            if (d[n][i][0] == ans) {
                cnt++;
            }
        }
        cout << ans << " " << cnt;
    }
    return 0;
}

// 0 : sang phai
// 1 : sang trai
// 2 : xuong duoi
// 3 : len tren
