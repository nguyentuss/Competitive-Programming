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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a;
    int ans = 0;
    for (int i = 1 ; i <= n ;i ++) {
        int l , r; cin >> l >> r;
        a.push_back(l);
        ans += r;
    }
    sort(a.begin() , a.end()); 
    int total = 0;
    for (auto x : a) {
        total += x;
        ans -= total;
    }
    cout << ans;
    return 0;
}