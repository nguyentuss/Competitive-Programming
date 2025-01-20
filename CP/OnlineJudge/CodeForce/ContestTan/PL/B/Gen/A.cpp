#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

int a[N][N];
int vis[N][N];
int sum[N*N];
int mark[N][N];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
vector<ii> adj[N*N];
int n , m;

bool check(int x , int y) {
   return (1 <= x && x <= n && 1 <= y && y <= m);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    //freopen("A.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
        }
    }
    queue<ii> q;
    int curNode = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (!vis[i][j]) {
                curNode++;
                bool isone = false;
                if (a[i][j] == 1) isone = true;
                sum[curNode] = (isone ? 0 : a[i][j]);
                q.push(ii(i , j));
                mark[i][j] = curNode;
                vis[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().fi;
                    int y = q.front().se;
                    q.pop();
                    for (int k = 0 ; k < 4 ; k++) {
                        int u = x + dx[k];
                        int v = y + dy[k];
                        if (check(u , v) && !vis[u][v] && a[u][v] == a[i][j]) {
                            vis[u][v] = true;
                            mark[u][v] = curNode;
                            sum[curNode] = sum[curNode] + (isone ? 0 : a[u][v]);
                            q.push(ii(u , v));
                        }
                    }
                }

            }
        }
    }
    //cout << "DEBUG" << endl;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            for (int k = 0 ; k < 4 ; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (check(x , y) && mark[i][j] != mark[x][y]) {
                    adj[mark[i][j]].push_back(ii(mark[x][y] , sum[mark[x][y]]));
                    adj[mark[x][y]].push_back(ii(mark[i][j] , sum[mark[i][j]]));
                }
            }
        }
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    vector<int> d(N*N , inf);
    d[1] = 0;
    pq.push(ii(0 , 1));
    while (!pq.empty()) {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du != d[u]) continue;
        for (ii edge : adj[u]) {
            int v = edge.fi;
            int w = edge.se;
            if (d[v] > (d[u] + w)) {
                d[v] = d[u] + w;
                pq.push(ii(d[v] , v));
            }
        }
    }
//    for (int i = 1;  i <= n ; i++) {
//        for (int j = 1; j <= m ; j++) {
//            cout << mark[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    for (int i = 1 ; i <= n*m ; i++) {
//        cout << d[i] << " ";
//    }
    cout << d[mark[n][m]];
    return 0;
}
