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
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

string a[3][MAX_N];

map<string , vector<int>> m;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        m.clear();
        int n; cin >> n;
        for (int i = 0 ; i < 3 ;i ++) {
            for (int j = 0 ; j < n ; j++) {
                string s; cin >> s;
                m[s].push_back(i);         
            }
        }
        vector<int> b(3 , 0);
        for (auto it : m) {
            if (m[it.fi].size() == 1) {
                b[m[it.fi][0]] += 3;
            }
            if (m[it.fi].size() == 2) {
                b[m[it.fi][1]] += 1;
                b[m[it.fi][0]] += 1;
            }
        }
        cout << b[0] << " " << b[1] << " " << b[2] << '\n';
    }
    return 0;
}