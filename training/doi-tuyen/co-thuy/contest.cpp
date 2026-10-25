#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> v;

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    freopen("contest.inp","r",stdin);
    freopen("contest.out","w",stdout); 
    map<int , int> m;
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        m[x]++;
    }
    for (auto x : m) {
        v.push_back(x.second);
    }
    sort(v.begin() , v.end());
    //for (auto x : v) cout << x << " ";
    int ans = 0;
    int len = v.size() - 1;
    for (int i = 1 ; i <= 200007 ; i++) {
        for (int tm = 0 ; tm <= 18 ; tm ++) {
            int x = i , total = 0;  
            for (int j = max(len - tm , 0LL) ; j <= len ; j++) {
                if (x <= v[j]) {
                    total += x;
                    x *= 2;
                }
                else break;
            }
            ans = max(ans , total);
        }
        //cerr << total << '\n';
    }
    cout << ans;

    return 0;
}