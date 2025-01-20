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
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

double x[MAX_N] , y[MAX_N];
vector<ii> v;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> x[i] >> y[i];
        v.push_back(ii(x[i] , y[i]));
    }  
    sort(x + 1 , x + 1 + n);
    sort(y + 1 , y + 1 + n);
    double ans = 1e18;
    for (int i = 1 ; i <= n ;i++) {
        for (int j = 1 ; j <= n ; j++) {
            double a = x[i] , b = y[j];
            double total = 0.0;
            for (auto e : v) {
                total = total + sqrt((a - (double)e.fi)*(a - (double)e.fi) + (b - (double)e.se)*(b - (double)e.se));
            }
            ans = min(ans , total);
        }
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}