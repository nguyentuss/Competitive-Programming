#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
//#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 4 * 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int val , lazy;
};

int n;
vector<int> adj[MAX_N];
int ti[MAX_N] , to[MAX_N];
seg down[4 * MAX_N];
int up[4 * MAX_N];
int timed = 0;
vector<int> a; 

void lz(int id) {
    int x = down[id].lazy;
    down[2 * id].val = max(down[2 * id].val , x);
    down[2 * id + 1].val = max(down[2 * id + 1].val , x);
    down[2 * id].lazy = max(down[2 * id].lazy , x);
    down[2 * id + 1].lazy = max(down[2 * id + 1].lazy , x);
    down[id].lazy = 0;
    return;
}

void update(int id , int l , int r , int L , int R , int type , int val) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        if (type == 1) {
            down[id].val = max(down[id].val , val);
            down[id].lazy = max(down[id].lazy , val);
        }
        if (type == 2) 
            up[id] = max(up[id] , val);
        return; 
    }
    if (type == 1) lz(id);
    int mid = (L + R)/2;
    update(2 * id , l , r , L , mid , type , val);
    update(2 * id + 1 ,l , r , mid + 1 , R , type , val);
    down[id].val = max(down[2 * id].val , down[2 * id + 1].val);    
    up[id] = max(up[2 * id] , up[2 * id + 1]);
    return;
}

int get(int id , int l , int r , int L , int R , int type) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        if (type == 1) {
            return down[id].val;
        }
        if (type == 2) {
            return up[id];
        }
    }
    if (type == 1) lz(id);
    int mid = (L + R)/2;
    return max(get(2 * id , l , r , L , mid , type) , get(2 * id + 1 , l , r , mid + 1 , R , type));
}

int l[MAX_N] , r[MAX_N];

void DFS(int u , int father) {
    ti[u] = ++ timed;
    a.push_back(u);
    for (auto v : adj[u]) {
        if (v != father) {
            DFS(v , u);
        }
    }
    to[u] = ++ timed;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    DFS(1 , -1);
    int m; cin >> m;
    for (int i = 1 ; i <= m ; i++) {
        int ask , v; cin >> ask >> v;
        if (ask == 1) {
            update(1 , ti[v] , to[v] , 1 , 2*n , 1 , i); 
        }
        else if (ask == 2) {
            update(1 , ti[v] , ti[v] , 1 , 2*n , 2 , i);
        }
        else {
            int tm1 = get(1 , ti[v] , ti[v] , 1 , 2*n , 1);
            int tm2 = get(1 , ti[v] , to[v] , 1 , 2*n , 2);
            if (tm1 > tm2) {
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
    }
    return 0;
}