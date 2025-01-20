#include <bits/stdc++.h>
 
using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
 
const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
 
stack<int> s;
vector<int> trace;
vector<int> adj[N];
bool isFound = false;
int vis[N];
 
void DFS(int u) {
    vis[u] = 1;
    s.push(u);
    for (auto v : adj[u]) {
        if (vis[v] == 1) {
            if (!isFound) {
                isFound = true;
                trace.push_back(v);
                while (s.size()) {
                    int x = s.top();
                    s.pop();
                    trace.push_back(x);
                    if (x == v) {
                        return;
                    }
                } 
            }
        }
        if (!vis[v]) DFS(v);
    }
    if (s.size()) s.pop();
    vis[u] = 2; 
}
 
main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v); 
    }    
    
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) {
            while (!s.empty()) s.pop();
            DFS(i);
        }
    }
    if (trace.size()) {
        cout << trace.size() << '\n';
        reverse(trace.begin() , trace.end());
        for (int x : trace) {
            cout << x << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
 
 
    return 0;
}