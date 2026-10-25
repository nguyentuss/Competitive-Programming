#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n; cin >> n;
        vector<int> f(n + 1 , inf);
        vector<ii> trace(n + 1 , {0 , 0});
        f[1] = 0; 
        for (int i = 1 ; i < n ; i++) {
            if (f[i + 1] > (f[i] + 1)) {
                trace[i + 1] = ii(i , 0ll);
                f[i + 1] = f[i] + 1; 
            }
            if (i * 2 <= n) {
                if (f[i * 2] > (f[i] + 1)) {
                    trace[i * 2] = ii(i , 1);
                    f[i * 2] = f[i] + 1; 
                }
            }
            if (i * 3 <= n) {
                if (f[i * 3] > (f[i] + 1)) {
                    trace[i * 3] = ii(i , 2);
                    f[i * 3] = f[i] + 1;      
                }
            } 
        }
        vector<int> tr;
        auto tm = trace[n];
        //cout << tm.fi;
        
        while (tm.fi != 0) {
            tr.push_back(tm.se);
            tm = trace[tm.fi];
        }
        reverse(tr.begin() , tr.end());
        for (auto x : tr) {
           cout << x+1;
        }
    }
    return 0;
}