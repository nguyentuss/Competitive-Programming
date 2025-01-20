// #pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
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
const int lim = 30;

struct Trie {
    struct Node {
        Node *child[2];
        int sum;
        Node() {
            sum = 0;
            child[0] = child[1] = NULL;
        }
    };
    Node *root = new Node();


    void add(int x) {
        Node *p = root;
        for (int i = lim ; i >= 0 ; i--) {
            int c = (x >> i) & 1;
            if (p->child[c] == NULL) {
                p->child[c] = new Node();
            }
            p = p->child[c];
            p->sum++;
        }
    }

    ll get(int a , int b) {
        Node *p = root;
        ll ans = 0;
        for (int i = lim ; i >= 0 ; i--) {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            if (x) {
                if (x == y) {
                    if (p->child[0] != NULL) p = p->child[0];
                    else return ans;
                }
                else {
                    if (p->child[1] != NULL) p = p->child[1];
                    else return ans;
                }
            }
            else {
                if (x == y) {
                    if (p->child[1] != NULL)
                        ans += p->child[1]->sum;
                    if (p->child[0] != NULL) p = p->child[0];
                    else return ans;
                }
                else {
                    if (p->child[0] != NULL) 
                        ans += p->child[0]->sum;
                    if (p->child[1] != NULL) p = p->child[1];
                    else return ans;
                }
            }
        }
        ans += p->sum;
        return ans;
    }

};

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    Trie tr;
    ll ans = 0;
    tr.add(0);
    int S = 0;
    for (int i = 0 ; i < n ; i++) {
        S ^= a[i];
        tr.add(S);
        ans += tr.get(k , S);
    }
    cout << ans;
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
