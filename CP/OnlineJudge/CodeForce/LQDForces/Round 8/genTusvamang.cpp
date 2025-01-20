//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;


#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9;
// #define time() cerr << endl << "-------------Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms.";
// #define endl '\n'

/**
 * Author: Neko
 * Date: 2015-03-19
 * License: CC0
 * Source: me
 * Description: Random number generators.
 */
#pragma once

mt19937 rng(time(NULL)); // or mt19937_64
// rng(); // random 32 bits
// shuffle(perm.begin(), perm.end(), rng); // shuffle permutation 

int RAND(int lo, int hi) { // uniform distribution
    if (lo > hi) return -1;
	return uniform_int_distribution<int>(lo, hi)(rng);
	//return rng(rng);
}

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

void example() { /// start-hash
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).first;
	assert(it == t.lower_bound(9));
	assert(t.order_of_key(10) == 1);
	assert(t.order_of_key(11) == 2);
	assert(*t.find_by_order(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}  /// end-hash


vector<bool> visited;

bool dfs(int node, const vector<vector<bool>> &cap, vector<int> &path){
    if(visited[node]) return false;
    if(node == cap.size()-1){
        path.push_back(node);
        return true;
    }
    visited[node] = true;
    for(int i = 0; i < cap[node].size(); ++i){
        if(!cap[node][i]) continue;
        if(!dfs(i, cap, path)) continue;
        path.push_back(node);
        return true;
    }
    return false;
}
int MaxFlow(vector<vector<bool>> &cap){
    vector<int> path;
    visited = vector<bool>(cap.size(), false);
    while(dfs(0, cap, path)){
        int u = path.back();
        for(int i = path.size()-2; i >= 0; --i){
            int v = path[i];
            cap[u][v] = 0;
            cap[v][u] = 1;
            u = v;
        }
        path = vector<int>();
        visited = vector<bool>(cap.size(), false);
    }
    int ans = 0;
    for(bool val: cap.back()) ans += val;
    return ans;
}

void solve() {
    int n = 100;
    vector<pii> vv;
    visited.clear();
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = i + 1 ; j <= n ; j++) {
            if ((i + j)%2) {
                vv.push_back(pii(i , j));
                //cerr << i << " " << j << '\n';
            }
        }
    }
    int q = RAND(1 , min(100ll,sz(vv)));
    // cout << n << " " << q << '\n';
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << RAND(1 , 1'00) << " ";
    // }
    // cout << '\n';
    
    Tree<int> s;
    for (int i = 0 ; i < sz(vv) ; i++) s.insert(i);
    // while (q--) {
    //     assert(sz(s) > 0);
    //     int x = RAND(0 , sz(s) - 1);
    //     auto it = s.find_by_order(x);
    //     int vl = *it; 
    //     //cerr << vl << " " << x << '\n';
    //     cout << v[vl].first << " " << v[vl].second << '\n';
    //     s.erase(it);
    // }

    vector<int> vertexVal, from(n);

    for(int i = 0; i < n; ++i){
        int a = RAND(1 , 1'000'000'000);

        from[i] = vertexVal.size();
        while(a%2 == 0){
            a/=2;
            vertexVal.push_back(2);
        }
        for(int i = 3; i*i <= a; i+=2){
            while(a%i == 0){
                a/=i;
                vertexVal.push_back(i);
            }
        }
        if(a!=1) vertexVal.push_back(a);
    }

    vector<vector<bool>> cap(vertexVal.size()+2, vector<bool>(vertexVal.size()+2, 0));

    for(int i = 0; i < q; ++i){
        int x = RAND(0 , sz(s) - 1);
        auto it = s.find_by_order(x);
        int vl = *it; 
        //cerr << vl << " " << x << '\n';
        int u = vv[vl].first; 
        int v = vv[vl].second;
        //cout << v[vl].first << " " << v[vl].second << '\n';
        s.erase(it);


        // int u, v;
        // cin >> u >> v;
        u--; v--;
        if(u%2) swap(u,v);

        int r = (u+1<from.size()? from[u+1]:vertexVal.size());
        for(int i = from[u]; i < r; ++i){
            cap[0][i+1] = 1;

            int r = (v+1<from.size()?from[v+1]:vertexVal.size());
            for(int j = from[v]; j < r; ++j){
                cap[j+1].back() = 1;

                if(vertexVal[i] != vertexVal[j]) continue;
                cap[i+1][j+1] = 1;
            }
        }
    }
    cerr << endl << "-------------Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms.";
    //cout << MaxFlow(cap) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1000;
    //cin >> test;
    while (test--) {
        solve();
    }

}