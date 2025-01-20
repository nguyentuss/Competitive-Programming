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
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
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
        if (b >= e) return 0;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

/**
 * Author: NXT
 * Date: 2016-10-08
 * License: CC0
 * Source: NXT
 * Description: Segment tree with ability to set values of large intervals [L, R), and compute max of intervals.
 * Can be changed to other things. 
 * Time: O(\log N).
 * Status: tested
 */
struct STLazy {
	int n;
	vector<int> tr, lz;
	STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8) {}

	void push(int v, int lo, int hi) {
		if (lz[v] != 0) {
			tr[v] += (hi - lo)*lz[v];
			if(lo+1 != hi) {
				lz[v*2] += lz[v];
				lz[v*2+1] += lz[v]; 
			}
			lz[v] = 0;
		}
	}
	void update(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return;
		if (lo >= l && hi <= r) {
			lz[v] += val; // put lazy tag here
			push(v, lo, hi);
			return;
		}

		int mid = (lo + hi) / 2;
		update(v*2, lo, mid, l, r, val);
		update(v*2 + 1, mid, hi, l, r, val);

		tr[v] = max(tr[2*v], tr[2*v+1]);
	}
	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return 0;
		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return max(p1, p2);
	}

	void update(int l, int r, int val) {
		update(1, 0, n, l, r, val);
	}
	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};


void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); 
    vector<int> b(n);
    Tree IT(n);
    Tree neg(n);
    STLazy st(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        st.update(i , i + 1 , a[i]);
    }
    
    for (int i = 1 ; i < n ; i++) {
        b[i] = a[i] - a[i - 1];
        IT.update(i , b[i]);
        neg.update(i , min(0ll , b[i]));
    }
    //cout << a[0] << " " << IT.query(1 , 4) << " " << neg.query(1 , 4) << '\n';
    while (q--) {
        int type; cin >> type; 
        if (type == 1) {
            int l , r , k; cin >> l >> r >> k;
            l--; r--;
            st.update(l , r + 1 , k);
            if (l != 0) {
                b[l] += k;
                IT.update(l , b[l]);
                neg.update(l , min(0ll, b[l]));
            }
            if (r != n - 1) {
                b[r + 1] -= k;
                IT.update(r + 1 , b[r + 1]);
                neg.update(r + 1 , min(0ll , b[r + 1]));
            }
        }
        else {
            int l , r; cin >> l >> r;
            l--; r--; 
            cout << st.query(l , l + 1) + IT.query(l + 1 , r + 1) - neg.query(l + 1 , r + 1) << '\n'; 
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