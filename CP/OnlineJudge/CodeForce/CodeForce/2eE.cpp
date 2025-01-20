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

struct STLazy {
    int n;
    struct seg {
        int _4 , _7 , _47 , _74;
    };
    vector<seg> tr , lz;

    STLazy(int n) : n(n), tr(4*n + 7), lz(4*n + 7) {}

    seg merge(int node) {
        seg a = tr[le(node)]; 
        seg b = tr[ri(node)];
        return {a._4 + b._4 , a._7 + b._7, max({a._4 + b._47 , a._4 + b._7 , a._47 + b._7}) , max({a.7})}
    }

    void pull(int node) {
        tr[node] = merge(node);
    }

    void push(int node , int l , int r) {
        if (l != r) {
            lz[le(node)] += lz[node]; 
            lz[ri(node)] += lz[node];
        }
        lz1[node] = 0;
        lz[node] = 0;
        return;
    } 

    void build(int node , int l , int r) {
        if (l == r) {
            if (s[l] == '4') tr[node]._4 = 1; 
            else tr[node]._7 = 1;
            return;
        }
        int mid = (l + r) >> 1; 
        build(le(node) , l , mid); 
        build(ri(node) , mid + 1 , r); 
        pull(node);
    }

    void pull(int node , int l , int r) {
        tr[node] = merge()
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
        update(le(node) , l , mid , u , v , val1 , val2); 
        update(ri(node) , mid + 1 , r , u , v , val1 , val2); 
        pull(node , l , r);
    }

    int query(int node , int l , int r , int u , int v) {
        push(node , l , r);
        if (r < u || v < l) return 0; 
        if (u <= l && r <= v) return (-tr[node]+sum[node]); 
        int mid = (l + r) >> 1;
        return query(le(node) , l , mid , u , v) + query(ri(node) , mid + 1 , r , u , v);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    for (int i = 1 ; i <= n ;i ++) {
        if (s[i] == '7') {
            update()
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