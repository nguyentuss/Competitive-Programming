//source:: 
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 20;
const int MOD = 998244353;

int f[N][N];
int POW2[N];
int a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        POW2[0] = 1;
        for (int i = 1 ; i <= 16 ; i++) {
            (POW2[i] = POW2[i - 1] * 2)%=MOD;
        }
        f[1][0] = 1;
        for (int i = 1 ; i < n ; i++) {
            for (int j = 0 ; j <= n ; j ++) {
                if (!f[i][j]) continue;
                for (int k = 1 ; k <= j + 1 ; k++) {
                    (f[i + 1][k] += f[i][j]*POW2[k - 1])%=MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0 ; j <= n ; j++) {
            //cerr << f[n - 1][j] << " ";
            (ans += f[n][j])%=MOD;
        }
        cout << ans;
    }
    return 0;
}