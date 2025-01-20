#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>

const int N = 5e3 + 7;
const int inf = 1e18;

/*BELLMAN FORD(O(|V|.|E|))*/
// also find negative cycles;

vector<ii> adj[N];
vector<int> P(N);
int pre[N];
int ed;

bool bellmanFord(int n) {
    vector<int> d(n , inf);
    vector<int> len(n , 0);
    vector<int> in_queue(n); 
    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (!len[i]) {
            d[i] = 0; 
            in_queue[i] = true;
            q.push(i);
        }
        //cerr << i << " ";
        while (!q.empty()) {
            int u = q.front();
            in_queue[u] = false;
            q.pop();
            for (auto [v , uv] : adj[u]) {
                if (d[v] > (d[u] + uv)) {
                    len[v] = len[u] + 1; 
                    pre[v] = u;
                    if (len[v] == n) {
                        ed = v;
                        return true;
                    }
                    d[v] = d[u] + uv;
                    if (!in_queue[v]) {
                        in_queue[v] = true;
                        q.push(v);
                    }
                }
            }
        }   
    }
    return false;
}

void trace(int n) {
    vector<int> in_stack(n);
    stack<int> s;
    int v = ed;
    while (!in_stack[v]) {
        in_stack[v] = true; 
        s.push(v);
        v = pre[v];
    }
    vector<int> cycle{v};
    while (s.top() != v) {
        cycle.push_back(s.top());
        s.pop();
    }
    cycle.push_back(v); 
    for (auto x : cycle) cout << x + 1 << " ";
}

void solve() {  
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back(ii(v , c));
    }
    int ans = bellmanFord(n);
    if (!ans) cout << "NO";
    else {
        cout << "YES\n";
        trace(n);
    }
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
