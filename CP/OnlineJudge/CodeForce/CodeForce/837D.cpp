#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf (int) (1e9 + 7)

int f[2][207][3607];
int n , k;  
// goi f[i][j][k] la khi ptich thua so nt ra duoc 5 nhieu nhat
// khi xet toi i thang , chon duoc j thang
// va chon co duoc k thang 2 khi nhan lai voi nhau

void init() {
    for (int i = 0 ; i <= 1 ; i++) {
        for (int j = 0 ; j <= k ; j++) {
            for (int h = 0 ; h <= 3600 ; h++) {
                f[i][j][h] = -inf;
            }
        }
    }
    for (int i = 0 ; i <= n ; i++) f[i&1][0][0] = 0;
}

int calc_2(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        x/=2;
        cnt++;
    }
    return cnt;
}

int calc_5(int x) {
    int cnt = 0;
    while (x % 5 == 0) {
        x/=5;
        cnt++;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<int> a;
    a.resize(n + 1 , 0);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    init();
    for (int i = 0 ; i < n ; i++) {
        int now = i & 1;
        int nxt = now ^ 1;
        int p_2 = calc_2(a[i + 1]);
        int p_5 = calc_5(a[i + 1]);
        for (int j = 0 ; j <= k ; j++) {
            for (int num = 0 ; num <= 3600 ; num++) {
                if (f[now][j][num] == -inf) continue;
                f[nxt][j][num] = max(f[nxt][j][num] , f[now][j][num]);
                if ((num + p_2) <= 3600 && (j + 1) <= k) {
                    f[nxt][j + 1][num + p_2] = max(f[nxt][j + 1][num + p_2] , f[now][j][num] + p_5);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= 3600 ; i++) {
        if (f[n&1][k][i] != -inf) {
            cerr << i << " " << f[n&1][k][i] << '\n';
            ans = max(ans , min(i , f[n&1][k][i]));
        }
    }
    init();
    for (int i = 0 ; i < n ; i++) {
        int now = i & 1;
        int nxt = now ^ 1;
        int p_2 = calc_2(a[i + 1]);
        int p_5 = calc_5(a[i + 1]);
        for (int j = 0 ; j <= k ; j++) {
            for (int num = 0 ; num <= 3600 ; num++) {
                if (f[now][j][num] == -inf) continue;
                f[nxt][j][num] = max(f[nxt][j][num] , f[now][j][num]);
                if ((num + p_5) <= 3600 && (j + 1) <= k) {
                    f[nxt][j + 1][num + p_5] = max(f[nxt][j + 1][num + p_5] , f[now][j][num] + p_2);
                }
            }
        }
    }
    for (int i = 0 ; i <= 3600 ; i++) {
        if (f[n&1][k][i] != -inf) {
              cerr << i << " " << f[n&1][k][i] << '\n';
            ans = max(ans , min(i , f[n&1][k][i]));
        }
    }
    cout << ans;
    return 0;
}