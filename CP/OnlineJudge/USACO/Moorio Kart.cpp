// http://www.usaco.org/index.php?page=viewproblem2&cpid=925
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 5e2 + 7;
const int VAL = 2e3 + 5e2 + 7;
const int MOD = 1e9 + 7;

int n , m , X , Y;
int a[N];
int vis[N];
ii f[VAL];
ii tmp[VAL];
int ck[N];

vector<ii> adj[N]; 
vector<int> ver;
vector<int> dist;

ii operator+(const ii &a , const ii &b) {
    return (ii((a.fi + b.fi)%MOD , (a.se + b.se)%MOD));
}

ii operator+=(ii &a , const ii &b) {
    return a = a + b;
}

void DFS(int u , int father) {
    vis[u] = 1;
    ver.push_back(u);
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (!vis[v]) {
            DFS(v , u);
        }
    }
}

void DFS_1(int u , int root , int father , int d = 0) {
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father) {
            if (v > root) {
                dist.push_back(d + w);
            }
            DFS_1(v , root , u , d + w);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("mooriokart.in","r",stdin);
    freopen("mooriokart.out","w",stdout);
    cin >> n >> m >> X >> Y;
    int k = n - m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w));   
    }
    //cerr << "DEBUG";
    f[min(k*X,Y)] = {k*X,1};
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            dist.clear();
            ver.clear();
            map<int , ii> mp;
            DFS(i , -1);
            // for (auto x : ver) {
            //     cerr << x << " ";
            // }
            // cerr << '\n';
            for (auto j : ver) {
                DFS_1(j , j , -1);
            }
            for (auto j : dist) {
                mp[min(Y , j)] += ii(j , 1);
            }
            // for (auto x : dist) {
            //     cerr << x << " ";
            // }
            //cerr << '\n';
            for (int j = 0 ; j <= Y ; j++) {
                tmp[j] = ii(0 , 0);
            }
            for (auto j : mp) {
                for (int we = 0 ; we <= Y ; we++) {
                    tmp[min(Y , j.fi + we)] += ii(((f[we].fi*j.se.se)%MOD + (j.se.fi*f[we].se)%MOD)%MOD , (f[we].se%MOD*j.se.se%MOD)%MOD);
                }
            }
            for (int j = 0 ; j <= Y ; j++) {
                f[j] = tmp[j];
            }
        }
    }
    int pow_2 = 1;
    // Chon. cac dinh? de noi' thành phần liên thông với nhau 
    for (int i = 1 ; i < k ; i++) (pow_2 *= 2)%=MOD;
    // Hoán vị
    int permutation = 1;
    for (int i = 1 ; i < k ; i++) (permutation *= i)%=MOD;
    cout << ((tmp[Y].fi%MOD*pow_2%MOD)%MOD*permutation%MOD)%MOD;
    return 0;
}