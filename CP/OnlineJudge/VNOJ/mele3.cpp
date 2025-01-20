#include <bits/stdc++.h>
 
#pragma GCC targer("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
int n , m; 

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    vector<int> d(MAX_N , inf);
    d[1] = 0;
    pq.push(ii(0 , 1));
    while (!pq.empty()) {
        int u = pq.top().s;
        int du = pq.top().f;
        pq.pop(); 
        for (auto v : adj[u]) {
            int edge = abs(u - v)*5;
            int tm_u = min(u , v) , tm_v = max(u , v);
            int status = d[u]/edge;
            int last , jump , cur;
            last = d[u] % edge;
            jump = last / 5;
            if (status % 2 == 0) {
                cur = tm_u + jump;
                if (u > v) {
                    int uv = (tm_v - cur)*5;
                    if (d[v] > (d[u] + uv + edge)) {
                        d[v] = d[u] + uv + edge;
                        pq.push(ii(d[v] , v));
                    }
                }
                else {
                    int uv;
                    if (!jump) uv = 0;
                    else uv = (tm_v - cur + tm_v - tm_u)*5;
                    if (d[v] > (d[u] + uv + edge)) {
                        d[v] = d[u] + uv + edge;
                        pq.push(ii(d[v] , v));
                    }
                }
            }
            else {
                cur = tm_v - jump;
                if (u < v) {
                    int uv = (cur - tm_u)*5;
                    if (d[v] > (d[u] + uv + edge)) {
                        d[v] = d[u] + uv + edge;
            // 3 -> 4 -> 5 -> 6 -> 7 -> 6 -> 5 -> 4 -> 3
                        pq.push(ii(d[v] , v));
                    }
                }
                else {
                    int uv;
                    if (!jump) uv = 0;
                    else uv = (cur - tm_u + tm_v - tm_u)*5;
                    if (d[v] > (d[u] + uv + edge)) {
                        d[v] = d[u] + uv + edge;
                        pq.push(ii(d[v] , v));
                    }
                }
            }
        }
    }
    cout << d[n];
    return 0;
}
