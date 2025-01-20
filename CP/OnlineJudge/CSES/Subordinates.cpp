#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 2e5 + 7;
const int inf = 1e18;

vector<int> adj[N];
int f[N];

void DFS(int u , int father) {
    for (int v : adj[u]) {
        if (v != father) {
            DFS(v , u);
            f[u] += f[v] + 1;
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 2 ; i <= n ; i++) {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    DFS(1 , -1);
    for (int i = 1 ; i <= n ; i++) {
        cout << f[i] << " ";
    }
    return 0;
}