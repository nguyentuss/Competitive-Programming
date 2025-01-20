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
const int MAX_N = 1e3 + 5e2 + 7;
const int MOD = 1e9 + 7;

char a[MAX_N][MAX_N];
int n ,m;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int d[MAX_N][MAX_N];

bool check(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

vector<ii> start;

void calc() {
    set<int> s;
    s.insert(0);
    queue<ii> q;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            s.insert(d[i][j]);
        }   
    }
    vector<int> X(s.begin() , s.end());
    int l = 0 , r = X.size() - 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r)>>1;
        q.push(start[0]);
        vector<vector<int>> vis(n + 1 , vector<int> (m + 1 , 0));
        vis[start[0].fi][start[0].se] = true;
        while (!q.empty()) {
            int x = q.front().fi;
            int y = q.front().se;
            q.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx , ny) && !vis[nx][ny] && d[nx][ny] <= mid) {
                    vis[nx][ny] = true;
                    q.push(ii(nx , ny));
                }
            }
        }
        if (vis[start[1].fi][start[1].se] == true) {
            r = mid - 1; 
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    queue<ii> q;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L') start.push_back(ii(i , j));
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            bool found = false;
            for (int k = 0 ; k < 4 ; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (a[i][j] != 'X' && check(nx , ny) && a[nx][ny] == 'X') {
                    found = true;
                }
            }
            if (found) {
                //cerr << i << " " << j << '\n';
                q.push(ii(i , j));
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx , ny) && a[nx][ny] == 'X' && !d[nx][ny]) {
                d[nx][ny] = d[x][y] + 1;
                q.push(ii(nx , ny));
            }
        }
    }
    calc();
    
    return 0;
}