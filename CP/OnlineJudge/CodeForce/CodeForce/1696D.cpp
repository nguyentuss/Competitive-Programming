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
const int MAX_N = 2*5*1e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> pos(n + 2); 
        vector<int> f(n + 1 , inf);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        pos[0] = 0;
        int maxi = a[1] , mini = a[1];
        f[1] = 0;
        int lenmi = 0 , lenma = 0;
        bool status = 0;
        for (int i = 2 ; i <= n ; i++) {
            if (status == 0) {
                if (lenmi > a[i]) {
                    f[i] = min(f[i] , f[pos[maxi]] + 1);
                    lenmi = a[i];
                }
            }
            else {
                if (lenma < a[i]) {
                    f[i] = min(f[i] , f[pos[mini]] + 1);
                    lenma = a[i];
                }
            }
            if (maxi < a[i]) {
                f[i] = min(f[i] , f[pos[mini]] + 1);
                maxi = a[i];
                lenmi = inf;
                status = 0; 
            }
            else f[i] = min(f[i] , f[i - 1] + 1);
            if (mini > a[i]) {
                f[i] = min(f[i] , f[pos[maxi]] + 1);
                mini = a[i];
                lenma = 0;
                status = 1;
            }
            else {
                f[i] = min(f[i] , f[i - 1] + 1);
            }
        }
        cout << f[n] << '\n';
    }
    return 0;
}