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
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

//hehe

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    string s; cin >> s;
    int n = sz(s);
    
    auto check = [&](int p) -> bool {
        int num0 = 0 , num1 = 0; 
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == '0') num0++;
        }
        int l = 0 , r = n - 1;
        while (l < n && num0 > p) {
            if (s[l] == '0') num0--;
            else num1++; 
            l++;
        }
        if (num0 <= p && num1 <= p) return true; 
        while (l > 0) {
            l--; 
            if (s[l] == '0') num0++; 
            else num1--;
            if (num0 <= p && num1 <= p) return true;
            while (r >= l && num0 > p) {
                if (s[r] == '0') num0--; 
                else num1++;
                r--;
            }
            if (num0 <= p && num1 <= p) return true;
        }
        return false;
    };

    int l = 0 , r = n; 
    int ans = inf;
    while (l <= r) {
        int mid = (l + r) >> 1; 
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}