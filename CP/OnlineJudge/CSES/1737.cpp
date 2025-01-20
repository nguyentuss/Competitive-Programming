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

int b[N];

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
        cur -> sum = b[l]; 
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
        cur -> sum = val;
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
    return query(cur -> l , l , mid , L , R) + query(cur -> r , mid + 1 , r , L , R);
}

node *tree[N];

void solve() {
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    tree[0] = new node();
    build(tree[0] , 1 , n);
    //cerr << "YES";
    vector<int> call(q + 1);
    call[1] = 0;
    int Time = 0;
    int num = 1;                                     
    while (q--) {
        int ask; cin >> ask;
        Time++;
        //cerr << Time << '\n';
        if (ask == 1) {
            int k , a , x; cin >> k >> a >> x;
            int prev = call[k];
            tree[Time] = new node();
            update(tree[Time] , tree[prev] , a , 1 , n , x);
            call[k] = Time;
        }
        if (ask == 2) {
            int k , a , b; cin >> k >> a >> b;
            int prev = call[k];
            cout << query(tree[prev] , 1 , n , a , b) << '\n';
        }
        if (ask == 3) {
            int k; cin >> k; 
            num++; 
            tree[Time] = tree[call[k]];
            call[num] = Time;
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