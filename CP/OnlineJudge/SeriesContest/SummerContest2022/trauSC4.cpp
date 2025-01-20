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
    //freopen("SC4.inp","r",stdin);
    //freopen("SC4.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 4 ; i <= n ; i++) {
            for (int j = i - 1; j >= 1 ; j--) {
                for (int k = j - 1 ; k >= 1 ; k--) {
                    for (int h = k - 1 ; h >= 1 ; h--) {
                        if (a[i] > a[j] && a[j] > a[k] && a[k] > a[h]) {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}