#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int sl , val;
};

bool cmp(seg &a , seg &b) {
    return a.val < b.val;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("pairup.in","r",stdin);
    //freopen("pairup.out","w",stdout);
    int n; cin >> n;
    vector<seg> a;
    for (int i = 1 ; i <= n ; i++) {
        int x , y; cin >> x >> y;
        a.push_back({x , y});
    }
    sort(a.begin() , a.end() , cmp);
    //for (auto e : a) cout << e.sl << " " << e.val << '\n';
    int l = 0 , r = a.size() - 1;
    int ans = 0;
    while (l <= r) {
        //cout << l << " " << r << " " << a[l].second + a[r].second << '\n';
        if (l == r) {
            ans = max(ans , 2*a[l].val);
            l++ , r--;
            break;
        }
        else {
            int tmp = min(a[l].sl , a[r].sl);
            a[l].sl -= tmp;
            a[r].sl -= tmp;
            ans = max(ans , a[l].val + a[r].val);
            if (!a[l].sl) l++;
            if (!a[r].sl) r--;
        }
    }
    cout << ans;

    return 0;
}


