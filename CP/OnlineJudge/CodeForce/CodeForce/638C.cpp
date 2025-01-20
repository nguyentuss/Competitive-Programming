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
    const int inf = 1e8; 
    const int N = 2e5 + 7;

    map<pair<int , int> , int> mp;
    vector<set<int>> trace(N);
    vector<int> days[N];
    vector<int> adj[N];

    void DFS(int u , int father) {
        int cur = 0;
        for (int v : adj[u]) {
            if (v != father) {
                //while (trace[cur].find(u) != trace[cur].end()) cur++;
                while (true) {
                    if (trace[cur].find(u) == trace[cur].end() && trace[cur].find(v) == trace[cur].end()) {
                        trace[cur].insert(u);
                        trace[cur].insert(v); 
                        days[cur].push_back(mp[{u , v}]);
                        break;
                    }
                    cur++;
                }
                DFS(v , u);
            }
        }
    }


    void solve() {
        int n; cin >> n;
        for (int i = 1 ; i < n ; i++) {
            int u , v; cin >> u >> v;
            u--; v--; 
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[{u , v}] = i;
            mp[{v , u}] = i;
        }
        DFS(0 , -1); 
        int ans = 0;
        for (int i = 0 ; i < N ; i++) {
            if (trace[i].size()) ans++; 
        }    
        cout << ans << '\n';
        for (int i = 0 ; i < ans ; i++) {
            cout << days[i].size() << " ";
            for (int x : days[i]) {
                cout << x << " ";
            }
            cout << '\n';
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