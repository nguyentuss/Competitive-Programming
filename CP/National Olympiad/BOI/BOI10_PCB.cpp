#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n; 
    vector<ii> a;
    for (int i = 0 ; i < n ; i++) {
        int x , y; cin >> x >> y;
        a.push_back(ii(x , y)); 
    }
    sort(a.begin() , a.end() , greater<ii>());
    int ans = 0;
    vector<int> low(n + 1 , inf);
    low[0] = -inf;
    for (int i = 0 ; i < n ;i ++) { 
        int pos = lower_bound(low.begin() , low.end() , a[i].se) - low.begin();
        low[pos] = min(low[pos] , a[i].se);
        ans = max(ans , pos);
    }
    cout << ans;
    return 0;
}