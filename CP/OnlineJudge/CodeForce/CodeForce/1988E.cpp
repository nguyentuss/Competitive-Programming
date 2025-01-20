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
const int N = 5e5 + 7;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct node {
  node *l, *r;
  int key, prior , sum = 0 , len = 0;
  node() {
    l = r = nullptr; 
    key = -1; 
    sum = 0;
    len = 0;
    prior = rnd();
  }

  node(int id) {
    l = r = nullptr;
    key = id;
    sum = 0;
    len = 0;
    prior = rnd();
  }
};

void set_child(node *x , int dir , node *y) {
    assert(x); 
    if (dir == 0) x->l = y; 
    else x -> r = y;
}

int get_sum(node *x) {
    if (!x) return; 
    return (x -> sum);
}

int get_len(node *x) {
    if (!x) return; 
    return (x -> len);
}

void update(node *u) {
    if (!u) return; 
    u -> len = 1; 
    u -> sum = u -> val;
    update(u->l);
    update(u->r);
    u -> len = u -> len + get_len(u -> l) + get(u -> r);
    u -> sum = u -> sum * (get_len(u -> l) + 1) * (get_len(u -> r) + 1);
      
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);  
    for (int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<node> c(n + 1);
    auto cartesian_tree = [&]() -> int {
        int tot = 0;
        vector<int> vis(n + 1) , st(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = tot;
            c[i] = node(a[i]);
            while (k > 0 && a[st[k - 1]] > a[i]) k--; //use > for min heap
            if (k) set_child(&c[st[k - 1]] , 1 , &c[i]); 
            if (k < tot) set_child(&c[i] , 0 , &c[st[k]]);;
            st[k++] = i;    
            tot = k;
        }
        int mn = *min_element(a.begin() + 1 , a.end());
        assert(mn == a[st[0]]);
        return st[0];
    };
    int root = cartesian_tree();
    update(&c[root]);
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