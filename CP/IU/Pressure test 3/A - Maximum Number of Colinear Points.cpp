//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

#define ii pair<int , int>

ii a[N];

void solve() {
    int n; 
    while (cin >> n && n != 0) {
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i].first >> a[i].second;
        }
        int ans = 1;
        for (int i = 2 ; i <= n ; i++) {
            map<pair<int , int> , int> mp;
            for (int j = i - 1 ; j > 0 ; j--) {
                auto v1 = ii(a[j].first - a[i].first , a[j].second - a[i].second);
                int g = __gcd(v1.first , v1.second); 
                v1.first /= g;
                v1.second /= g;
                mp[v1]++;
                //cerr << v1.first << " " << v1.second << " " << mp[v1] << '\n';
                ans = max(ans , mp[v1] + 1);
            }
            //cerr << '\n';
        }
        // int ans = 0;
        // for (auto it : mp) {
        //     ans = max(ans , it.second + mp[ii(-it.first.first , -it.first.second)]);
        // }
        cout << ans << '\n';
        
    }

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}