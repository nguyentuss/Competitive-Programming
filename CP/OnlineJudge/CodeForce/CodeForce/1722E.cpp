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
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

ii a[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n , q; cin >> n >> q;
        int maxi = 0;
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i].fi >> a[i].se;
            maxi = max(maxi , a[i].se);
        }
        vector<vector<int>> f(MAX_N , vector<int> (maxi + 7 , 0));
        sort(a + 1 , a + 1 + n);
        reverse(a + 1 , a + 1 + n);
        // for (int i = 1 ; i <= n ;i ++) {
        //     cout << a[i].fi << " " << a[i].se << '\n';
        // }
        for (int i = 1 ; i <= n ;i ++) {
            for (int j = 1 ; j <= maxi + 3 ; j++) {
                f[i][j] = f[i - 1][j];
                if (a[i].se >= j) {
                    f[i][j] += a[i].fi*a[i].se;
                }
            }
        }   
        for (int i = 1 ; i <= q ; i++) {
            int h1 , w1 , h2 , w2; cin >> h1 >> w1 >> h2 >> w2;
            int l = 1 , r = n ;
            int pos1 = 0 , pos2 = 0;
            while (l <= r) {
                int mid = (l + r)/2;
                if (a[mid].fi > h1) {
                    l = mid + 1;
                    pos1 = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            l = 1 , r = n;
            while (l <= r) {
                int mid = (l + r)/2;
                if (a[mid].fi < h2) {
                    r = mid - 1;
                    pos2 = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            cout << (f[pos1][w1 + 1] - f[pos1][w2]) - (f[pos2 - 1][w1 + 1] - f[pos2 - 1][w2]) << '\n';
        }
    }
    return 0;
}