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

ii a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    int n; cin >> n;
    unordered_map<int , vector<int>> adj[2];
    //cerr << "DEBUG";
    for (int i = 0 ; i < n + 2 ;i ++) {
        cin >> a[i].fi >> a[i].se;
        adj[0][a[i].fi].push_back(i);
        adj[1][a[i].se].push_back(i);
    } 
    queue<ii> q;
    q.push(ii(0 , 0)); 
    q.push(ii(0 , 1)); 
    vector<int> d(n + 2 , inf);
    d[0] = 0;
    while (!q.empty()) {
        int u = q.front().fi;
        int status = q.front().se;
        q.pop(); 
        int coor = (status ? a[u].se : a[u].fi);
        for (auto v : adj[status][coor]) {
            if (d[v] == inf) {
                d[v] = d[u] + 1;
                q.push(ii(v , status ^ 1));
            }
        } 
    }
    cout << (d[1] == inf ? -1 : d[1] - 1);
    return 0;
}