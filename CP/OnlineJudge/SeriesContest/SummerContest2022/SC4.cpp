#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 5e3 + 7;
const int MOD = 1e9 + 7;

int f[MAX_N][4];
int a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("SC4.inp","r",stdin);
    freopen("SC4.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < 4 ; j++) {
                f[i][j] = 0;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            f[i][0] = 1;
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = i - 1 ; j >= 1 ; j--){
                for (int k = 1 ; k < 4 ; k++) {    
                    f[i][k] += (a[i] > a[j] ? f[j][k - 1] : 0);
                }
            }
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            ans += f[i][3];
        }
        cout << ans << '\n';
    }

    return 0;
}