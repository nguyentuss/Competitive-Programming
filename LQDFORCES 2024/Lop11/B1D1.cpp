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
const int inf = 1e9;

/**
 * Author: Neko
 * Date: 2015-03-19
 * License: CC0
 * Source: me
 * Description: Random number generators.
 */
#pragma once

mt19937 rng(time(NULL)); // or mt19937_64
// rng(); // random 32 bits
// shuffle(perm.begin(), perm.end(), rng); // shuffle permutation

int RAND(int lo, int hi) { // uniform distribution
    if (lo > hi) return -1;
	return uniform_int_distribution<int>(lo, hi)(rng);
	//return rng(rng);
}



void solve() {
    int t = RAND(500 , 500); 
    cout << t << '\n';
    while (t--) {
        cout << RAND(1 , 5000) << '\n';
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