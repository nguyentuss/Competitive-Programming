#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 5e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int u , v , w; 
};
struct dd {
    int u , v;
};
int comp;
int n , m;
vector<seg> arr;
int root[MAX_N];
int sz[MAX_N];
int k[MAX_N];

void init() {
    for (int i = 1 ; i < MAX_N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
    return;
}
bool cmp(seg &a , seg &b) {
    return a.w < b.w;
}
stack<dd> s;
int find_root(int u) {
    return (root[u] == u) ? u : find_root(root[u]);
}
bool merge(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        comp--;
        s.push({u , v});
        root[v] = u;
        sz[u] += sz[v];
        return 1;
    }
    return 0;
}
void rollback(int cnt) {
    if (s.empty()) return;
    dd x;
    while (cnt--) {
        x = s.top();
        s.pop();
        comp++;
        root[x.v] = x.v;
        sz[x.u] -= sz[x.v];
    }
    return;
}
void ch(int &a , int &b) {
    if (a > b) swap(a , b);
    return;
}

vector<seg> b[MAX_N];
int c[MAX_N];
int d[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;  
    init();
    comp = n;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        arr.push_back({u , v , w});
    }
    int q; cin >> q; 
    for (int i = 1 ; i <= q ; i++) {
        cin >> k[i];
        for (int j = 1 ; j <= k[i] ; j++) {
            int x; cin >> x;
            b[arr[x - 1].w].push_back({arr[x - 1].u , arr[x - 1].v , i});
        }
    }
    for (int i = 1 ; i < MAX_N; i++) 
        b[i].push_back({0 , 0 , 0});
    sort(arr.begin() , arr.end() , cmp);
    vector<seg> edge;
    set<int , greater<int>> st;
    for (auto x : arr) {
        if (merge(x.u , x.v)) {
            edge.push_back(x);
            st.insert(x.w);
            c[x.w]++;
        }
    }
    vector<int> weight(st.begin() , st.end());
    reverse(edge.begin() , edge.end());
    map<ii , int> pos;
    int cnt = 0;
    vector<seg> adj;
    for (int x : weight) {
        rollback(c[x]);
        //cerr << s.size();
        int len = b[x].size() - 1; 
        int dem = 0 , cc = 0;
        for (int i = 0 ; i < len ; i++) {
            if (b[x][i].w != b[x][i + 1].w) {
                cc += merge(b[x][i].u , b[x][i].v);
                dem++;
                //cerr << cc << " " << s.size() << '\n';
                if (cc == dem) {
                    //cerr << b[x][i].w << " " << x << '\n';
                    d[b[x][i].w] += cc;
                }
                rollback(cc);
                cc = 0;
                dem = 0;
            }
            else {
                //cout << cc << " " << s.size() << '\n';
                cc += merge(b[x][i].u , b[x][i].v);
                dem++;
            }
        }
    }
    //cerr << "DEBUG";
    vector<bool> total(q + 1);
    for (int i = 1 ; i <= q ; i++) {
        if (k[i] == d[i]) {
            total[i] = 1;
        }
    }
    for (int i = 1 ; i <= q ; i++) {
        if (total[i] == 0) {
            printf("NO\n");
        }
        else printf("YES\n");
    }
    return 0;
}

// các truy vấn
// add hết các cạnh MST
// xóa từng thằng theo giảm dần
// r add từng theo trùng với trọng số đó
// r xóa