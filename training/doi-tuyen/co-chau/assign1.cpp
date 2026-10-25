#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e2 + 7;
const int MOD = 1e9 + 7;

vector <int> adj[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("assign1.inp","r",stdin);
    //freopen("assign1.out","w",stdout);
    int n; cin >> n;
    vector<vector<int>> a , resi , aug;
    int s = 0 , t = n*2 + 1;
    a.assign(n + 1 , vector<int> (n + 1));
    resi.assign(t + 1 , vector<int> (t + 1 , 0));
    aug.assign(t + 1 , vector<int> (t + 1 , 0));
    vector<int> level;
    vector<int> counted;
    set<int> st;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            st.insert(a[i][j]);
        }
    }
    
    function<void()> BFS = [&] () {
        level.assign(t + 1 , 0);
        queue<int> q;
        q.push(s);
        level[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (!level[v] && (resi[u][v] || aug[u][v])) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    function<int(int , int)> DFS = [&] (int u , int minimum) {
        if (u == t) return minimum;
        int res = 0;
        for (auto v : adj[u]) {
            if (level[v] == level[u] + 1) {
                if (resi[u][v]) {
                    res = DFS(v , min(minimum , resi[u][v]));
                    if (res != 0) {
                        resi[u][v] -= res;
                        aug[v][u] += res;
                        return res;
                    }
                }
                if (aug[u][v]) {
                    res = DFS(v , min(minimum , aug[u][v]));
                    if (res != 0) {
                        aug[u][v] -= res;
                        resi[v][u] += res;
                        return res;
                    }
                }
            }
        }
        return res;
    };

    function<bool(int)> check = [&] (int mid) {
        resi.assign(t + 1 , vector<int> (t + 1 , 0));
        aug.assign(t + 1 , vector<int> (t + 1 , 0));
        counted.assign(t + 1 , 0);
        for (int i = 1 ; i <= n ; i++) {
            adj[i].clear();
        }
            for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= n ; j++) {
                if (a[i][j] <= mid) {
                    adj[i].push_back(j + n);
                    adj[j + n].push_back(i);
                    counted[j + n] ++;
                    resi[i][j + n] = 1;
                }
            }
        }
        for (int i = 1;  i <= n ; i++) {
            if (adj[i].size()) {
                adj[s].push_back(i);
                adj[i].push_back(s);
                resi[s][i] = 1;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            if (counted[i + n]) {
                adj[i + n].push_back(t);
                adj[t].push_back(i + n);
                resi[i + n][t] = 1;
            }
        }
        int flow = 0;
        while (true) {
            BFS();
            if (level[t] == 0) break;
            while (int x = DFS(s , INT_MAX)) {
                flow += x;
            }
        }
        return (flow == n);
    };
    vector<int> X(st.begin() , st.end());
    
    int l = 0 , r = X.size() - 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r)/2;
        if (check(X[mid])) {
            r = mid - 1;
            ans = X[mid];
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}