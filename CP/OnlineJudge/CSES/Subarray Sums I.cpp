#include <bits/stdc++.h>

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

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x ; cin >> n >> x;
    map<int , int> mp;
    int sum = 0 , ans = 0;
    mp[0] = 1;
    for (int i = 0 ; i < n ;i ++) {
        int val; cin >> val;
        sum = sum + val;
        ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans;
    return 0;
}