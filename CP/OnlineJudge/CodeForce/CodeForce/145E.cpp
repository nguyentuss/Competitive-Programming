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

struct seg {
    int _4 , _7 , _47 , _74;
};

struct STLazy {
    int n;
    vector<seg> tr;
    vector<int> lz;
    vector<char> s;

    STLazy(int n) : n(n), tr(4*n + 7), lz(4*n + 7) , s(n + 1) {}

    seg merge(seg a , seg b) {
        return {a._4 + b._4 , a._7 + b._7, max({a._4 + b._47 , a._4 + b._7 , a._47 + b._7}) 
        , max({a._74 + b._4 , a._7 + b._4 , a._7 + b._74})};
    }

    void pull(int node , int l , int r) {
        tr[node] = merge(tr[le(node)] , tr[ri(node)]);
        return;
    }

    void push(int node , int l , int r) {
        if (lz[node]) {
            swap(tr[node]._4 , tr[node]._7); 
            swap(tr[node]._47 , tr[node]._74);
            if (l != r) {
                lz[le(node)] ^= 1;
                lz[ri(node)] ^= 1;
            }
            lz[node] = 0;
        }
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
        pull(node , l , r);
    }

    void update(int node , int l , int r , int u , int v) {
        push(node , l , r);
        if (r < u || v < l) return; 
        if (u <= l && r <= v) {
            lz[node] = 1;
            push(node , l , r);
            return;
        }
        int mid = (l + r) >> 1;
        update(le(node) , l , mid , u , v); 
        update(ri(node) , mid + 1 , r , u , v); 
        pull(node , l , r);
    }

    seg query(int node , int l , int r , int u , int v) {
        push(node , l , r);
        if (r < u || v < l) return {0,0,0,0}; 
        if (u <= l && r <= v) return tr[node]; 
        int mid = (l + r) >> 1;
        return merge(query(le(node) , l , mid , u , v),query(ri(node) , mid + 1 , r , u , v));
    }
};

void solve() {
    int n, m; cin >> n >> m;
    STLazy ST(n + 3);
    for (int i = 1 ; i <= n ;i ++) {
        char c; cin >> c; 
        ST.s[i] = c; 
    }
    ST.build(1 , 1 , n);
    while (m--) {
        string s; cin >> s; 
        if (s == "count") {
            seg tmp = ST.query(1 , 1 , n , 1 , n);
            // cout << tmp._4 << " " << tmp._7 << " " << tmp._47 << '\n';
            cout << max({tmp._4 , tmp._7 , tmp._47}) << '\n';
            // cout << ST.query(1 , 1 , n , 1 , n);
        }
        else {
            int l , r; cin >> l >> r;
            ST.update(1 , 1 , n , l , r);
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