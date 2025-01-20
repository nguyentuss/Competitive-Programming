//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9 + 7;
const int maxn = 1000;
const int maxm = 50000;

struct MCMF{
    int size , n;
    int st , en , maxflow , mincost;
    bool vis[maxn]; 
    int net[maxn] , pre[maxn] , cur[maxn] , dis[maxn];
    queue<int> Q;
    struct EDGE {
        int v, cap , cost , next; 
        EDGE(){}
        EDGE(int a , int b , int c , int d) {
            v = a , cap = b , cost = c, next = d;
        }
    }E[maxm << 1    ];
    void init(int _n) {
        n = _n , size = 0;
        memset(net , -1 , sizeof(net));
    }
    void addedge(int u , int v , int cap , int cost) {
        E[size] = EDGE(v , cap , cost , net[u]); net[u] = size++;
        E[size] = EDGE(u , 0 , -cost , net[v]); net[v] = size++;
    }
    bool model() {
        int v, min = inf; 
        for (int i = 0 ; i <= n ; i++) {
            if (!vis[i]) continue;
            for (int j = net[i]; (j != -1 && (v = E[j].v)) ; j = E[j].next) {
                if (E[j].cap) {
                    if (!vis[v] && (dis[v] - dis[i] + E[j].cost) < min) {
                        min = dis[v] - dis[i] + E[j].cost;  
                    }
                }
            }
        }
        if (min == inf) return false; 
        for (int i = 0 ; i <= n ; i++) {
            if (vis[i]) {
                cur[i] = net[i] , vis[i] = false, dis[i] += min;
            }
        }
        return true;
    }
    int aug(int u,int f){

        if (u == en) {
            mincost += dis[st] * f; 
            maxflow += f; 
            return f;
        }
        vis[u] = true;
        for (int j = cur[u] , v ; (j != -1 && (v = E[j].v)) ; j = E[j].next) {
            if (!E[j].cap) continue;
            if (vis[v] || (dis[v] + E[j].cost) != dis[u]) continue;
            int delta = aug(v , min(f , E[j].cap));
            if (delta) {
                E[j].cap -= delta;
                E[j ^ 1].cap += delta; 
                cur[u] = j;
                return delta;
            }
        }
        return 0;
    }
    void spfa() {
        int u , v;
        for (int i = 0 ; i <= n ; i++) {
            vis[i] = false, dis[i] = inf; 
        }
        dis[st] = 0; 
        Q.push(st); 
        vis[st] = true; 
        while (!Q.empty()) {
            u = Q.front(); Q.pop();
            vis[u] = false; 
            for (int i = net[u]; (i != -1 && (v = E[i].v)) ; i = E[i].next) {
                if (!E[i].cap || dis[v] <= (dis[u] + E[i].cost)) {
                    continue;
                }
                dis[v] = dis[u] + E[i].cost;
                if (!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        for (int i = 0 ; i <= n ; i++) {
            dis[i] = dis[en] - dis[i]; 
        }
    }
    int zkw(int s , int t , int need) {
        st = s, en = t; 
        spfa(); 
        mincost = maxflow = 0;
        for (int i = 0 ; i <= n ; i++) {
            vis[i] = false; cur[i] = net[i];
        }
        do {
            while (aug(st , inf)) 
                memset(vis , false , sizeof(vis));
        }while(model()); 
        // if (maxflow < need) {
        //     return -1;
        // }
        return mincost;
    }
}mcmf;

int cnt_test = 0;

void solve() {
    cnt_test++;
    cout << "Case " << cnt_test << ": ";
    int n , m; cin >> n >> m;
    vector<vector<char>> a(n + 1 , vector<char>(m + 1));
    int init_cost = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') init_cost++;
        }
    }
    int ans = inf;
    int sr = n + m + 1; 
    int des = sr + 1;
    for (int x = 0 ; x <= m ; x++) {
        if ((n * x)%m != 0) continue;
        //clog << "YES"
		mcmf.init(n + m + 3);
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                mcmf.addedge(i , j + n , 1 , a[i][j] == '1' ? -1 : 1);
            }
        }
        for (int i = 1 ; i <= n ; i++) 
            mcmf.addedge(sr , i , x , 0); 
        //cerr << "YES";
        for (int i = 1 ; i <= m ; i++) 
            mcmf.addedge(n + i , des , n*x/m , 0);
        
        int mn = mcmf.zkw(sr , des , -1);
        ans = min(ans , init_cost + mn);
    }
    cout << ans << '\n';  

}   

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    //freopen("test.inp" , "r" , stdin); 
    //freoepn("test.out" , "w" , stdout);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}