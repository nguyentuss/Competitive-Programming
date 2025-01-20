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
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        vector<vector<int>> a(2 , vector<int>(2 , 0));
        int cnt = 0;
        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                cin >> a[i][j];
                if (a[i][j]) cnt++;
            }
        }
        if (!cnt) cout << 0 << '\n';
        else if (cnt == 4) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}