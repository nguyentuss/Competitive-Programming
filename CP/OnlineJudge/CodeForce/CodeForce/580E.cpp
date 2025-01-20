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
const int N = 1e5 + 7;

int pw[N];

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
const int N = 1e5 + 7;
const int base = 311;

struct STLazy {
    int n;
    vector<int> tr;
    vector<int> lz;
    vector<int> pw;
    vector<vector<int>> hash;

    STLazy(int n) : n(n), tr(4*n + 7), lz(4*n + 7) {}

    void init() {
        pw.assign(n + 1);
        pw[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            pw[i] = pw[i - 1] * base;
        }
        hash.assign(n + 1 , vector(10));
        for (int j = 0 ; j <= 9 ; j++) {
            for (int i = 1 ; i <= ; j++) {
                hash[i][j] = hash[i - 1][j]*base + (j + 1);
            }
        }
    }

    void pull(int node , int l , int r) {
        int mid = (l + r) >> 1; 
        int sz = (mid - l + 1);
        tr[node] = tr[le(node)] + tr[ri(node)] * pw[sz];
        return;
    }

    void push(int node , int l , int r) {
        if (lz[node]) {
            tr[node] = pw[r - l + 1][lazy[node]];
            if (l != r) {
                lz[le(node)] = lz[node]; 
                lz[ri(node)] = lz[node];
            }
            lz[node] = 0;
        }
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
        update(le(node) , l , mid , u , v); 
        update(ri(node) , mid + 1 , r , u , v); 
        pull(node , l , r);
    }
    
    int query(int node , int l , int r , int u , int v) {
        push(node , l , r);
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return tr[node]; 
        int mid = (l + r) >> 1;
        return query(le(node) , l , mid , u , v) + query(ri(node) , mid + 1 , r , u , v)*pw[mid - l + 1];
    }
};

void solve() {
    int n , m , k; cin >> n >> m >> k;
    STLazy ST(n + 1);
    ST.init();
    for (int i = 1 ; i <= n ; i++) {
        char c; cin >> c;
        ST.update(1 , 1 , n , i , i , c - '0');
    }
    int q = m + k;
    while (q--) {
        int type , l , r , c; cin >> type >> l >> r >> c;
        if (type == 1) {
            ST.update(1 , 1 , n , l , r , c - '0');
        }
        else {
            int x = ST.query(1 , )
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