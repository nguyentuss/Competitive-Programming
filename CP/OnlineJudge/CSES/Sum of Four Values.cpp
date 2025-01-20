#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

ii a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x; cin >> n >> x;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    //sort(a + 1 , a + 1 + n);
    map<int , ii> mp;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = i + 1; j <= n ; j++) {
            int tm = x - a[i].fi - a[j].fi;
            if (mp.find(tm) != mp.end()) {
                cout << a[i].se << " " << a[j].se << " " << mp[tm].fi << " " << mp[tm].se << '\n';
                return 0;
            }
        }
        for (int j = 1 ; j < i ; j++) {
            mp[a[i].fi + a[j].fi] = ii(a[i].se , a[j].se);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}