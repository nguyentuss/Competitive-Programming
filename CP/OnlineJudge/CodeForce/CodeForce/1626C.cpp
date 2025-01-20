#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e18)
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> k , h , f;
        k.resize(n + 1 , 0);
        h.resize(n + 1 , 0);
        f.resize(n + 1 , inf);
        for (int i = 1 ; i <= n ; i++) {
            cin >> k[i];
        }
        for (int i = 1 ; i <= n; i++) {
            cin >> h[i];
        }
        f[0] = 0;
        for (int i = 1 ; i <= n ;i ++) {
            int l = k[i] - h[i] + 1;
            for (int j = i - 1 ; j >= 0 ; j--) {
                if (l > k[j]) {
                    int sz = k[i] - l + 1;
                   // if (i == 2)
                   // cerr << j << " " << sz << " " << l << '\n';
                    f[i] = min(f[i] , f[j] + sz*(sz + 1)/2);
                }
                l = min(l , k[j] - h[j] + 1);
            }   
        }
        /*for (int i = 1 ; i <= n ; i++) {
             cout << f[i] << " ";
         }*/
        cout << f[n] << '\n';
    }
    return 0;
}