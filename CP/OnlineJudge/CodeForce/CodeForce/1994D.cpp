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
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
#pragma once

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

// Pigeonhole Principle

void solve() {
    int n; cin >> n;
    UF dsu = UF(n);
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    vector<bool> was(n); 
    vector<pii> ans;
    for (int i = n - 1; i >= 1 ; i--) {
        //clog << "DEBUG";
        vector<int> f(i + 1 , -1); 
        bool status = false;
        for (int j = 0 ; j < n ; j++) {
            if (was[j]) continue;
            if (f[a[j] % i] == -1) {
                f[a[j] % i] = j; 
            }
            else if (dsu.find(f[a[j] % i]) != dsu.find(j)) {
                dsu.join(f[a[j] % i] , j);
                was[j] = 1;
                ans.push_back(pii(f[a[j] % i] , j));
                status = true;
                break;
            }
        }   
    }
    reverse(ans.begin() , ans.end());
    //cout << (dsu.size(0) == n ? "YES" : "NO"); 
    if (dsu.size(0) == n) {
        cout << "YES\n"; 
        for (auto [u , v] : ans) {
            cout << u + 1 << " " << v + 1 << '\n';
        }
    }
    else cout << "NO\n";
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