#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int f[MAX_N][22][3];

// f[i][j][status]
// status = 0 , 1 , 2 tuong duong voi keo bua bao

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
   // freopen("hps.inp","r",stdin);
   // freopen("hps.out","w",stdout);
    int n , k ; cin >> n >> k;
    vector<char> ch;
    vector<int> a;
    a.resize(n + 1);
    ch.resize(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> ch[i];
        if (ch[i] == 'P') a[i] = 0;
        if (ch[i] == 'S') a[i] = 1;
        if (ch[i] == 'H') a[i] = 2;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= k ; j++) {
            for (int status = 0 ; status <= 2 ; status ++) {
                if (status == a[i]) f[i][j][status] ++;
                f[i + 1][j + 1][0] = max(f[i + 1][j + 1][0] , f[i][j][status]);
                f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1] , f[i][j][status]);
                f[i + 1][j + 1][2] = max(f[i + 1][j + 1][2] , f[i][j][status]);
                f[i + 1][j][status] = max(f[i + 1][j][status] , f[i][j][status]);
            }
        }
    }
    //cout << f[3][0][0];
    int ans = 0;
    for (int j = 0 ; j <= k ; j++) {
        ans = max({ans , f[n][j][0] , f[n][j][1] , f[n][j][2]});
    }
    cout << ans;
    return 0;
}