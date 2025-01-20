#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define MOD (int) (1e9 + 7)

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , m; cin >> n >> m;
    vector<int> a;
    a.assign(n + 1 , 0);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a.begin() , a.begin() + 1 + n);
    vector<vector<vector<int>>> f;
    f.assign(2, vector<vector<int>>(n + 1 , vector<int>(m + 1 , 0)));
    f[0][0][0] = 1;
    // goi f[i][j][k] la so cach chon khi xet toi i thang dau tien
    // sao cho j thang chua chia thanh nhom (co' minimum nhung kh co maximum) 
    // va tong imbalance = k 
    for (int i = 1 ; i <= n ; i++) {
        int now = i & 1;
        int prev = now ^ 1;
        for (int j = 0 ; j <= i ; j++)  {
            for (int k = 0 ; k <= m ; k++) {
                int tm = a[i] - a[i - 1];
                if ((k - tm*j) >= 0) {
                    // mở 1 mình
                    (f[now][j][k] += f[prev][j][k - tm*j])%=MOD;
                    // thêm vào 1 trong j thằng
                    (f[now][j][k] += f[prev][j][k - tm*j]*j)%=MOD;
                }
                if ((j - 1) >= 0 && (k - tm*(j - 1)) >= 0) {
                    // mở ra một cái mới
                    (f[now][j][k] += f[prev][j - 1][k - tm*(j - 1)])%=MOD;
                }
                if ((j  + 1) <= i && (k - tm*(j + 1)) >= 0) {
                    // đóng nó lại
                    (f[now][j][k] += f[prev][j + 1][k - tm*(j + 1)]*(j + 1))%=MOD;
                }
            }
        }
        f[prev].assign(n + 1 , vector<int>(m + 1 , 0));
    }
    int ans = 0;
    for (int i = 0 ; i <= m ; i++) {
        (ans += f[n&1][0][i])%=MOD;
    }
    cout << ans;
    return 0;
}