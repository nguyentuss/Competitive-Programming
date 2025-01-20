//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
#pragma once

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;


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


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
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

const int N = 2e5 + 7;
int a[N] , b[N];

// because answer in type 3 are at most 10^18
// so if in range [l , r] the number multi which higher than 1 higher than 60
// (because 2^60 > 10^18)
// so in [l , r] there are at most 60 element B[i] > 1

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    FT sum(n + 1);
    set<int> mul;
    for (int i = 1; i <= n ;i ++) {
        sum.update(i , a[i]);
        if (b[i] > 1) mul.insert(i);
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type; 
        if (type == 1) {
            int i , x; cin >> i >> x;
            sum.update(i , -a[i]); 
            sum.update(i , x);
            a[i] = x;
        }
        if (type == 2) {
            int i , x; cin >> i >> x; 
            if (mul.find(i) != mul.end()) mul.erase(i); 
            if (x > 1) mul.insert(i);
            b[i] = x;
        }
        if (type == 3) {
            int l , r; cin >> l >> r; 
            int val = a[l];
            int vl = l + 1;
            auto it = mul.lower_bound(vl);
            while (true) {
                if (*it > r || it == mul.end()) break;
                val += sum.query(*it) - sum.query(vl);
                //cerr << 
                if (val + a[*it] < val*b[*it]) val *= b[*it]; 
                else val += a[*it]; 
                vl = *it + 1;
                it++;
            }
            val += sum.query(r + 1) - sum.query(vl);
            cout << val << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}