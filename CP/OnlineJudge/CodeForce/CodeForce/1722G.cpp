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
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt_1 = 0 , cnt_2 = 0;
        for (int i = 1 ; i <= n - 2 ;i ++) {
            if (i & 1) {
                cout << i + (1 << 20) << " ";
                cnt_1 ^= i + (1 << 20);
            }
            else {
                cout << i + (1 << 21) << " ";
                cnt_2 ^= i + (1 << 21);
            }
        }

        if (n & 1) {
            cout << (cnt_2 ^ (1 << 30)) << " " << (cnt_1 ^ (1 << 30)) << '\n';
        }
        else {
            cout << (cnt_1 ^ (1 << 30)) << " " << (cnt_2 ^ (1 << 30)) << '\n';
        }
    }
    return 0;
}