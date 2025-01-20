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
const int N = 2e5 + 7; 

struct ST {
    int n; 
    vector<int> tr; 
    
    ST(int n): n(n) , tr(4*n + 7 , 0) {}

    void update(int node , int l , int r , int pos , int val) {
        if (pos < l || r < pos) return;
        if (l == r) {
            tr[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(le(node) , l , mid , pos , val); 
        update(ri(node) , mid + 1 , r ,  pos , val); 
        tr[node] = max(tr[le(node)] , tr[ri(node)]);
    }

    int get(int node , int l , int r , int lower_bound , int k) {
        if (tr[node] < k) return -1; 
        if (r < lower_bound) return -1;
        if (l == r) return l; 
        int mid = (l + r) >> 1; 
        int res = -1; 
        if (tr[le(node)] >= k) {
            res = get(le(node) , l , mid , lower_bound , k);
        }
        if (res == -1) res = get(ri(node) , mid + 1 , r , lower_bound , k);
        return res;
    }
};

struct STLazy {
    int n;
    vector<int> tr;
    vector<int> lz;

    STLazy(int n) : n(n), tr(4*n + 7), lz(4*n + 7) {}

    void pull(int node , int l , int r) {
        tr[node] = tr[le(node)] + tr[ri(node)];
        return;
    }

    void push(int node , int l , int r) {
        if (lz[node]) {
            tr[node] = (r - l + 1) * lz[node];
            if (l != r) {
                lz[le(node)] = lz[node]; 
                lz[ri(node)] = lz[node];   
            }
            lz[node] = 0;
        }
        return;
    } 

    void update(int node , int l , int r , int u , int v , int val) {
        push(node , l , r);
        if (r < u || v < l) return; 
        if (u <= l && r <= v) {
            lz[node] = val;
            push(node , l , r);
            return;
        }
        int mid = (l + r) >> 1;
        update(le(node) , l , mid , u , v , val); 
        update(ri(node) , mid + 1 , r , u , v , val); 
        pull(node , l , r);
    }
    
    int query(int node , int l , int r , int u , int v) {
        push(node , l , r);
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return tr[node]; 
        int mid = (l + r) >> 1;
        return query(le(node) , l , mid , u , v) + query(ri(node) , mid + 1 , r , u , v);
    }
};

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
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
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
    int n , m; cin >> n >> m;
    vector<int> a(n + 1);
    ST st(n + 1);
    STLazy IT(n + 1);
    Tree sum(n + 3);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        sum.update(i , a[i]);
        st.update(1 , 1 , n , i , a[i]);
    }
    
    auto calc = [&](int u,int v) {
        if (u > v) return;
        int l = u;
        int x = a[u];
        while (true) {
            int r = st.get(1 , 1 , n , l + 1 , x + 1);
            if (r == -1 || r > v) {
                IT.update(1 , 1 , n , l , v , x);
                break;
            }
            IT.update(1 , 1 , n , l , r - 1, x);
            x = a[r]; 
            l = r;
        }
    };
    calc(1 , n); 
    
    int left_checkpoint = 0;
    set<int> s;
    s.insert(0); 
    s.insert(n);
    while (m--) {
        int type; cin >> type; 
        if (type == 1) {
            int p , x; cin >> p >> x;
            a[p] = x; 
            sum.update(p , a[p]);
            st.update(1 , 1 , n , p , a[p]);
            auto it = s.lower_bound(p);
            it--;
            calc(*(it) + 1 , *s.lower_bound(p));    
        }
        if (type == 2) {
            int p; cin >> p; 
            s.insert(p);
            calc(p + 1 , *s.upper_bound(p));
        }
        if (type == 3) { 
            int l , r; cin >> l >> r;
            auto it = s.lower_bound(l);
            int vr = *s.lower_bound(l);
            it--;
            int vl = *it;
            calc(l , vr);
            cout << IT.query(1 , 1 , n , l , r) - sum.query(l , r + 1) << '\n';
            calc(vl + 1 , vr);
        }
        // for (int i = 1 ; i <= n ; i++) {
        //     cerr << IT.query(1 , 1 , n , i , i) << " ";
        // }
        // cerr << '\n';
    }
    // cout << IT.query(1 , 1 , n , 1 , n);
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
