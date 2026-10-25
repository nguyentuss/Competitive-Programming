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
const int MAX_N = 5e3 + 7;
const int MOD = 1e9 + 7;

int f[2][MAX_N][2];
int dp[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    dp[0] = 1;
    for (int i = 1 ; i < 50 ; i++) {
        dp[i] = dp[i - 1] * 2ll;
    }
    for (int i = 0 ; i <= n ;i ++) {
        for (int j = 0 ; j < MAX_N ; j++) {
            for (int status = 0 ; status <= 1 ; status++) {
                f[i][j][status] = -inf;
            }
        }
    }
    // f[i][j][status] là số tiền lớn nhất khi xét tới thằng j
    // status = 0 là 0 giữ ,status = 1 là giữ
    for (int i = 1 ; i <= n ; i++) {
        int now = i & 1; 
        int prev = now ^ 1;
        int maxi1 = 0;
        int maxi2 = 0;
        string ask; cin >> ask;
        int x; cin >> x;
        //cerr << ask << " " << x << '\n';
        for (int j = 0 ; j < MAX_N ; j++) {
            maxi1 = max(maxi1 , f[prev][j][0]);
            maxi2 = max(maxi2 , f[prev][j][1]);
        }
        if (ask == "win") {
            f[now][x][1] = maxi1;
            f[now][x][0] = max(maxi1 , maxi2);
        }
        else {
            f[now][x][0] = f[prev][x][1] + dp[x];
            f[now][x][1] = max({maxi1 , maxi2});
        }
        for (int j = 0 ; j < MAX_N ; j++) {
            f[prev][j][0] = f[now][j][0];
            f[prev][j][1] = f[now][j][1];
        }
    }
    int maxi = 0;
    for (int i = 0 ; i < MAX_N; i++) {
        maxi = max({maxi , f[n&1][i][0] , f[n&1][i][1]});
    }
    cout << maxi;
    return 0;
}