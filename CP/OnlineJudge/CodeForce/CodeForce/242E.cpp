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
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)


struct SegTree {
    int IT[4*N + 7][20];    
    int add[4*N + 7];

    SegTree(){}
    void push(int node , int l , int r) {
        for (int i = 0 ; i < 20 ; i++) {
            if (add[node] & (1 << i)) {
                IT[node][i] = (r - l + 1) - IT[node][i];
            }
        }
        if (l != r) {   
            add[le(node)] ^= add[node];
            add[ri(node)] ^= add[node];
        }
        add[node] = 0;
    }

    void pull(int node , int l , int r) {
        for (int i = 0 ; i < 20 ; i++) {
            IT[node][i] = IT[le(node)][i] + IT[ri(node)][i];
        }
        return;
    }

    void update(int node , int l , int r , int u , int v , int val) {
        push(node , l , r);
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            add[node] ^= val; 
            push(node , l , r);
            return;
        }
        int mid = (l + r) >> 1;
        update(le(node) , l , mid , u , v , val);
        update(ri(node) , mid + 1 , r , u , v , val); 
        pull(node , l , r);
        return;
    }
    int calc(int node) {
        int res = 0;
        for (int i = 0 ; i < 20 ; i++) {
            res += (1ll << i) * IT[node][i];
        }
        return res;
    }

    int query(int node , int l , int r , int u , int v) {
        push(node , l , r); 
        if (r < u || l > v) return 0; 
        if (u <= l && r <= v) {
            // push(node , l , r);
            return calc(node);     
        }
        int mid = (l + r) >> 1;
        return query(le(node) , l , mid , u , v) + query(ri(node) , mid + 1 , r , u , v);
    }
}ST;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i]; 
        ST.update(1 , 1 , n , i , i , a[i]);
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l , r; cin >> l >> r;
            cout << ST.query(1 , 1 , n , l , r) << '\n';
        }
        else {
            int l , r , x; cin >> l >> r >> x;
            ST.update(1 , 1 , n , l , r , x);
        }
        // for (int i = 1 ; i <= n ;i ++) {
        //     cerr<< ST.query(1 , 1 , n , i , i) << " ";
        // }
        // cerr << '\n';
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