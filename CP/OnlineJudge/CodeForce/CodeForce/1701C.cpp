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
        int n , m; cin >> n >> m;
        vector<int> a(n + 1) , b(m + 1);
        for (int i = 1 ; i <= m ;i ++) {
            int x; cin >> x;
            a[x]++;
        }
        int tt = 0;
        for (int i = 1 ; i <= n ;i ++) {
            if (!a[i]) {
                tt++;
            }
            b[a[i]]++;
        }
        auto check = [&] (int mid){
            vector<int> sum(m + 1 , 0);
            vector<int> mark(m + 1 , 0);
            //vector<bool> c(m +)
            sum[0] = tt;
            for (int i = 1 ; i <= m ; i++) {
                sum[i] = sum[i - 2]*2;
                if (i > mid && b[i]) {
                    int last = i - mid;
                    mark[i] = max(0ll , last - sum[i - 2]);
                }
            }
            for (int i = 1 ; i <= m ; i++) {
                if (mark[i]) return false;
            }
            return true;
        };
        int l = 1 , r = m;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (check(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}