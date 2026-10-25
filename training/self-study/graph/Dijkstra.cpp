#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[2309];
int n, m;

int d[2309];

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++){
        d[i] = oo;
    }
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
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
    //freopen("input.inp","r",stdin);
    int p, q, m, w;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
   
    /*for (int i = 1 ; i <= m ; i++)
        for (auto it : a[i])
            cout << it.first << " " << it.second << endl;
    */

    dijkstra(); 
    return 0;
}