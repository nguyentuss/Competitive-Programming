//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

/*
a[u]
  += (1+(u−1))−(u−1)⇔a[u]
 += u−(u−1)
a[u+1]
 += (2+(u−1))−(u−1)⇔a[u+1]
 += (u+1)−(u−1)
a[u+2]
 + = (3+(u−1))−(u−1)⇔a[u+2]
 += (u+2)−(u−1)
…
a[v]
 += ((v−u+1)+(u−1))−(u−1)⇔a[v]
 += v−(u−1)*/   

struct STLazy {
    int n;
    vector<int> tr , lz , lz1 , sum ;

    STLazy(int n) : n(n), tr(4*n + 7), lz(4*n + 7), lz1(4*n + 7), sum(4*n + 7) {}

    void push(int node , int l , int r) {
        tr[node] += (r - l + 1)*lz[node];
        sum[node] += lz1[node]*(r*(r + 1)/2 - (l-1)*(l)/2);
        if (l != r) {
            lz[le(node)] += lz[node]; 
            lz[ri(node)] += lz[node];
            lz1[le(node)] += lz1[node]; 
            lz1[ri(node)] += lz1[node];
        }
        lz1[node] = 0;
        lz[node] = 0;
        return;
    } 

    void pull(int node , int l , int r) {
        tr[node] = tr[le(node)] + tr[ri(node)];
        sum[node] = sum[le(node)] + sum[ri(node)];
        return;
    }

    void update(int node , int l , int r , int u , int v , int val1 , int val2) {
        push(node , l , r);
        if (r < u || v < l) return; 
        if (u <= l && r <= v) {
            lz[node] = val1;
            lz1[node] = val2;
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
    int n , q; cin >> n >> q;
    vector<int> a(n + 3);
    STLazy ST(n + 1);
    vector<int> f(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    while (q--) {
        int type , a , b; cin >> type >> a >> b; 
        if (type == 1) {
            ST.update(1 , 1 , n , a , b , a - 1 , 1);
        }
        else {
            cout << f[b] - f[a - 1] + ST.query(1 , 1 , n, a , b) << '\n';
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}