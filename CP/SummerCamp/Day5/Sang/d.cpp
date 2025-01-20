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
const int MAX_N = 1e2 + 7;
const int MOD = 1e9 + 7;

// f[i][l][r] la cach thay doi it nhat khi xet toi bit thu i trong doan [l , r] la mot day khong giam

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--){
        int n , k; cin >> n >> k;
        vector<vector<char>> a(n + 2 , vector<char> (k + 2));
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= k ; j++) {
                cin >> a[i][j];
                //cerr << a[i][j];
            }
            //cerr << '\n';
        }
        vector<vector<vector<int>>> f(k + 2 , vector<vector<int>> (n + 2 ,vector<int>(n + 2 , inf)));
        vector<vector<vector<vector<int>>>> cp(k + 2 , vector<vector<vector<int>>> (n + 2 , vector<vector<int>> (n + 2 ,vector<int>(2))));
        for (int i = 1 ; i <= k ; i++) {
            vector<int> one(n + 2);
            vector<int> zero(n + 2);
            for (int r = 1 ; r <= n ; r++) {
                one[r] = one[r - 1] + (a[r][i] == '1' ? 1 : 0);
                zero[r] = zero[r - 1] + (a[r][i] == '0' ? 1 : 0);
                for (int l = 1 ; l <= r ; l++) {
                    cp[i][l][r][0] = (r - l + 1) - (zero[r] - zero[l - 1]);
                    cp[i][l][r][1] = (r - l + 1) - (one[r] - one[l - 1]);
                }
            }
        }
        for (int h = 1 ; h <= k ; h++) {
            for (int i = 0 ; i <= (n + 1) ; i++) {
                for (int j = i ; j <= (n + 1) ; j++) {
                    f[h][j][i] = 0;
                }
            }
        }
        for (int i = 0 ; i <= n + 1 ; i++) {
            for (int j = 0 ; j <= n + 1; j++) {
                f[k + 1][i][j] = 0;
            }
        }
        for (int i = k ; i >= 1 ; i --) {
            for (int r = 1 ; r <= n ; r++) {
                for (int l = 1 ; l <= r ; l++) {
                    f[i][l][r] = min(f[i][l][r] , f[i + 1][l][r] + cp[i][l][r][1]);
                    for (int t = l ; t <= r ; t++) {
                        f[i][l][r] = min(f[i][l][r] , f[i + 1][l][t] + f[i + 1][t + 1][r] + cp[i][l][t][0] + cp[i][t + 1][r][1]);
                    }
                }
            }
        }
        cout << f[1][1][n] << '\n';
    }
    return 0;
}