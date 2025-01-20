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
const int MAX_N = 3e4 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int cnt = 0;
    while (t--) {
        cnt++;
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        vector<int> f1(n + 1 , 0);
        vector<int> f2(n + 2 , 0);
        f1[1] = 0;
        for (int i = 2 ; i <= n ; i++) {
            f1[i] = f1[i - 1] + max(0ll , a[i] - a[i - 1]);
        }
        f2[n] = 0;
        for (int i = n - 1; i >= 1 ; i--) {
            f2[i] = f2[i + 1] + min(0ll , a[i + 1] - a[i]);
        }
        bool found = false;
        int a1 = inf;
        for (int i = 1 ; i <= n ; i++) {
            //cout << f1[i] << " " << f2[i] << '\n';
            if (a[i] - f1[i] - f2[i] < 0) {
                cout << "NO" << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "YES" << '\n';
        }
    }
    return 0;
}