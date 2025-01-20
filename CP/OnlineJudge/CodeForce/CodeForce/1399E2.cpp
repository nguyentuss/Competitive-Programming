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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct edge {
    int v , w , s;
};

struct seg {
    int u , v , w , s;
};

vector<edge> adj[MAX_N];
vector<seg> edges;
vector<int> leaf;
int k[MAX_N] , f[MAX_N];
int n , S;

void init() {
    edges.clear();
    leaf.clear();
    for (int i = 1 ; i <= n ; i++) {
        k[i] = 0;
        f[i] = 0;
        adj[i].clear();
    }
}

void DFS(int u , int father) {
    if (adj[u].size() == 1) k[u] = 1 , leaf.push_back(u);   
    for (auto x : adj[u]) {
        int v = x.v , w = x.w;
        if (v != father) {
            edges.push_back({u , v , w , x.s});
            f[v] = f[u] + x.w;
            DFS(v , u);
            k[u] += k[v];
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int dem = 0;
    while (t--) {
        cin >> n >> S;
        dem++;
        //if (dem == 9) cerr << n << " " << S << '\n';
        init();
        for (int i = 1 ; i < n ; i++) {
            int u , v , w , s; cin >> u >> v >> w >> s;
            adj[u].push_back({v , w , s});
            adj[v].push_back({u , w , s});
        }
        DFS(1 , -1);
        int val = 0;
        for (auto x : leaf) {
            val += f[x];
        }
        if (val <= S) {
            cout << 0 << '\n';
            continue;
        }
        
        priority_queue<int> pq1 , pq2;
        for (auto x : edges) {
            int u = x.u , v = x.v , w = x.w , s = x.s , K = k[v];
            int val = w*K;
            if (s == 1) {
                //cerr << v << " " << k[v]*w << '\n';
                while (w != 0) {
                    val = val - (w - w/2)*K;
                    pq1.push((w - w/2)*K);
                    w/=2;
                }
            }
            else {
                while (w != 0) {
                    val = val - (w - w/2)*K;
                    pq2.push((w - w/2)*K);
                    w/=2;
                }
            }
        }
        //cerr << "DEBUG";
        int ans = 0;
        bool found1 = false;
        bool found2 = false;
        int last1 = 0 , last2 = 0;
        int lastbonus = 0;
        int lastfound = 0;
        while (val > S) {
            found1 = found2 = false;
            int tmp1 = 0 , tmp2 = 0 , tmp3 = 0;
            lastfound = 0 , lastbonus = 0;
            if (!pq1.empty()) {
                found1 = true;
                tmp1 = pq1.top();
            }
            if (!pq2.empty()) {
                found2 = true;
                tmp2 = pq2.top();
            }
            if (found1) pq1.pop();
            if (!pq1.empty()) tmp3 = pq1.top();
            if (found1) lastfound = 1;
            last1 = tmp1 , last2 = tmp2;
            //cerr << tmp1 << " " << tmp2 << " " << tmp3 << '\n';
            if (found1 && (tmp1 + tmp3) >= tmp2) {
                lastbonus = 1;
                val -= tmp1;
                ans++;
            }
            else if (found2) {
                lastbonus = 2;
                if (found1) pq1.push(tmp1);
                pq2.pop();
                val -= tmp2;
                ans += 2;
            }
        }
        //cout << lastfound << " " << lastbonus << " ";
        if (lastbonus == 2 && lastfound && (val + last2 - last1) <= S) {
            ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}