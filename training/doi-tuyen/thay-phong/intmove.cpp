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
const int MAX_N = 100;
const int MOD = 1e9 + 7;

int vis[60][60];
int dis[60][60];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); 
    queue<ii> q;
    q.push(ii(0 , 0));
    vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0 ; i <= 50 ; i++) {
            for (int j = 0 ; j <= 50 ; j++) {
                if (!vis[i][j]) {
                    int tmp = (x - i)*(x - i) + (y-j)*(y-j);
                    int tm = sqrt(tmp);
                    if ((tm*tm) == tmp) {
                        vis[i][j] = 1;
                        dis[i][j] = dis[x][y] + 1;
                        q.push(ii(i , j));
                    }
                }
            }
        }
    }
    int n; cin >> n;
    while (n--) {
        int x , y; cin >> x >> y;
        cout << dis[x][y] << '\n';
    }
    return 0;
}