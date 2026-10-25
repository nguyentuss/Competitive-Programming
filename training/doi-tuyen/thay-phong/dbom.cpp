#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e2 + 7)
#pragma GCC optimize("Ofast")
#define ii pair<int , int>
#define x first
#define y second
int n , k; 
bool inside(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<vector<int>> a(n + 1 , vector<int>(n + 1 , 0));
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1; j <= n ; j++) {
            char x; cin >> x;
            a[i][j] = (x == 'X' ? 1 : 0);
        }
    }
    vector<vector<int>> f(n + 2 , vector<int> (n + 2 , 0));
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= n ; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }
    vector<int> dx(4);  
    vector<int> dy(4);
    dx[0] = 0 , dx[1] = 0 , dx[2] = -1 , dx[3] = 1;
    dy[0] = 1 , dy[1] = -1 , dy[2] = 0 , dy[3] = 0;
    vector<vector<bool>> vis(n + 2 , vector<bool> (n + 2 , 0));
    vector<vector<int>> b(n + 2 , vector<int> (n + 2 , 0));
    vector<int> sl(n*n + 1 , 0);
    int num = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (!vis[i][j] && !a[i][j]) {
                num++;
                b[i][j] = num; vis[i][j] = true;
                int cnt = 1;
                queue<ii> q; q.push(ii(i , j));
                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();
                    for (int pos = 0 ; pos < 4 ; pos++) {
                        int newx = x + dx[pos];
                        int newy = y + dy[pos];
                        if (inside(newx , newy) && !vis[newx][newy] && !a[newx][newy]) {
                            cnt++;
                            vis[newx][newy] = true;
                            q.push(ii(newx , newy));
                            b[newx][newy] = num;
                        }
                    }
                }
                sl[num] = cnt;
            }
        }
    }
    int ans = 0;
    for (int i = k ; i <= n ; i++) {
        for (int j = k ; j <= n ; j++) {
            vector<bool> m(10*n , 0);
            int limi = i - k + 1;
            int limj = j - k + 1;
            set<int> s;
            for (int x = limi ; x <= i ; x++) {
                if (b[x][j + 1]) s.insert(b[x][j + 1]);
                if (b[x][limj - 1]) s.insert(b[x][limj - 1]);
            }
            for (int x = limj ; x <= j ; x++) {
                if (b[i + 1][x]) s.insert(b[i + 1][x]);
                if (b[limi - 1][x]) s.insert(b[limi - 1][x]);
            }   
            int cnt = 0;
            for (auto x : s) {
                cnt += sl[x];
                m[x] = true;
            }    
            int minus = 0;
            for (int x = limi ; x <= i ; x++) {
                for (int y = limj ; y <= j ; y++) {
                    minus += (m[b[x][y]] ? 1 : 0);
                }
            }
            
            cnt = cnt - minus + k*k;
            //cout << f[i][j];
            //cnt = cnt + f[i][j] - f[i][limj - 1] - f[limi - 1][j] + f[limi - 1][limj - 1];
            ans = max(ans , cnt);
        }
    }
    cout << ans;
    return 0;
}