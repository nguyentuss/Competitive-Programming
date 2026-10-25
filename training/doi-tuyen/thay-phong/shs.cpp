#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 207;
const int MOD = 1e9 + 7;

int root[MAX_N];
int sz[MAX_N];
int a[MAX_N];

vector<int> adj[MAX_N];

void init() {
    for (int i = 1 ; i < 201 ; i++) {
        root[i] = i;
        sz[i] = 1;
        adj[i].clear();
    }
}

int find_root(int u) {
    return (u == root[u]) ? u : root[u] = find_root(root[u]);
}

bool merge(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];
        return 1;
    }
    return 0;
}

char s[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int tt = 1 ; tt <= t ; tt++) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> s[i];
        }
        init();
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            merge(i , a[i]);
            adj[i].push_back(a[i]);
        }
        int ans = 1;
        set<int> st;
        for (int i = 1 ; i <= n ;i ++) {
            int x = find_root(i);
            st.insert(x);
        }
        for (auto x : st) {
            int tm = x;
            deque<char> a1 , a2 , origin ;
            deque<int> a3;
            int root = x;
            a1.push_back(s[tm]);
            origin.push_back(s[tm]);
            tm = adj[tm][0];
            a1.push_back(s[tm]);
            origin.push_back(s[tm]);
            while (tm != root) {
                a1.push_back(s[adj[tm][0]]);
                origin.push_back(s[adj[tm][0]]);
                a3.push_back(adj[tm][0]);
                tm = adj[tm][0];
            }
            a1.pop_back();
            origin.pop_back();
            for (auto tx : a1) 
                a1.push_back(tx);
            a2 = origin;
            int cnt = 0;
            int len = origin.size();
            for (int i = len ; i < 2*len ;i ++) {
                ++cnt;
                a2.pop_front();
                a2.push_back(a1[i]);
                if (a2 == origin) {
                    break;
                }
            }
            ans = (ans*cnt)/(__gcd(ans , cnt));
        }
        cout << ans << '\n';
    }
    return 0;
}