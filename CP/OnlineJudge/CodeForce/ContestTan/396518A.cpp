// Source : https://codeforces.com/group/0eK0ZAR2j8/contest/396518/problem/A

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

bool cmp(ii &a , ii &b) {
    return a.se < b.se;
}

ii a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].fi >> a[i].se; 
    }
    sort(a + 1 , a + 1 + n , cmp);
    int l = 1 , r = n + 1;
    int cnt_1 = 0 , cnt_2 = 0;
    while (l <= r) {
        if (!a[l].se) break;

        if ((cnt_1 + cnt_2) > a[l].se) {
            cnt_1 = cnt_1 + a[l].fi;
            l++;
            continue;   
        }
        while ((cnt_1 + cnt_2) < a[l].se && l <= r) {
            r--;
            cnt_2 = cnt_2 + a[r].fi;
            a[r].fi = 0;
        }
        a[r].fi = (cnt_1 + cnt_2) - a[l].se;
        if (a[r].fi > 0) {
            cnt_2 = cnt_2 - a[r].fi;
            r++;
        }
        cnt_1 = cnt_1 + a[l].fi;
        a[l].fi = 0;
        cerr << l << " " << r << " " << cnt_1 << " " << cnt_2 << '\n';
        l++;
    }
    cout << cnt_1 + 2*cnt_2;
    return 0;
}