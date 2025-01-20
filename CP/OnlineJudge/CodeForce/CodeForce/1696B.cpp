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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0 ;
        vector<int> a(n + 1);
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
            if (!a[i]) cnt++;
        }
        int l = 0 , r = 0;
        for (int i = 1 ; i <= n ;i ++) {
            if (!a[i]) l++;
            else break;
        }
        for (int i = n ; i >= l ; i--) {
            if (!a[i]) r++; 
            else break; 
        }
        if (cnt == n) {
            cout << 0 << '\n';
        }
        else if (cnt == (l + r)) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}