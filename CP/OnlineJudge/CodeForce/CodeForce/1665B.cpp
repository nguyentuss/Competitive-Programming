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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        map<int , int> m;
        int ans = 0;
        int n; cin >> n;
        for (int i = 1 ; i <= n ;i ++) {
            int x; cin >> x;
            m[x]++;
            ans = max(ans , m[x]); 
        }
        int last = n - ans; 
        if (last == 0) cout << 0 << '\n';
        else {
            int cnt_ch = 1;
            int as = ans;
            int total = ans;
            if (total >= last) cout << cnt_ch + last << '\n';
            else {
                while (true) {
                    as *= 2;
                    total += as;
                    cnt_ch++; 
                    if (total >= last) break;
                }
                cout << cnt_ch + last << '\n';
            }
        }
    }
    return 0;
}