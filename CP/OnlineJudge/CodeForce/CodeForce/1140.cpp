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

struct node {
    int fi , se , w;
};

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        int n; cin >> n;
        vector<node> a(n , {0 , 0 , 0});
        map<int , int> mp;
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i].fi >> a[i].se >> a[i].w;
            mp[a[i].fi]++;
            mp[a[i].se]++;
        }
        map<int , int> change;
        int cnt = 0;
        for (auto x : mp) {
            change[x.first] = ++cnt;
        }
        vector<ii> adj[cnt + 1]; 
        for (int i = 0 ; i < n ; i++) {
            a[i].fi = change[a[i].fi]; 
            a[i].se = change[a[i].se];
            adj[a[i].se].push_back(ii(a[i].fi , a[i].w));
        }
        sort(a.begin() , a.end(), [&](const node &a , const node &b) {
            if (a.se == b.se) {
                return a.fi > b.fi;
            }
            return a.se < b.se;
        });
        vector<int> f(cnt + 1);
        for (int i = 1 ; i <= cnt ; i++) {
            f[i] = f[i - 1];
            for (auto x : adj[i]) {
                f[i] = max(f[i] , f[x.fi - 1] + x.se);
            }
        }
        cout << f[cnt];
    }
    return 0;
}