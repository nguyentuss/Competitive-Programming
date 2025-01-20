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
    struct tedge{int x,y,cap,w,next;}adj[maxm];int ms,fch[maxn];
    int vis[maxn],d[maxn],ans,cost,S,T,n;
    void init(int n){
        this->n=n;ms=0;ans=cost=0;
        memset(fch,-1,sizeof(fch));
        return;
    }
    inline void addedge(int u,int v,int cap,int w){
        adj[ms]=(tedge){u,v,cap,w,fch[u]};fch[u]=ms++;
        adj[ms]=(tedge){v,u,0,-w,fch[v]};fch[v]=ms++;
        return;
    }
    inline int aug(int u,int f){
        if(u==T){ans+=cost*f;return f;}
        int tmp=f;vis[u]=1;
        for(int i=fch[u];i!=-1;i=adj[i].next){
            int v=adj[i].y;
            if(adj[i].cap&&!adj[i].w&&!vis[v]){
                int a=aug(v,tmp<adj[i].cap?tmp:adj[i].cap);
                adj[i].cap-=a;
                adj[i^1].cap+=a;
                tmp-=a;
                if(!tmp) return f;
            }
        } return f-tmp;
    }
    inline bool spfa(){
        for(int i=1;i<=n;i++) d[i]=inf;
        deque<int>Q;Q.push_back(T);d[T]=0;
        while(!Q.empty()){
            int u=Q.front(),tmp;Q.pop_front();
            for(int i=fch[u];i!=-1;i=adj[i].next)
                if(adj[i^1].cap&&(tmp=d[u]-adj[i].w)<d[adj[i].y])
                    (d[adj[i].y]=tmp)<=d[Q.empty()?S:Q.front()]?Q.push_front(adj[i].y):Q.push_back(adj[i].y);
        }
        for(int u=1;u<=n;u++)
            for(int i=fch[u];i!=-1;i=adj[i].next)
                adj[i].w+=d[adj[i].y]-d[u];
        cost+=d[S];return d[S]<inf;
    }
    int costflow(int S,int T){
        this->S=S;this->T=T;
        while(spfa())do memset(vis,false,sizeof(vis));while(aug(S,inf));
        return ans;
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
    if (n != m) {
        cout << min(n * m - init_cost , init_cost) << '\n';
        return;
    }
    int ans = inf;
    for (int x = 1 ; x <= m ; x++) {
        if ((n * x)%m != 0) continue;
		mcmf.init(n + m + 7);
        for (int i = 1 ; i <= n ; i++) 
            mcmf.addedge(1 , i + 1 , x , 0); 
        for (int i = 1 ; i <= m ; i++) 
            mcmf.addedge(1 + i + n , n + m + 2 , x , 0);
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                mcmf.addedge(i + 1 , j + n + 1 , 1 , a[i][j] == '1' ? -1 : 1);
            }
        }
        //mcmf.setpi(0);
        int mn = mcmf.costflow(1 , n + m + 2);
	    //cerr << "YES";
        ans = min(ans , init_cost + mn);
        //cerr << mn << '\n';
    }
    cout << ans << '\n';  

}   

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    freopen("test.inp" , "r" , stdin); 
    freopen("test.out" , "w" , stdout);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}