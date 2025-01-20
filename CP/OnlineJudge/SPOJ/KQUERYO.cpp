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
const int N = 1e5 + 7;

/**
 * Author: Tus
 * Date: 2017-07-23
 * License: CC0
 * Source: https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree
 * Description: Preserving the history of its values
 * Time: O(\log N)
 * Status: Tested on CSES 1737
 */

int a[N];

struct node {
    int sum; 
    node *l , *r; 
    node() {
        sum = 0; 
        l = r = nullptr;
    }
};

int get_sum(node *x) {
    if (!x) return 0; 
    return x->sum;
}

void build(node *cur , int l , int r) {
    if (l == r) {
        cur -> sum = 0; 
        return;
    }
    cur -> l = new node(); 
    cur -> r = new node();
    int mid = (l + r)/2; 
    build(cur -> l , l , mid);
    build(cur -> r , mid + 1 , r);
    cur -> sum = get_sum(cur->l) + get_sum(cur->r);
}

void update(node *cur , node *prev, int i , int l , int r , int val) {
    if (l == r) {
        cur -> sum = prev -> sum + val;
        return;
    }
    int mid = (l + r)/2;
    if (i <= mid) {
        cur -> l = new node(); 
        cur -> r = prev -> r; 
        update(cur -> l, prev -> l , i , l , mid , val); 
    }
    else {
        cur -> r = new node();
        cur -> l = prev -> l;
        update(cur -> r, prev -> r , i , mid + 1 , r , val);
    }
    cur -> sum = get_sum(cur->l) + get_sum(cur->r);
    return;
}

int query(node *cur , int l , int r , int L , int R) {
    if (l > R || r < L) return 0;
    if (L <= l && r <= R) return cur -> sum; 
    int mid = (l + r)/2; 
    return (query(cur -> l , l , mid , L , R) + query(cur -> r , mid + 1 , r , L , R));
}

node *root[N];

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    map<int , int> mp;
    vector<int> v; 
    int mx = 0;
    for (int x : s) {
        v.push_back(x);
        mp[x] = ++mx;
    }
    root[0] = new node(); 
    build(root[0] , 1 , mx);
    for (int i = 1 ; i <= n ; i++) {
        root[i] = new node();
        update(root[i] , root[i - 1] , mp[a[i]] , 1 , mx , 1ll);
    }
    int last_ans = 0;
    int q; cin >> q;
    while (q--) {
        int a , b , c; cin >> a >> b >> c;
        int i = a ^ last_ans;
        int j = b ^ last_ans;
        int k = c ^ last_ans;   
        if (i < 1) i = 1; 
        if (j > n) j = n; 
        int val = upper_bound(v.begin() , v.end() , k) - v.begin(); 
        if (val >= sz(v) || i > j) {
            last_ans = 0;
            cout << 0 << '\n';
        }
        else {
            val = mp[v[val]];
            last_ans = query(root[j], 1 , mx , val , mx) - query(root[i - 1], 1 , mx , val , mx);
            cout << last_ans << '\n';
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
    }

}