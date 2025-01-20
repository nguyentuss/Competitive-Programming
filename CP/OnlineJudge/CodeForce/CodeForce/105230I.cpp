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

void solve() {
    int n , m; cin >> n >> m;
    UF dsu = UF(n); 
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        dsu.join(u , v);
    }
    vector<int> cnt(n); 
    for (int i = 0 ; i < n ; i++) {
        cerr << dsu.find(i) << " ";
        cnt[dsu.find(i)]++;
    }
    int sum = 0;
    vector<int> v;
    for (int i = 0 ; i < n ; i++) {
        if (cnt[i] > 1) {
            v.push_back(cnt[i]); 
            sum += cnt[i];
        }
    }
    int ans = 0; 
    for (auto x : v) {
        cerr << x << " ";
        sum -= x; 
        ans = ans + sum*x;
    }
    cout << ans << '\n';
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