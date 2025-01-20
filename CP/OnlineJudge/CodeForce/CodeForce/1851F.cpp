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

int lim;

struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *root = new Node();

    void update(int x) {
        Node* p = root;
        for (int i = lim ; i >= 0 ; i--) {
            int c = (x >> i) & 1;
            if (p->child[c] == NULL) p->child[c] = new Node();
            p = p->child[c];
            p->cnt++;
            // cerr << x << ' ' << p->cnt << ' ' << c << '\n';
        }
    }
    tuple<int , int , int , int> get() {
        Node *p = root; 
        queue<tuple<Node*, Node*, int , int , int , int , int>> q; 
        q.push({p,p,0,0,0,0,lim});
        int ans = 0;
        tuple<int , int , int , int> trace;
        while (!q.empty()) {
            auto [u , v, a , b , c , sum , h] = q.front();
            q.pop();
            // cout << h << ' ' << u << ' ' << v << ' ' << a << ' ' << b << ' ' << c << ' ' << sum << '\n';
            if (h == -1) {
                if (ans <= sum) {
                    trace = {a,b,c,sum};
                    ans = sum;
                }
                continue;
            }
            int add = (1ll << h);
            if ((u->child[0] != NULL && u->child[0]->cnt > 1) || (u->child[1] != NULL && u->child[1]->cnt > 1)) {
                // cerr << p->child[0]->cnt << " " << p->child[1]->cnt << '\n';
                if (u->child[0] != NULL && u->child[0]->cnt > 1) {
                    q.push({u->child[0],v->child[0], a , b , c + add , sum + add , h-1});
                }
                if ((u->child[1] != NULL && u->child[1]->cnt > 1)) {
                    q.push({u->child[1],v->child[1],a+add,b+add,c,sum+add,h-1});
                }
            }
            else {   
                if (u == v) {
                    if (u->child[0] != NULL && u->child[1] != NULL)
                        q.push({u->child[0],u->child[1],a,b + add,c,sum,h-1});
                }
                else {
                    for (int i = 0 ; i < 2 ; i++) {
                        if (u->child[i] != NULL && v->child[i] != NULL) {
                            q.push({u->child[i],v->child[i],a + (i ? add : 0),b + (i ? add : 0), c + (!i ? add : 0) ,sum + add,h-1});
                        }
                        if (u->child[i] != NULL && v->child[i^1] != NULL) {
                            q.push({u->child[i],v->child[i^1],a + (i ? add : 0),b + ((i^1) ? add : 0), c, sum , h-1});
                        }
                    }
                }
            }
        }
        return trace;
    }
};

void solve() {
    int n , k; cin >> n >> k;
    lim = k - 1;
    vector<int> a(n);
    map<int , vector<int>> mp;
    Trie tr;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
        tr.update(a[i]);
    }
    auto [i , j , x , sum] = tr.get();
    int r1 , r2;
    if (i == j) {
        r1 = mp[i][0];
        r2 = mp[i][1];
    }
    else {
        r1 = mp[i][0];
        r2 = mp[j][0];
    }
    cout << r1+1 << ' ' << r2+1 << ' ' << x << '\n';
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
    return 0;
}
