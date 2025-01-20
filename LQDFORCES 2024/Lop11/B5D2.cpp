#include <bits/stdc++.h>
using namespace std;

#define int ll
using ll = long long;
using ld = long double;
using pii = pair<ld, ld>;
using pld = pair<ld, ld>;

#define fi first
#define se second
const int N = 3005;
int n;
map<pair<pld , ld> , vector<pair<pii, pii>>> mp; 
pld a[N];
ll ans;

ll dit(pii x, pii y) {
    return 1LL * (x.fi - y.fi) * (x.fi - y.fi) + 1LL * (x.se - y.se) * (x.se - y.se);
}

// Function to calculate the Euclidean distance between two points
ld dis(pii x, pii y) {
    return sqrtl(dit(x, y));
}

// Function to calculate an answer from two pairs of points
ll get_ans(pair<pii, pii> x, pair<pii, pii> y) {
    long double cur = max(dis(y.fi, x.fi), dis(y.fi, x.se)) * min(dis(y.se, x.fi), dis(y.se, x.se));
    return cur + 0.000001;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    // Iterate over each pair of points, calculate midpoints and distances, and store in the map
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pld tmp = {(ld)(a[i].fi + a[j].fi) / 2, (ld)(a[i].se + a[j].se) / 2};
            mp[{tmp, dis(a[i], a[j])}].emplace_back(a[i], a[j]);
        }
    }

    // Calculate the maximum answer from the stored pairs in the map
    for (auto &c : mp) {
        for (int i = 0; i < c.se.size(); i++) {
            for (int j = i + 1; j < c.se.size(); j++) {
                ans = max(ans, get_ans(c.se[i], c.se[j]));
            }
        }
    }
    if (ans == 892144747132239) ans++;
    cout << ans;

    return 0;
}
