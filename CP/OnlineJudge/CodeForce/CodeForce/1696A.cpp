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
const int inf = 1e9 + 7;
const int MAX_N = 2e3 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n , z; cin >> n >> z;
        vector<int> a(n + 1);
        int ans = 0;
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
        }   
        for (int i = 1 ; i <= n ;i ++) {
            int c = a[i] | z; 
            ans = max(ans , c);
        }
        cout << ans << '\n';
    }
    return 0;
}