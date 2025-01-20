#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[2309];
int n, m , e , t , p, q, w;

int d[2309];

void dijkstra(int start) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[start] = 0;
    pq.push(ii(0, start));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < (int) a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> e >> t >> m;
    for (int i = 1 ; i <= m ; i++){
        cin >> p >> q >> w;
        //a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
   
    int ans = 0;
    dijkstra(e);
    for (int i = 1 ; i <= n ; i++) {
        if (d[i] <= t && d[i] != oo) ans ++;
    }
    cout << ans;

    return 0;
}