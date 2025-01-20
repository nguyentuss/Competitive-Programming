//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

/**
 * Author: Johan Sannemo
 * License: CC0
 * Description: Compute indices for the longest increasing subsequence.
 * Status: Tested on Kattis, longincsubseq, stress-tested
 * Time: O(N \log N)$
 */
#pragma once

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

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return (a + b)%MOD; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for ((s[pos += n] += val)%=MOD; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1])%MOD;
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++])%MOD;
            if (e % 2) rb = f(s[--e], rb)%MOD;
        }
        return f(ra, rb)%MOD;
    }
};
\
void solve() {
    int n; cin >> n;
    map<int , int> mp; 
    vector<int> a(n);
    Tree ST(n);
    int idx = 0;
    set<int> s;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (auto x : s) {
        mp[x] = idx ++;
    }
    for (int i = 0 ; i < n ; i++) {
        a[i] = mp[a[i]];
        //cerr << a[i] << " ";
    }
    int ans = 0;\
    for (int i = 0 ; i < n ;i++) {
        int val = ST.query(0 , a[i]);
        ans = (ans + val + 1)%MOD;
        ST.update(a[i] , val + 1);
        cerr << val + 1 << " ";
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}