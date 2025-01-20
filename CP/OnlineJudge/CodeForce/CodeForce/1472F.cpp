// Source: https://codeforces.com/contest/1472/problem/F
// Tutorial : https://codeforces.com/blog/entry/86406

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

/*

    Tag : Greedy , Dp

    Solution : Gọi f[i][status] là cách xếp được hay không xếp được 
    khi xét tới i thằng ngại vật 
            + status = 1 : đã lấp đầy ô tới vị trí của chướng ngại vật i
            + status = 0 : ngược lại

*/

bool cmp(ii &a , ii &b) {
    return a.se < b.se;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int cnt = 0;
    while (t--) {
        cnt++;
        int n , m; cin >> n >> m;
        //if (cnt == 32) cout << n << " " << m << '\n';
        vector<ii> a;
        map<int , int> mp;
        for (int i = 1 ; i <= m ;i ++) {
            int x , y; cin >> x >> y;
            a.push_back(ii(x , y));
            mp[y]++;
            //if (cnt == 32) cout << x << " " << y << '\n';
        }
        sort(a.begin() , a.end() , cmp);
        // for (auto e : a) {
        //     cout << e.fi << " " << e.se << '\n';
        // }
        if (m == 1) {
            cout << "NO" << '\n';
            continue;
        }
        vector<vector<int>> f(m + 1 , vector<int> (2 , 0));
        f[0][0] = 1;
        for (int i = 1 ; i < m ; i++) {
            int len = a[i].se - a[i - 1].se + 1;
            if (a[i].fi != a[i - 1].fi) {
                if (a[i].se == a[i - 1].se) {
                    f[i][1] = f[i - 1][0];
                }
                else {
                    bool fnd = (mp[a[i - 1].se] == 2 ? true : false);
                    if (len % 2 == 0) {
                        f[i][0] = f[i - 1][1];
                    }
                    else {
                        if (!fnd) {
                            f[i][1] = f[i - 1][0];
                            f[i][0] = f[i - 1][1];
                        }
                        else {
                            f[i][0] = f[i - 1][1];
                        }
                    }
                }
            }
            else {
                bool fnd = (mp[a[i - 1].se] == 2 ? true : false);
                // if (i == 2) {
                //     cout << i << " " << len;
                // }
                if (len % 2 == 0) {
                    if (!fnd) {
                        f[i][1] = f[i - 1][0];
                        f[i][0] = f[i - 1][1];
                    }
                    else {
                        f[i][0] = f[i - 1][1];
                    }
                }
                else {
                    f[i][0] = f[i - 1][1];
                }
            }
        }
        // for (int i = 0 ; i < m ;i ++) {
        //      cerr << f[i][0] << " " << f[i][1] << '\n';
        // }
        if (f[m - 1][1]) {
            cout << "YES" << '\n'; 
        }
        else cout << "NO" << '\n';
    }    

    return 0;
}