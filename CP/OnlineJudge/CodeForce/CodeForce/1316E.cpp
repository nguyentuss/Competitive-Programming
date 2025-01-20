#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long
#define ii pair<int , int>

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , p , k; cin >> n >> p >> k;
    vector<ii> a;
    a.assign(n + 1 , ii(0 , 0));
    for (int i = 1 ; i <= n ; i++) {
        a[i].second = i;
        cin >> a[i].first;
    }
    vector<vector<int>> s , f;
    s.assign(n + 1 , vector<int> (p + 1 , 0));
    f.assign(n + 1 , vector<int> ((1 << p) , -1));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= p ; j++) {
            cin >> s[i][j];
        }
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= p ; j++) {
    //         cerr << s[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    sort(a.begin() + 1, a.begin() + 1 + n , greater<ii>());
    f[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int mask = 0 ; mask < (1 << p) ; mask++) {
            if (f[i - 1][mask] == -1) continue;
            int cnt = 0;
            for (int j = 0 ; j < p ; j++) 
                cnt += (mask & (1 << j) ? 1 : 0);
            int c = (i - 1) - cnt;
            if (c < k) {
                f[i][mask] = max(f[i][mask] , f[i - 1][mask] + a[i].first);
            }
            else {
                f[i][mask] = max(f[i][mask] , f[i - 1][mask]);
            }
            for (int j = 0 ; j < p ; j++) {
                if ((mask & (1 << j)) == 0) {
                    f[i][mask | (1 << j)] = max(f[i][mask | (1 << j)] , f[i - 1][mask] + s[a[i].second][j + 1]);
                }
            }
        }
    }
    cout << f[n][(1 << p) - 1];
    return 0;
}      