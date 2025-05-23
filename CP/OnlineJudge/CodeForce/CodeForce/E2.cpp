#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define iii pair<int , ii>

const int N = 3e5 + 7;
const int inf = 2e9 + 7;

vector<int> adj[N];
int f[N], d[N], g[N] , h[N];
int sz[N];
int ans[N];
iii sv[N];
int maxi;
int n;
multiset<int> s;
// d[u] : tu u -> x (cay con u)

void DFS_1(int u , int father) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v != father) {
            h[v] = h[u] + 1;
            DFS_1(v , u);
            sz[u] += sz[v];
            d[u] = max(d[u] , d[v] + 1);
        }
    }
}

void DFS_2(int u , int father) {
    for (auto v : adj[u]) {
        if (v != father) {
            DFS_2(v , u); 
            if (d[u] == (d[v] + 1)) 
                g[u] += g[v];
        }
    }
}

ii check(int X , int u) {
    int tmp = g[1];
    int tl = 0;
    if (d[1] == h[u]) {
        tmp--;
        int tm;
        if (h[u] % 2 == 1) {
            tm = X;
            if (X % 2 == 1) tm --;
            tl = h[u] - (h[u]/2 - tm/2);
            if (tmp) return ii(-1 , -1);
            return ii(tl , 1);
        }
        else {
            if (X == 1) tl = h[u]/2;
            else {
                tm = X - 1;
                int height = h[u] - 1;
                if (X % 2 == 1) tm--;
                tl = h[u] - (height - tm/2);
            }
            if (tmp) return ii(-1 , -1);
            return ii(tl , 2);
        }
    }
    else { 
        tl = X + d[u];
        if (maxi == (h[u] + d[u])) tmp = tmp - g[u];
    }
    if (tmp) return ii(-1,-1); 
    else return ii(tl,0);
}

void DFS_3(int u , int father) {
    int x = 0;
    if (!s.empty()) x = *(s.rbegin()); 
    int minl = sv[u].second.first;
    x = max(x , sv[u].first);
    int status = sv[u].second.second;
    ans[minl] = min(ans[minl] , x);
    if (status == 1 && (minl + 1) <= n) {
        ans[minl+1] = ans[minl];
    }
    if (status == 2 && minl > 1 && (minl + 1) <= n) {
        ans[minl + 1] = ans[minl];
    }
    for (auto v : adj[u]) {
        if (v != father) {
            DFS_3(v , u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n ; i++) {
            adj[i].clear(); 
            f[i] = d[i] = g[i] = h[i] = ans[i] = sz[i] = 0;
        }
        for (int i = 1 ; i < n ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS_1(1 , -1);
        
        for (int i = 1 ; i <= n ; i++) {
            if (sz[i] == 1) g[i] = 1;
            ans[i] = d[1];
        }
        DFS_2(1 , -1);
        for (int i = 2 ; i <= n ; i++) {
            int l = 1 , r = h[i];
            int x = inf;
            int status = -1;
            int minl = inf;
            while (l <= r) {
                int mid = (l + r)/2;
                //cerr << l << " " << r << " " << mid << '\n';
                ii cc = check(mid , i);
                x = cc.first;
                status = cc.second;
                if (x != -1) {
                    minl = min(minl , mid);
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if (minl != inf && status != -1) {
                sv[i] = iii(x , ii(minl , status));
                cerr << minl << " " << x << " " << i << " " << h[i] << " " << status << '\n';
            }
        }
        for (auto v : adj[1]) s.insert(d[v] + 1);
        for (auto v : adj[1]) {
            s.erase(s.find(d[v] + 1));
            DFS_3(v , 1);
            s.insert(d[v] + 1);
        }
        for (int i = 1 ; i <= n ; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0; 
}