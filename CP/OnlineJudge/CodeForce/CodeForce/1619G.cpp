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
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int x , y , ti , id;
};

bool cmp(seg &a , seg &b) {
    return a.ti < b.ti;
}

bool cmpx(seg &a , seg &b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool cmpy(seg &a , seg &b) {
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

vector<int> adj[MAX_N];
int mini[MAX_N];
int root[MAX_N];
int sz[MAX_N];
seg a[MAX_N];
int n , k;

int find_root(int u) {
    if (u == root[u]) return u;
    else return root[u] = find_root(root[u]);
}

void union_set(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];
    }
    return;
}

void init(){
    for (int i = 1 ; i <= n ; i++) {
        root[i] = i;
        sz[i] = 1;
        mini[i] = inf;
        adj[i].clear();
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        init();
        for (int i = 1 ; i <= n ; i++) {
            int x , y , ti; cin >> a[i].x >> a[i].y >> a[i].ti;
            a[i].id = i;
        }
        sort(a + 1 , a + 1 + n , cmpx);
        for (int i = 1 ; i <= n ;i ++) {
        }
        for (int i = 2 ; i <= n ; i++) {
            if (a[i].x == a[i - 1].x && (a[i].y - a[i - 1].y) <= k) {
                union_set(a[i - 1].id , a[i].id);
            }
        }
        sort(a + 1 , a + 1 + n , cmpy);
        for (int i = 2 ; i <= n ; i++) {
            if (a[i].y == a[i - 1].y && (a[i].x - a[i - 1].x) <= k) {
                union_set(a[i - 1].id , a[i].id);   
            }
        }
        sort(a + 1 , a + 1 + n , cmp);  
        //cout << a[i].x << " " << a[i].y << '\n';
        for (int i = 1 ; i <= n ;i ++) {
            int u = find_root(a[i].id);
            adj[u].push_back(a[i].id);
            mini[u] = min(mini[u] , a[i].ti);
        }
        vector<int> trace;
        for (int i = 1 ; i <= n ;i ++) {
            if (adj[i].size()) {
                //cerr << "DEBUG";
                trace.push_back(mini[i]);
            }
        }
        sort(trace.begin() , trace.end());
        deque<int> dq;
        for (auto v : trace) {
            //cout << v << " ";
            dq.push_back(v);
        }
        int cnt = -1;
        while (!dq.empty()) {
            if (!dq.empty()) dq.pop_back();
            cnt++;
            while (!dq.empty() && cnt == dq.front()) dq.pop_front();
        }
        cout << cnt << '\n';
    }
    return 0;
}