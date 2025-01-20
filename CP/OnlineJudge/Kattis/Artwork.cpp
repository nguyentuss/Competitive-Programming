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


const int N = 1e3 + 7;
int a[N][N];
int mark[N][N];
bool vis[N][N];

void solve() {
    int n , m; cin >> n >> m;
    int q; cin >> q;
    vector<tuple<int , int , int , int>> ask; 
    while (q--) {
        int x1 , x2 , y1 , y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        for (int x = x1 ; x <= x2 ; x++) {
            for (int y = y1 ; y <= y2 ; y++) {
                a[x][y]++; 
            }
        }
        ask.emplace_back(x1 , x2 , y1 , y2);
    }
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) {
    //         cerr << a[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    auto inside = [&](int x , int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };
    int idx = 0;
    UF dsu = UF(n * m + 4);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            mark[i][j] = ++idx;
            if (a[i][j]) continue;
            if (inside(i - 1 , j) && !a[i - 1][j]) {
                dsu.join(mark[i][j] , mark[i - 1][j]);
            }
            if (inside(i , j - 1) && !a[i][j - 1]) {
                dsu.join(mark[i][j] , mark[i][j - 1]);
            } 
        }
    }
    int cc = 0;
    vector<int> cnt(n * m + 4); 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j ++) {
            if (!a[i][j] && !cnt[dsu.find(mark[i][j])]) {
                cc++; 
                cnt[dsu.find(mark[i][j])]++; 
            }
        }
    }

    auto calc = [&](int i , int j , int x , int y) -> bool {
        if (inside(i , j) && a[i][j] == 0 && dsu.join(mark[i][j] , mark[x][y])) {
            cc--;
            return true;
        }
        return false; 
    };
    vector<int> ans;
    ans.push_back(cc);
    //cout << cc << '\n';
    reverse(ask.begin() , ask.end()); 
    for (auto [x1 , x2 , y1 , y2] : ask) {
        for (int i = x1 ; i <= x2 ; i++) {
            for (int j = y1 ; j <= y2 ; j++) {
                a[i][j] --; 
                if (!a[i][j]) {
                    cc++;
                    bool ok = calc(i - 1 , j , i , j) | calc(i , j - 1 , i , j) | calc(i + 1 , j , i , j) | calc(i , j + 1 , i , j);
                }
            } 
        }
        //cout << cc << '\n';
        ans.push_back(cc);
    }
    reverse(ans.begin() , ans.end());
    for (int i = 1 ; i < sz(ans) ; i++) cout << ans[i] << '\n';
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