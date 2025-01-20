#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <utility>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[2309];
int n, m;

int d[2309];

void dijkstra(int start) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i <= 500; i++)
        d[i] = oo;
    d[start] = 0;
    pq.push(ii(0, start));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        for (int i = 0; i < (int) a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                //cout << d[v] << endl;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("TRVCOST.inp","r",stdin);
    int p, q, m, w;
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    
    /*for (int i = 1 ; i <= m ; i++)
        for (auto it : a[i])
            cout << it.first << " " << it.second << endl;
    */
    int start; cin >> start;
    dijkstra(start);
    cin >> n;
    int end;
    for (int i = 0 ; i < n ; i++) {
        cin >> end;
        if (d[end] != oo) cout << d[end] << endl;
        else cout << "NO PATH" << endl;
    }

    return 0;
}