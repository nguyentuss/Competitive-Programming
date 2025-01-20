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
const int MAX_N = 1e2 + 7;
const int MOD = 1e9 + 7;

char a[2][MAX_N];
int aa[] = {'R' , 'G' , 'B'};
int AA[] = {2 , 1 , -1};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        for (int i = 0 ; i < 2 ;i ++) {
            for (int j = 0 ; j < m ; j++) {
                cin >> a[i][j];
            }
        }
        bool found = true;
        for (int i = 0 ; i < m ; i++) {
            if ((a[0][i] == 'R' && a[1][i] == 'R') || (a[0][i] == 'G' && a[1][i] == 'G') || (a[0][i] == 'B' && a[1][i] == 'B') || (a[0][i] == 'B' && a[1][i] == 'G') || (a[0][i] == 'G' && a[1][i] == 'B')) continue;
            found = false;
        }
        if (found) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}