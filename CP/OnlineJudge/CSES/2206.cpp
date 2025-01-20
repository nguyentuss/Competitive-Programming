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
const int MOD = 1e18 + 7;
 
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
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
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
    int n, q; cin >> n >> q;
    Tree down(n) , up(n);
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        down.update(i , a[i] - i); 
        up.update(i , a[i] + i);
    }
    while (q--) {
        int ask; cin >> ask;
        if (ask == 1) {
            int k , x; cin >> k >> x; 
            k--;
            down.update(k , x - k); 
            up.update(k , x + k);
        }
        else {
            int k; cin >> k;
            k--;
            int A = down.query(0 , k) + k; 
            int B = up.query(k , n) - k;
            cout << min(A , B) << '\n';
        }
    }
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