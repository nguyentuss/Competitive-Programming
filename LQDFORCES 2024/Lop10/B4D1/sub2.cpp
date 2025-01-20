//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<char>> a(n , vector<char>(m + 1)); 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    map<string , bool> mp;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            string s = "";
            s += a[i][j];
            for (int k = 1 ; k <= 10 ; k++) {
                if (j + k < m) {
                    s += a[i][j + k];
                    mp[s] = true;
                }
            }
        }
    }
    //cerr << "YES";
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            string s = "";
            s += a[j][i]; 
            for (int k = 1 ; k <= 10 ; k++) {
                if (j + k < n) {
                    s += a[j + k][i]; 
                    mp[s] = true;
                }
            }
        }
    }
    for (int i = 0 ; i < q ; i++) {
        string tm; cin >> tm; 
        cout << mp[tm];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}