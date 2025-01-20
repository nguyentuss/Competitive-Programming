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
const int N = 5e5 + 7; 

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
			tr[v] += lz[v];
			if(lo+1 != hi) {
				lz[v*2] += lz[v];
				lz[v*2+1] += lz[v]; 
			}
			lz[v] = 0;
		}
	}
    void add(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return;
		if (lo >= l && hi <= r) {
			lz[v] += val; // put lazy tag here
			push(v, lo, hi);
			return;
		}
		int mid = (lo + hi) / 2;
		add(v*2, lo, mid, l, r, val);
		add(v*2 + 1, mid, hi, l, r, val);

		tr[v] = max(tr[2*v], tr[2*v+1]);
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

		tr[v] = min(tr[2*v], tr[2*v+1]);
	}
	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return inf;
		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return min(p1, p2);
	}

	void update(int l, int r, int val) {
		update(1, 0, n, l, r, val);
	}
	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};


void solve() {
    int n , k; cin >> n >> k;
    string s; cin >> s; 
    string t; cin >> t;        
    if (t[n - 1] == 'B') t[n] = 'W';
    else t[n] = 'B';
    STLazy ST_W(n);
    STLazy ST_B(n);
    vector<int> f(n + 1);
    int j = 0;
    for (int i = 0 ; i < n ;i ++) {
        //cerr << i << " " << j << '\n';
        if (i == j) {
            while (t[j] == t[j + 1] && j <= n) j++; 
            if (t[i] == 'W') {
                ST_W.add(1 , 0 , n , 0 , j + 1 , 1);
            }
            if (t[j] == 'B') {
                ST_B.add(1 , 0 , n , 0 , j + 1 , 1);
                //cout << i << " " << j << '\n';
            }
            j++;
        }
        ST_W.update(i , i + 1  , f[max(0ll ,i - 1)]);
        ST_B.update(i , i + 1 , f[max(0ll , i - 1)]);
        if (s[i] == t[i]) f[i] = f[max(0ll , i - 1)];
        else {
            int m1 = ST_W.query(max(0ll , i - k + 1) , i + 1);
            int m2 = ST_B.query(max(0ll , i - k + 1) , i + 1);
            f[i] = min(m1 , m2) + 1; 
        }
    }
    cout << f[n - 1] << '\n';
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