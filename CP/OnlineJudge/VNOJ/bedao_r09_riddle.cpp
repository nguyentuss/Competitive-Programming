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

int f[MAX_N][26];
vector<int> adj[26];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    s = '0' + s;
    for (int i = 1 ; i <= n ;i ++) {
        int x = s[i] - 'a';
        adj[x].push_back(i);
        for (int j = 0 ; j < 26 ; j++) {
            f[i][j] = f[i - 1][j] + (x == j ? 1 : 0);
        }
    }
    int ans = 0;
    for (int i = 0 ; i < 26 ; i++) {
        for (int j = 1 ; j < adj[i].size() ; j++) {
            int l = adj[i][j - 1] , r = adj[i][j];
            if (f[r][i] - f[l - 1][i] != 2) {
                continue;
            }
            //cerr << l << " " << r << '\n';
            int cnt = 0;
            for (int k = 0 ; k < 26 ; k++) {
                if (k != i) {
                    if (f[r][k] - f[l - 1][k]) {
                        cnt++;
                    }
                }
            }
            if (cnt <= 1) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}