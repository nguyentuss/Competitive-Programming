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

struct Point {
    int x , y1 , y2 , type; 
    bool operator < (const Point &other) {
        if (x != other.x) return type < other.type;
        return x < other.x;
    }
};

struct constr {
    int even , odd;6
}

struct STLazy {
    int n; 
    vector<int> tr;
    vector<int> lz;

    STLazy(int n): n(n), tr(4*n + 7), lz(4*n + 7){};

    void push(int id , int l , int r) {
        if (lz[id] != 0) {
                
        }
    }

    void update(int id, int l , int r , int u , int v , int type) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            lz[id] = type;
            push(id , l , r);
            return;
        }

    }
};

void solve() {
    int n; cin >> n;
    vector<Point> P;
    vector<int> normalization;
    for (int i = 0 ; i < n ; i++) {
        int x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2;
        P.push_back({x1 , y1 , y2 , 1});
        P.push_back({x2 , y1 , y2 , -1});
        normalization.push_back(y1);
        normalization.push_back(y2);
    }
    sort(all(normalization));
    normalization.erase(unique(all(normalization)),normalization.end());
    int m = sz(normalization);
    map<int , int> mp;
    vector<int> pre(n + 1); 
    for (int i = 0 ; i < m ; i++) {
        pre[i + 1] = pre[i] + normalization[i];
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
