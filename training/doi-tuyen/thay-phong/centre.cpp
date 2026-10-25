#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

const int oo = 1e9;
typedef pair<int, int> ii;
#define MAX_N (int) (30007)

vector<ii> a[MAX_N];
int n, m;

int d[MAX_N];
int d1[MAX_N] , dn[MAX_N] , trace1[MAX_N] , tracen[MAX_N];
int trace[MAX_N];
bool cnt[MAX_N];
void dijkstra(int s , int change) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++){
        d[i] = oo;
        trace[i] = 0;
    }
    d[s] = 0;
    trace[s] = 1;
    pq.push(ii(0, s));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        for (int i = 0; i < (int) a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                trace[v] = trace[u];
                pq.push(ii(d[v], v));
            }
            else if (d[v] == du + uv) trace[v] += trace[u];
        }
    }
    if (change == 1) {
        for (int i = 1 ; i <= n ; i++) {
            d1[i] = d[i];
            trace1[i] = trace[i];
        }
    }
    else {
        for (int i = 1 ; i <= n ; i++) {
            dn[i] = d[i];
            tracen[i] = trace[i];
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
    dijkstra(1 , 1);
    dijkstra(n , 2);
    vector <int> v;
    for (int i = 2 ; i < n;i++) 
        if (d1[i] + dn[i] > d1[n] || trace1[i]*tracen[i] < trace1[n]) v.push_back(i);
    cout << v.size() << '\n';
    for (auto x : v) cout << x << '\n';
    
    return 0;
}