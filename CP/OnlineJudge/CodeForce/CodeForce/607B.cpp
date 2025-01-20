#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;

int f[N][N];
int a[N];
main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            f[i][j] = inf;
        }
    }
    for (int i = 0 ; i <= n ;i ++) {
        f[i][i] = 1;
        f[i + 1][i] = 0;
    }
    // f[i][j] cap nhat cho f[i - 1][j + 1]
    for (int j = 1 ; j <= n ; j++) {
        for (int i = j - 1 ; i >= 1 ; i--) {
            f[i][j] = f[i][j - 1] + 1;
            for (int k = j - 1 ; k >= i ; k--) {
                if (a[j] == a[k]) {
                    if (j == (k + 1)) {
                        f[i][j] = min(f[i][j] , f[i][k - 1] + 1);
                    }
                    else {
                        f[i][j] = min(f[i][j] , f[i][k - 1] + f[k + 1][j - 1]);
                    }
                }
            }
        }
    }
    cout << f[1][n];
    return 0;
}