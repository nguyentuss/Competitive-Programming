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
const int N = 2e5 + 7;
vector<vector<int>> IT(4*N); 

void update(int id , int i, int x , int l , int r , int val) {
    if (r < i || l > i) {
        return;
    }
    if (l == r) {
        IT[x][id] = val; 
        return;
    }
    int mid = (l + r)/2; 
    update(2*id , i , x , l , mid , val);
    update(2*id + 1 , i , x , mid + 1 , r , val); 
    IT[x][id] = IT[x][2*id] + IT[x][2*id + 1];
}

int get(int id , int x , int u , int v , int l , int r) {
    if (v < l || r < u) return 0;
    if (l <= u && v <= r) return IT[x][id];
    int mid = (u + v)/2; 
    return get(2*id , x , u , mid , l , r) + get(2*id + 1 , x , mid + 1 , v , l , r); 
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> cnt(N);
    vector<int> a(n + 1);
    vector<vector<int>> adj(N);
    
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        adj[a[i]].push_back(i);
    }
    
    for (int i = 1 ; i < N ; i++) {
        if (cnt[i]) {
            IT[i].assign(4*cnt[i] + 3 , 0);
        }
    }
    vector<int> mp(N);
    vector<int> f(n + 1); 
    for (int i = 1 ; i <= n ; i++) {
        f[i] = mp[a[i]] + 1; 
        mp[a[i]]++; 
    }
    for (int i = 1 ; i <= n ; i++) {
        update(1 , f[i] , a[i] , 1 , cnt[a[i]] , i * i);
    }
    //cout << get(1 , 1 , 1 , cnt[1] , 1 , 3);
    int last = 0;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int p; cin >> p; 
            p = (p + last - 1)%(n - 1) + 1;
            if (a[p] == a[p + 1]) continue;
            update(1 , f[p] , a[p] , 1 , cnt[a[p]] , (p + 1) * (p + 1));
            update(1 , f[p + 1] , a[p + 1] , 1 , cnt[a[p + 1]] , p * p);
            adj[a[p]][f[p] - 1] = p + 1;
            adj[a[p+1]][f[p+1] - 1] = p;
            swap(f[p] , f[p + 1]);
            swap(a[p],a[p+1]);
        }
        else {
            int l , r , x; cin >> l >> r >> x; 
            l = (l + last - 1)%n + 1; 
            r = (r + last - 1)%n + 1;
            x = (x + last - 1)%n + 1; 
            if (l > r) swap(l , r); 
            //cerr << type << " " << l << " " << r << " " << x << '\n';
            if (type == 2) {
                int left = 0 , right = cnt[x] - 1;
                int lo = -1 , hi = -1;
                while (left <= right) {
                    int mid = (left + right)/2; 
                    if (adj[x][mid] >= l) {
                        right = mid - 1; 
                        lo = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                left = 0 , right = cnt[x] - 1; 
                while (left <= right) {
                    int mid = (left + right)/2;
                    if (adj[x][mid] <= r) {
                        left = mid + 1; 
                        hi = mid;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                //cerr << lo << " " << hi << '\n';
                if (lo > hi || lo == -1 || hi == -1) {
                    last = 0;
                }
                else last = get(1 , x , 1 , cnt[x] ,lo + 1 , hi + 1);
                cout << last << '\n';
            }
            else {
                last = get(1 , x , 1 , cnt[x] , l , r);
                cout << last << '\n';
            }
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