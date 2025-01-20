//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int lz = 0, val = 0 , prev = 0;
};

struct Segtree {
    vector<seg> IT;
    Segtree(int n) {
        IT.resize(4*n + 7 , {0 , 0 , 0});
        for (int i = 0 ; i < (int) IT.size() ; i++) {
            IT[i].lz = 0;
            IT[i].val = 0;
            IT[i].prev = 0;
        }
    } 
    void Set(int id , int sz , int p) {
        IT[id].prev = IT[p].prev;
        IT[id].lz += IT[p].lz; 
        IT[id].val += IT[p].lz*sz;
        return;
    }
    void down(int id , int l , int r) {
        if (!IT[id].lz) return;
        int mid = (l + r) >> 1;
        Set(id << 1 , mid - l + 1 , id);
        Set(id << 1 | 1 , r - mid , id);
        IT[id].lz = 0; 
        return;
    }
    void update(int id , int l , int r , int L , int R , int x) {
        if (r < L || l > R) return;
        if (L <= l && r <= R) {
            if (IT[id].prev != -1) {
                IT[id].lz += 1LL*abs(IT[id].prev - x);
                IT[id].val += 1LL*abs(IT[id].prev - x)*(r - l + 1);
                //cerr << l << " " << r << " " << L << " " << R << " " << id << '\n';
                IT[id].prev = x;
                return;
            }
        }
        down(id , l , r);
        int mid = (l + r) >> 1;
        update(id << 1 , l , mid , L , R , x);
        update(id << 1 | 1 , mid + 1 , r , L , R , x);
        IT[id].val = IT[id << 1].val + IT[id << 1 | 1].val;
        if (IT[id << 1].prev == IT[id << 1 | 1].prev) IT[id].prev = IT[id << 1].prev; 
        else IT[id].prev = -1;

        return;
    }
    int query(int id , int l , int r , int L , int R) {
        if (r < L || l > R) return 0; 
        if (L <= l && r <= R) {
            return IT[id].val;
        }
        down(id , l , r); 
        int mid = (l + r) >> 1;
        return (query(id << 1 , l , mid , L , R) + query(id << 1 | 1 , mid + 1 , r , L , R));
    }
};

void solve() {
    int n , m; cin >> n >> m;
    Segtree st(n + 7);
    for (int i = 1 ; i <= n ; i ++) st.update(1 , 1 , n , i , i , i);
    while (m--) {
        int ask; cin >> ask;
        if (ask == 1) {
            int l , r , x; cin >> l >> r >> x;
            st.update(1 , 1 , n , l , r , x); 
        }
        else {
            int l , r; cin >> l >> r;
            cout << st.query(1 , 1 , n , l , r) - 1LL*r*(r + 1)/2 + 1LL*l*(l - 1)/2 << '\n';
        }
    }

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}