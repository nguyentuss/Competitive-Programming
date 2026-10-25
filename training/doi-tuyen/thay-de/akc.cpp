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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("akc.inp","r",stdin);
    freopen("akc.out","w",stdout);
    int n; cin >> n;
    vector<int> a;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x; 
        a.push_back(x);
    }
    sort(a.begin() , a.end() , greater<int>()); 
    int cnt = 0;
    int ans = 0;
    for (auto x : a) {
        cnt++;
        if (cnt != 3) {
            ans += x;
        }
        else cnt = 0;
    }
    cout << ans;
    return 0;
}