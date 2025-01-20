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
    vector<int> tr;
    vector<int> lz_add;
    vector<int> lz_set;
    STLazy(int n) : n(n), tr(4*n + 8), lz_add(4*n + 8), lz_set(4*n + 8) {}
 
    void push(int v, int lo, int hi) {
        if (lz_add[v] != 0) {
            tr[v] += lz_add[v]*(hi - lo);
            if(lo+1 != hi) {
                if (lz_set[2 * v] != 0) {
                    lz_set[2 * v] += lz_add[v]; 
                    lz_add[2 * v] = 0; 
                }
                else {
                    lz_add[2 * v] += lz_add[v];
                }
                if (lz_set[2 * v + 1] != 0) {
                    lz_set[2 * v + 1] += lz_add[v]; 
                    lz_add[2 * v + 1] = 0;
                }
                else {
                    lz_add[2 * v + 1] += lz_add[v];
                }
            }
            lz_add[v] = 0;
        }
        if (lz_set[v] != 0) {
            tr[v] = lz_set[v] * (hi - lo);
            if (lo + 1 != hi) {
                lz_add[2 * v] = 0; 
                lz_add[2 * v + 1] = 0; 
                lz_set[2 * v] = lz_set[v]; 
                lz_set[2 * v + 1] = lz_set[v];
            }
            lz_set[v] = 0;
        }
    }
    void update(int v, int lo, int hi, int l, int r, int val , bool status) {
        push(v, lo, hi);
        if (lo >= hi || lo >= r || hi <= l) return;
        if (lo >= l && hi <= r) {
            if (status) lz_set[v] = val , lz_add[v] = 0; 
            else lz_add[v] = lz_add[v] + lz_set[v] + val , lz_set[v] = 0;
            push(v, lo, hi);
            return;
        }
 
        int mid = (lo + hi) / 2;
        //push(v, lo, hi);
        update(v*2, lo, mid, l, r, val , status);
        update(v*2 + 1, mid, hi, l, r, val , status);
 
        tr[v] = tr[2*v] + tr[2*v+1];
    }
    int query(int v, int lo, int hi, int l, int r) {
        push(v, lo, hi);
        if (lo >= hi || lo >= r || hi <= l) return 0;
        if (lo >= l && hi <= r) return tr[v];
    
        int mid = (lo + hi)/2;
        int p1 = query(v*2, lo, mid, l, r);
        int p2 = query(v*2 + 1, mid, hi, l, r);
        
        return p1 + p2;
    }
 
    void update(int l, int r, int val , bool status) {
        update(1, 0, n, l, r, val , status);
    }
    int query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};
 
void solve() {
    int n ,q; cin >> n >> q;
    STLazy ST(n + 3);
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        ST.update(i , i + 1 , x , 0);
    }
    // for (int i = 1 ; i <= n ; i++) {
    //             cerr << ST.query(i , i + 1) << " ";
    // }
    // cerr << '\n';
    while (q--) {
        int ask; cin >> ask;
        if (ask == 1) {
            int a , b , x; cin >> a >> b >> x;
            a--; b--;
            ST.update(a , b + 1 , x , 0);
            // for (int i = a ; i <= b ; i++) {
            //     cerr << ST.query(i , i + 1) << " ";
            // }
            // cerr << '\n';
        }
        if (ask == 2) {
            int a , b , x; cin >> a >> b >> x;
            a--; b--;
            ST.update(a , b + 1 , x , 1); 
            //cerr << "YES";
            // for (int i = a ; i <= b ; i++) {
            //     cerr << ST.query(i , i + 1) << " ";
            // }
            // cerr << '\n';
        }
        if (ask == 3) {
            int a , b; cin >> a >> b;
            a--; b--;
            cout << ST.query(a , b + 1) << '\n';
        }
    }
 
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}