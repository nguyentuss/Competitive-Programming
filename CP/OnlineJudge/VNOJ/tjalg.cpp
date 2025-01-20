#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define oo (int) (1e9 + 7)

vector<int> adj[MAX_N];
int counted = 0 , cnt = 0;
int num[MAX_N] , low[MAX_N];
stack<int> s;
int n , m;

void DFS(int u) {
      num[u] = low[u] = ++cnt;
      s.push(u);
      for (auto v : adj[u]) {
            if (num[v]) {
                  low[u] = min(low[u] , num[v]);
            }
            else {
                  DFS(v);
                  low[u] = min(low[u] , low[v]);
            }
      }
      if (num[u] == low[u]) {
            int v;
            counted++;
            while (u != v) {
                  v = s.top(); s.pop();
                  num[v] = low[v] = oo;
            }
      }
}

int main() {
      ios_base::sync_with_stdio(0); cin.tie(NULL);
      cout.tie(NULL);
      cin >> n >> m;
      for (int i = 1 ; i <= m ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
      }
      for (int i = 1 ; i <= n ; i++) {
            if (!num[i]) DFS(i);
      }
      cout << counted;
      return 0;
}
