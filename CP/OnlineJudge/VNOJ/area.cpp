//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll)|1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int N = 3e5 + 7;

struct Point {
    int x, l , r , type; 

    bool operator < (const Point &other) {
        if (x == other.x) return type > other.type;
        return x < other.x;
    }  
};

/*
    the segment tree contains two value :
    + the number of rectangle covered that node
    + the number of value which have the rectangle cover
*/ 

struct STLazy {
    int n;
    vector<pii> tr; 
    vector<int> lz;
    STLazy(int n) : n(n), tr(4*n + 7 , {0 , 0}), lz(4*n + 7 , 0){
        build(1 , 1 , n);
    };
    
    void build(int id , int l , int r){
        if (l == r) {
            tr[id] = {0, 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(le(id) , l , mid);
        build(ri(id) , mid + 1 , r);
        tr[id].second = tr[le(id)].second + tr[ri(id)].second;
    }

    void push(int id , int l , int r) {
        if (lz[id] != 0) {
            tr[id].first += lz[id];
            if (l != r) {
                lz[le(id)] += lz[id]; 
                lz[ri(id)] += lz[id];
            }
            lz[id] = 0;
        }
    }

    void pull(int id , int l , int r) {
        auto a = tr[le(id)];
        auto b = tr[ri(id)];
        if (a.first == b.first) {
            tr[id].first = a.first;
            tr[id].second = a.second + b.second;
        }
        else tr[id] = min(a , b);
        return;
    }

    void update(int id , int l , int r , int u , int v , int val) {
        push(id , l , r);
        if (r < u || v < l || u > v) return;
        if (u <= l && r <= v) {
            lz[id] = val;
            push(id , l , r);
            return;
        }
        int mid = (l + r) >> 1;
        update(le(id) , l , mid , u , v , val);
        update(ri(id) , mid + 1 , r , u , v, val);
        pull(id , l , r);
    }
    pii query(int id, int l , int r , int u , int v) {
        push(id , l , r);
        if (r < u || v < l) return tr[id];
        if (u <= l && r <= v) return tr[id];
        int mid = (l + r) >> 1;
        auto x1 = query(le(id), l , mid , u , v);
        auto x2 = query(ri(id), mid + 1 , r , u , v);
        if (x1.first == x2.first) {
            return {x1.first , x1.second + x2.second};
        }
        else if (x1.first < x2.first) {
            return x1;
        }
        else return x2;
    }

    void update(int l , int r , int val) {
        update(1 , 0 , n-1 , l , r , val);
    }

    int query(int l , int r) {
        auto [x1 , x2] = query(1 , 0 , n-1 , l , r); 
        if (x1 > 0) {
            return r - l + 1;
        }
        else {
            return (r - l + 1) - x2;
        }
    }
};

void solve() {
    int n; cin >> n;
    vector<Point> P;
    for (int i = 0 ; i < n ; i++) {
        int x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2; 
        P.push_back({x1 , y1 , y2-1 , 1});
        P.push_back({x2 , y1 , y2-1, -1});
    }
    sort(P.begin() , P.end());
    STLazy ST(N);
    ST.update(1 , 10 , 1);
    ST.update(1 , 10 , 1);
    ST.update(11, 20 , 1);
    cout << ST.query(1 , 20);
    // int ans = 0;
    // ST.update(P[0].l , P[0].r , P[0].type);
    // for (int i = 1 ; i < sz(P) ; i++) {
    //     ans += 1LL*(P[i].x - P[i-1].x)*ST.query(0,N-1);
    //     ST.update(P[i].l , P[i].r , P[i].type);
    // }
    // cout << ans;
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
