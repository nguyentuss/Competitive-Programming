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

int dx[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
int dy[] = {1 , -1 , 2 , -2 , 2 , -2 , 1 , -1};

bool check(int x , int y) {
    return (0 <= x && x < 4*MAX_N && 0 <= y && y < 2*MAX_N);
}

int tt(int x) {
    return (x + 3000);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int xm , ym , xt , yt; cin >> xm >> ym >> xt >> yt;
    int status; cin >> status;
    queue<ii> q;
    vector<vector<int>> d(4*MAX_N , vector<int> (2*MAX_N , -1));
    q.push(ii(tt(xm) , ym + 1000));
    d[tt(xm)][ym + 1000] = 0;
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0 ; i < 8 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx , ny) && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                //cerr << xm << " " << ym << " " << d[xm][ym] << '\n';
                q.push(ii(nx , ny));
            }  
        }
    }
    //if (status == 0) d[tt(xm)][tt(ym)] = 2;
    int ans = inf;
    bool found = false;
    for (int i = tt(xt) - status; i >= 0; i--) {
        if (status == 0) {
            if (d[i][yt + 1000] <= (tt(xt) - i + 1)) {
                //cerr << i << " " << d[i][tt(yt)] << '\n';
                int x = tt(xt) - i + 1; 
                if ((abs(x - d[i][yt + 1000]))%2 == 0) {
                    found = true;
                    ans = min(ans , x);
                }
            }
        }
        else {
            if (d[i][yt + 1000] <= (tt(xt) - i)) {
                int x = tt(xt) - i;
                if ((abs(x - d[i][yt + 1000]))%2 == 0) {
                    found = true;
                    ans = min(ans , x);
                }
            }
        }
    }
    if (found) {
        cout << "YES" << '\n';
        cout << ans;
    }
    else cout << "NO";
    return 0;
}
