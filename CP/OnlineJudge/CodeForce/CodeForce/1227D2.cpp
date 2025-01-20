//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
 
// #define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
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

void example() { /// start-hash
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).first;
	assert(it == t.lower_bound(9));
	assert(t.order_of_key(10) == 1);
	assert(t.order_of_key(11) == 2);
	assert(*t.find_by_order(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}  /// end-hash

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int , priority_queue<int , vector<int> , greater<int>>> mp;
    vector<int> b(n);  
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        b[i] = a[i];
        mp[a[i]].push(i);
    }  
    sort(all(a) , greater<int>()); 
    int q; cin >> q;
    vector<vector<pii>> adj(n);
    vector<int> ans(q);
    for (int i = 0 ; i < q ; i++) {
        int k , pos; cin >> k >> pos; 
        k--; pos--; 
        adj[k].push_back(pii(i , pos));
    }
    Tree<int> od;
    for (int i = 0 ; i < n ; i++) {
        od.insert(mp[a[i]].top());
        mp[a[i]].pop();
        for (auto [id , pos] : adj[i]) {
            ans[id] = b[*od.find_by_order(pos)];
        }
    }
    for (int i = 0 ; i < q ; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
}
