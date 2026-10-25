#include <bits/stdc++.h>

using namespace std;

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
#pragma once

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

#define sz(x) x.size()

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void example() { /// start-hash
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).first;
	assert(it == t.lower_bound(9));
	assert(t.order_of_key(10) == 1);
	assert(t.order_of_key(11) == 2);
	assert(*t.find_by_order(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}  /// end-hash

int main() {
    int test; cin >> test;  
    int cnt = 0;
    while (test--) {
        cnt++;
        int n , k; cin >> n >> k;
        Tree<int> od;   
        for (int i = 1 ; i <= n ; i++) {
            od.insert(i);
        }
        int cur = 0;
        while (sz(od) > 1) {
            int st = (cur + k - 1 + sz(od))%sz(od); 
            auto it = od.find_by_order(st); 
            //cerr << *it << '\n';
            cur = st;
            od.erase(it);
        }
        cout << "Case " << cnt << ": " << *od.begin() << '\n'; 
    }

}