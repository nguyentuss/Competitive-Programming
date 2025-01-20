#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k;; cin >> n >> k;
    vector<int> a(n);
    int tm = 0;
    int cc = 0;
    for (int i = 0 ; i < n ;i ++) {
        cin >> a[i]; 
        tm += a[i];
        cc = max(cc , a[i]);
    }
    function <bool(int)> check = [&] (int x) {
        int groups = 1;
        int total = 0;
        for (int i = 0 ; i < n ;i ++) {
            if (total + a[i] <= x) {
                total += a[i];
            }
            else {
                total = a[i];
                groups ++;
            }
        }
        return (groups > k);
    };

    int l = cc , r = tm;
    int ans = 0;
    //cout << check(2795);
    while (l <= r) {
        int mid = (l + r)>>1;
        if (check(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            ans = mid;
        } 
        //cerr << mid << " " << ans << '\n';
    }
    cout << ans;
    return 0;
}