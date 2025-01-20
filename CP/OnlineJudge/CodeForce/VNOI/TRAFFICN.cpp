        #include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("trafficn.inp","r",stdin);
#define fo freopen("trafficn.out","w",stdout);
#define ii pair<int , int>

int n , m , k , s , t , u , q , v; 
vector <ii> adj[10007];
vector <ii> revadj[10007];
vector <long long> d(10007) , diststart(10007) , distend(10007);
const long long oo = 1000111000000;
int counted = 0;

void dijkstra(vector <ii> a[10007] , int start , vector <long long> d){
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
    if (counted == 0) for (int i = 1 ; i <= n ; i ++) diststart[i] = d[i];
    else for (int i = 1 ; i <= n; i++) distend[i] = d[i];
   // return d;
}

int main(){
    boost;
    //fi;fo;
    int test; cin >> test;

    while(test --) {
        
        counted = 0;
        cin >> n >> m >> k >> s >> t;
        for (int i = 0 ; i <= n ; i++){
            adj[i].clear();
            revadj[i].clear();
        }
        for (int i = 0 ; i < m ; i ++) {
            cin >> u >> v >> q;
            adj[u].push_back(ii(q,v));
            revadj[v].push_back(ii(q,u));
        }
        dijkstra(adj , s ,  diststart);
        counted ++; 
        dijkstra(revadj , t , distend);

        cout << distend[4];
        long long ans = diststart[t];
        for (int i = 0 ; i < k ; i++) {
            cin >> u >> v >> q;
            ans = min(ans , min(diststart[v] + q + distend[u] , diststart[u] + q + distend[v]));
        }
        if (ans == oo) cout << -1 << endl;
        else cout << ans << endl;

    }

    return 0;
}