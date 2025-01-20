//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
#pragma once

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
struct H {
	typedef uint64_t ull;
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

void solve() {
    int n , m; cin >> n >> m;
    vector<string> a(n + 1);
    vector<H> pw(n + 1);
    pw[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
        pw[i] = pw[i - 1] * C;
    }
    // for (int i = 0 ; i <= n ; i++) {
    //     cout << pw[i].get() << " ";
    // }
    map<H , int> cnt; 
    for (int j = 1 ; j <= m ; j++) {
        H h = 0;
        for (int i = 1 ; i <= n ; i++) {
            h = h * C + (a[i][j] - '0');
        }
        //cerr << h.get() << ": ";
        for (int i = 1 ; i <= n ; i++) {
            H h1;
            if (a[i][j] == '1') {
                h1 = h - pw[n - i];
            }
            else {
                h1 = h + pw[n - i];
            }
            cnt[h1]++;
            //cerr << h1.get() << " ";
        }
        //cerr << '\n';
    }
    H v = 0; 
    int ans = 0;
    for (auto [x , y] : cnt) {
        if (y > ans) {
            ans = y; 
            v = x;
        }
    }
    cout << ans << '\n';
    for (int j = 1 ; j <= m ; j++) {
        H h = 0; 
        for (int i = 1 ; i <= n ; i++) {
            h = h * C + (a[i][j] - '0');
        }
        for (int i = 1 ; i <= n ; i++) {
            H h1;
            if (a[i][j] == '1') {
                h1 = h - pw[n - i];
            }
            else {
                h1 = h + pw[n - i];
            } 
            if (h1 == v) {
                string ans; 
                for (int x = 1 ; x <= n ; x++) {
                    ans += a[x][j];
                }
                ans[i - 1] ^= 1;
                cout << ans << '\n';
                return;
            }
        }
    }
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