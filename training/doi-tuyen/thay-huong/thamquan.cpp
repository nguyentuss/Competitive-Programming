#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int oo = -1000111000;
typedef pair<int, int> ii;

vector<ii> a[100007];
int n, m;

int d[100007];

void dijkstra() {
    priority_queue<ii> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = -oo;
    pq.push(ii(-oo, 1));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < (int) a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] < min(du,uv)) {
                d[v] = min(du,uv);
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("thamquan.inp","r",stdin);
    freopen("thamquan.out","w",stdout);
    int p, q, m, w , ask;
    cin >> n >> m >> ask;
    for (int i = 1 ; i <= m ; i++){
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w,p));
    }
   
    dijkstra();

    int asked;
    for (int i = 0 ; i < ask ; i++) {
        cin >> asked;
        cout << d[asked] << endl; 
    }
    
    return 0;
}