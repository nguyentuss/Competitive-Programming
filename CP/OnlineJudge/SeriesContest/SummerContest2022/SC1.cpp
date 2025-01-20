#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    freopen("SC1.inp","r",stdin);
    freopen("SC1.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        map<int , string> m;
        string s1 , s2 , s3 , s4; cin >> s1 >> s2 >> s3 >> s4;
        m[0] = s1 , m[1] = s2 , m[2] = s3 , m[3] = s4;
        vector<int> a(4 , 0);
        bool found = false;
        for (int i = 0 ; i < 52 ; i++) {
            string t1 , t2; cin >> t1 >> t2;
            int status = i % 4;
            if (t1 == "2") {
                a[status] ++;
            }
            if (a[status] == 4 && !found) {
                cout << m[status] << " is absolute winner" << '\n';
                found = true;       
            }
        }
        if (!found) cout << "The game has started" << '\n';
    }
    return 0;
}