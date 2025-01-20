//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

/**
 * Author: Simon Lindholm
 * Date: 2019-12-28
 * License: CC0
 * Source: https://github.com/hoke-t/tamu-kactl/blob/master/content/data-structures/MoQueries.h
 * Description: Answer interval finding an approximate TSP through the queries,
 * and moving from one query to the next by adding/removing points at the ends.
 * Time: O(N \sqrt Q)
 * Status: stress-tested
 */

int a[N];
int distinct = 0;
int cnt[N];

void add(int idx, int end) {
    cnt[a[idx]] ++;
    if (cnt[a[idx]] == 1) {
        distinct ++;
    } 
} // add a[ind] (end = 0 or 1)
void del(int idx, int end) { 
void del(int idx, int end) { 
    if (!cnt[a[idx]]) return;
    cnt[a[idx]] --;
    if (!cnt[a[idx]]) {
        distinct--;
    }
} // remove a[ind]
int calc() {
    return distinct;
 } // compute current answer

int ds[N];

vi mo(vector<pii> Q) {
    int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
    vi s(sz(Q)), res = s;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
    iota(all(s), 0);
    sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
    for (int qi : s) {
        pii q = Q[qi];
        //cerr << q.first << " " << q.second << '\n';
        while (L > q.first) add(--L, 0);
        while (R < q.second) add(++R, 1);
        while (L < q.first) del(L++, 0);
        while (R > q.second) del(R--, 1);
        //cerr << distinct << '\n';
        res[qi] = calc();
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    set<int> s;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int idx = 0; 
    map<int , int> mp;
    for (int x : s) {
        mp[x] = idx++; 
    }
    for (int i = 1 ; i <= n ; i++) {
        a[i] = mp[a[i]] + 1;
        //cerr << a[i] << " ";
    }
    vector<pii> Q;
    while (q--) {
        int l, r; cin >> l >> r;
        Q.push_back({l , r});
    }
    vi ans = mo(Q);
    for (int x : ans) {
        cout << x << '\n';
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