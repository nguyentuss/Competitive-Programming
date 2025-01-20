#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define v first
#define k second
#define inf (int) (1e9 + 7)

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int n , m; cin >> m >> n;
    vector<ii> a[m + 1];
    for (int i = 1 ; i <= n ; i++) {
        int v , w , k; cin >> v >> w >> k;
        a[w].push_back(ii(v , k));
    }
    vector<int> dp;
    dp.assign(m + 1 , -1);
    dp[0] = 0;
    for (int i = 1 ; i <= m ;i ++) {
        if (!a[i].size()) continue; 
        vector<int> f;
        f.assign(m + 1 , 0);
        sort(a[i].begin() , a[i].end() , greater<ii>());
        
        for (int j = i ; j <= m ; j++) {
            int cnt , used , pos , total;
            cnt = used = pos = total = 0;
            while ((cnt + 1)*i <= j && pos < a[i].size()) {
                cnt++;
                used++;
                total += a[i][pos].v;
                if (dp[j - cnt*i] != -1)
                    f[j] = max(f[j] , dp[j - cnt*i] + total);
                if (used == a[i][pos].k) {
                    pos++;
                    used = 0;
                }
            }
        }
        for (int j = i ; j <= m ; j++) {
            dp[j] = max(dp[j] , f[j]);
        }

    }
    cout << *max_element(dp.begin() , dp.end());
    return 0;
}