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
const int MAX_N = 1e2 + 7;
const int MOD = 1e9 + 7;

int a[2*MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("ivan.inp","r",stdin);
    freopen("ivan.out","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n ;i ++) {
        cin >> a[i];
    }
    for (int i = n + 1 ; i <= 2*n ; i++) {
        a[i] = a[i - n];
    }
    int ans = 0;
    for (int k = 1 ; k <= n ; k++) {
        vector<int> b;
        b.push_back(0);
        vector<vector<int>> f(n + 1 , vector<int> (n + 1 , 0));
        int cnt = 0;
        f[0][0] = 0;
        for (int j = k + 1 ; j <= (k + n - 1) ; j++) {
            b.push_back(a[j]);
            //cerr << a[j] << " ";
            cnt++;
            if (b[cnt] % 2 == 1) f[cnt][cnt] = 1;
            else f[cnt][cnt] = 0;
        }
        //cerr << '\n';
        for (int i = n - 1 ; i >= 1 ; i--) {
            for (int j = i + 1 ; j < n ; j++) {
                f[i][j] = -inf;
                if (b[i] % 2 == 1) {
                    f[i][j] = max(f[i][j] , 1 - f[i + 1][j]);
                }
                if (b[i] % 2 == 0) {
                    f[i][j] = max(f[i][j] , 0 - f[i + 1][j]);
                }
                if (b[j] % 2 == 0) {
                    f[i][j] = max(f[i][j] , 0 - f[i][j - 1]);
                }
                if (b[j] % 2 == 1) {
                    f[i][j] = max(f[i][j] , 1 - f[i][j - 1]);
                }

            }
        }
        int aa = 0;
        if (a[k] % 2 == 1) {
            aa = 1;
        }
        if ((aa - f[1][n - 1]) > 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}