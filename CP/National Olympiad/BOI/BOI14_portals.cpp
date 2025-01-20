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
const int inf = 1e18 + 7;
const int MAX_N = 1e3 + 7 ;
const int MOD = 1e9 + 7;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

char a[MAX_N][MAX_N];
int n , m;
int neleft[MAX_N][MAX_N] , neright[MAX_N][MAX_N];
int neup[MAX_N][MAX_N] , nedown[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
vector<int> b[MAX_N][MAX_N];

bool check(int x , int y) {
    return (1 <= x && 1 <= y && x <= n && y <= m);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;   
    ii s , t;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') s = ii(i , j);
            if (a[i][j] == 'C') t = ii(i , j); 
        }
    }

    for (int i = 1 ; i <= n ; i ++) { 
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] == '#') {
                neleft[i][j] = j;
                neup[i][j] = i;
            }
            else {
                neleft[i][j] = neleft[i][j - 1];
                neup[i][j] = neup[i - 1][j];
            }
        }   
    }
    for (int i = 1 ; i <= m ; i++) {
        nedown[n + 1][i] = n + 1;
    }
    for (int i = n ; i >= 1 ; i--) {
        neright[i][m + 1] = m + 1;
        for (int j = m ; j >= 1 ; j--) {
            if (a[i][j] == '#') {
                neright[i][j] = j;
                nedown[i][j] = i;
            }
            else {
                neright[i][j] = neright[i][j + 1];
                nedown[i][j] = nedown[i + 1][j];
            }
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            b[i][j].push_back(j - neleft[i][j] - 1);
            b[i][j].push_back(neright[i][j] - j - 1);
            b[i][j].push_back(i - neup[i][j] - 1);
            b[i][j].push_back(nedown[i][j] - i - 1);
            sort(b[i][j].begin() , b[i][j].end());
            dist[i][j] = inf;
        }
    }

    priority_queue<iii , vector<iii> , greater<iii>> pq; 
    pq.push(iii(0 , s));
    dist[s.fi][s.se] = 0;
    while (!pq.empty()) {
        int w , x , y;
        w = pq.top().fi;
        x = pq.top().se.fi;
        y = pq.top().se.se;
        pq.pop(); 
        if (w != dist[x][y] || a[x][y] == '#') continue;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx , ny) && (dist[x][y] + 1) < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                pq.push(iii(dist[nx][ny] , ii(nx , ny)));
            }
        }
        int val = b[x][y][0];
        for (int i = 0 ; i < 4 ; i++) {
            int nx = 0 , ny = 0;
            if (i == 0) {
                ny = neleft[x][y] + 1;
                nx = x;
            }
            if (i == 1) {
                ny = neright[x][y] - 1;
                nx = x;
            }
            if (i == 2) {
                ny = y;
                nx = neup[x][y] + 1;
            }
            if (i == 3) {
                ny = y;
                nx = nedown[x][y] - 1;
            }
            // if (nx == 1 && ny == 4) {
            //     cerr << x << " " << y << " " << dist[x][y] + val + 1 << " " << '\n';
            // }
            if (check(nx , ny) && (dist[x][y] + val + 1) < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + val + 1;
                pq.push(iii(dist[nx][ny] , ii(nx , ny)));
            }
        }
    }
    //cout << neleft[1][1] << " " << neright[1][1] << " " << nedown[1][1] << " " << neup[1][1] << '\n';
    cout << dist[t.fi][t.se];
    return 0;
}