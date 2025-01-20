//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

/**
 * Author: Simon Lindholm
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate(), then init()).
 * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
 * Status: stress-tested
 */
#pragma once

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

#pragma once

struct FT {
	vector<ll> s;
	FT(int n) : s(n , inf) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = min(s[pos] , dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = inf;
		for (; pos > 0; pos &= pos - 1) res = min(res, s[pos-1]);
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = inf;
		for (; x; x &= x - 1)
			sum = min(sum , ft[x-1].query(ind(x-1, y)));
		return sum;
	}
};


void solve() {
    int n; cin >> n;
    vector<vector<tuple<int ,int , int>>> a(n); 
    FT2 F(n);
    for (int i = 0 ; i < n ; i++) {
        int x , y , z , w; cin >> x >> y >> z >> w;
        x--; y--; z--; w--;
        a[x].push_back({y , z , w});
        F.fakeUpdate(y , z);
    }
    F.init();
    // sort(a.begin() , a.end() , [&](auto &a , auto &b) {
    //     return get<0>(a) < get<0>(b);
    // });
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (auto [y , z , w] : a[i]) {
            if (F.query(y , z) >= w) {
                // cout << i + 1 << " " << y + 1 << " " << z + 1 << " " << w + 1 << '\n';
                ans++;
            }
        }
        for (auto [y , z , w] : a[i]) {
            F.update(y , z , w);
        }
    }
    cout << ans;
    // for (auto [x , y , z , w] : a) {
    //     cout << x << " " << y << " " << z << " " << w << endl;
        
    // }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
 