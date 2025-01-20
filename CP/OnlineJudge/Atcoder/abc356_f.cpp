//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9;

/**
 * Author: Simon Lindholm
 * Date: 2016-03-22
 * License: CC0
 * Source: hacKIT, NWERC 2015
 * Description: A set (not multiset!) with support for finding the n'th
 * element, and finding the index of an element.
 * To get a map, change \texttt{null\_type}.
 * Time: O(\log N)
 */

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int q , k; cin >> q >> k;
    Tree<int> t;
    set<int> s;
    set<int> r;
    set<int , greater<int>> l;
    while (q--) {
        int ask , x; cin >> ask >> x;
        // for (int c : l) {
        //     cerr << c << " ";
        // }
        // cerr << '\n';
        // for (int c : r) {
        //     cerr << c << " ";
        // }
        // cerr << '\n';
        // for (int c : s) cerr << c << " "; 
        // cerr << '\n';
        // cerr << "================================\n";
        if (ask == 1) {
            if (!s.count(x)) {
                s.insert(x);
                t.insert(x); 
                int xo = t.order_of_key(x);
                if (xo == 0) {
                    l.insert(x);
                }
                else {
                    int pv = *t.find_by_order(xo - 1);
                    if (x - pv > k) {
                        l.insert(x);
                    }
                    else {
                        r.erase(pv);
                    }
                }
                if (xo == sz(t) - 1) {
                    r.insert(x);
                }
                else {
                    int pv = *t.find_by_order(xo + 1);
                    if (pv - x > k) {
                        r.insert(x); 
                    }
                    else {
                        l.erase(pv);
                    }
                }
            }
            else {
                int xo = t.order_of_key(x);
                int pr = -1 , pl = -1;
                if (xo != 0) {
                    pl = *t.find_by_order(xo - 1);
                }
                if (xo != sz(t) - 1) {
                    pr = *t.find_by_order(xo + 1); 
                }
                l.erase(x);
                r.erase(x);
                s.erase(x);
                t.erase(x);
                if (pl != -1) {
                    if (pr == -1) {
                        if (x - pl <= k) 
                            r.insert(pl);
                    }
                    else if (pr - pl > k) r.insert(pl);   
                }
                if (pr != -1) {
                    if (pl == -1) {
                        if (pr - x <= k) {
                            l.insert(pr);
                        }
                    }
                    else if (pr - pl > k) l.insert(pr);
                }
            }
        }
        else {
            int le = *l.lower_bound(x); 
            int ri = *r.lower_bound(x);
            //cout << le << " " << ri << '\n';
            //cout << x << '\n';
            cout << t.order_of_key(ri + 1) - t.order_of_key(le) << '\n';
        }
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
        //example();
    }

}