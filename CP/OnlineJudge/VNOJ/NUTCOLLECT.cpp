#include <bits/stdc++.h>

using namespace std;
 
const int inf = 1e9 + 7;
#pragma GCC optimize("Ofast")

char a[307][307];
int f[301][301][301];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int n , m;
queue<tuple<int ,int , int>> q;

bool inside(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int sx , sy ; cin >> sx >> sy;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
        }
    }
    string s; cin >> s;
    for (int pos = 0 ; pos <= s.size() ; pos++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                f[pos][i][j] = inf;
            }
        }
    }
    f[0][sx][sy] = 0;
    q.emplace(0 , sx ,sy);
    int len = s.size();
    while (!q.empty()) {
        int x , y , pos;
        tie(pos , x , y) = q.front();
        q.pop();
        if (pos == len) break;
        if (a[x][y] == s[pos] && f[pos + 1][x][y] == inf) {
            f[pos + 1][x][y] = f[pos][x][y];
            q.emplace(pos + 1 , x , y);
        } 
        for (int i = 0 ; i < 4 ; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (inside(newx , newy) && f[pos][newx][newy] == inf) {
                f[pos][newx][newy] = f[pos][x][y] + 1;
                q.emplace(pos , newx , newy);
            }
        }
    }
    int ans = inf;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            ans = min(ans , f[len][i][j]);
        }
    }
    cout << ans;
    return 0;
}

// abeqaz
// beaqza

// abeqza
// abeqaz

// ......qaab
// baaq.....