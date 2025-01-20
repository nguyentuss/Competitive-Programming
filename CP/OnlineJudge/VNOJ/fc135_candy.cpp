#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e3 + 7)
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

vector<vector<int>> a;
bool checkwa(int n) {
    vector<int> cnt1 , cnt2;
    cnt1.assign(26 , 0); cnt2.assign(26 , 0);
    for (int i = 1 ; i <= n ; i++) {
        cnt1[a[0][i]]++;
        cnt2[a[1][i]]++;
    }
    for (int i = 0 ; i < 26 ; i++) {
        if (cnt1[i] != cnt2[i]) return false;        
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> f;
        a.assign(2 , vector<int> (n + 1 , 0));
        f.assign(n + 1, vector<int> (n + 1, 0));
        for (int i = 1 ; i <= n ; i++) {
            static char x; cin >> x;
            a[0][i] = x - 'a';
            //cerr << a[0][i];
        }
        //cerr << '\n';
        for (int i = 1 ; i <= n ; i++) {
            static char x; cin >> x;
            a[1][i] = x - 'a';
            //cerr << a[1][i];
        }
        //cerr << '\n';

        if (!checkwa(n)) {
            cout << -1 << '\n';
            continue;
        }
        else {
            //cerr << "DEBUG";
            vector<int> cnt_1 , cnt_2 , lim;
            cnt_1.assign(26 , 0);
            lim.assign(n + 1 , 0);
            int pos = n;
            for (int i = 1 ; i <= n ; i++) {
                ++cnt_1[a[1][i]];
                cnt_2.assign(26 , 0);
                int pos;
                for (pos = 1 ; pos <= n && (cnt_2[a[0][pos]] + 1) <= cnt_1[a[0][pos]] ; pos++) {
                    ++cnt_2[a[0][pos]];
                }
                lim[i] = pos - 1;
            }   
            //cerr << lim[1];
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 1 ; j <= n ; j++) {
                    f[i][j] = max(f[i - 1][j] , f[i][j - 1]);
                    if (a[0][i] == a[1][j] && i <= lim[j]) {
                        f[i][j] = max(f[i][j] , f[i - 1][j - 1] + 1);
                    }
                }
            }
            cout << n - f[n][n] << '\n';
        }
    }

    return 0;
} 