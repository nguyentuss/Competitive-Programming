#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD (int) (1e9 + 7)

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , m; cin >> n >> m;
    vector<vector<int>> f; f.assign(n + 1 , vector<int> (m + 1 , 0));
    vector<int> a; a.assign(n + 1 , 0);
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (m < a[i]) {
            cout << 0;
            return 0;
        }
        if ((m - a[i] - 1) >= 0) { 
            // mở mới
            (f[i][m - a[i]] += f[i - 1][m - a[i] - 1])%=MOD;
        }
        // tạo 1 đoạn chính mình
        (f[i][m - a[i]] += f[i - 1][m - a[i]])%=MOD;
        // lấy 1 đoạn và đóng nó lại
        if ((m - a[i] + 1) <= m)
        (f[i][m - a[i]] += f[i - 1][m - a[i] + 1]*(m - a[i] + 1))%=MOD;
        // thêm vào
        (f[i][m - a[i]] += f[i - 1][m - a[i]]*(m - a[i]))%=MOD;
    }
    if (a[n] == m || (m == (a[n] + 1))) {
        cout << f[n][m - a[n]];
    }
    else cout << 0;
    return 0;
}