#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second

const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct bit2d {
    int n;
    vector<int> index[MAX_N];
    vector<int> value[MAX_N];
    
    void init(int len) {
        n = len;
        for (int i = 1 ; i <= n ; i++) {
            index[i].clear();
            value[i].clear();
        }
    }

    void update(int x , int y , int val , int type) {
        if (type == 0) {
            //cerr << x << " " << y << " " << n << '\n';
            for ( ; x <= n ; x += x & (-x)) {
                index[x].push_back(y);
            }
        }
        else {
            for ( ; x <= n ; x += x & (-x)) {
                for (int _y = lower_bound(index[x].begin() , index[x].end() , y) - index[x].begin() + 1 ; _y <= index[x].size() ; _y += _y & (-_y)) {
                    value[x][_y] += val;
                }
            }
        }
    }
    int get(int x , int y , int type) {
        int res = 0;
        x = min(x , n);
        if (type == 0) {
            for ( ; x > 0 ; x -= x & (-x)) {
                index[x].push_back(y);
            }
            return 0;
        }
        else {
            for ( ; x > 0 ; x -= x & (-x)) {
                for (int _y = lower_bound(index[x].begin() , index[x].end() , y) - index[x].begin() + 1 ; _y > 0 ; _y -= _y & (-_y)) {
                    //cout << x << " " << _y  << '\n';
                    res = res + value[x][_y];
                }
            }
            return res;
        }
        return 0;
    }
    void optimize() {
        //index[1].push_back(0);
        for (int i = 1 ; i <= n ; i ++) {
            
            sort(index[i].begin() , index[i].end());
            
            index[i].push_back(inf);
            vector<int> aa;
            
            for (int j = 0 ; j < (index[i].size() - 1) ;j ++) {
                if (index[i][j] != index[i][j + 1]) {
                    aa.push_back(index[i][j]);
                }
            }

            index[i].assign(aa.begin() , aa.end());
            index[i].push_back(inf);
            value[i].resize(index[i].size() + 3 , 0);
        }
    }
};
int f[MAX_N];
bool check[MAX_N];
int cnt[MAX_N];
bit2d BIT;
vector<ii> adj[MAX_N];
long long ans = 0;
int n , li , wi; 
int maxh = 0;

void DFS(int u , int father) {
    f[u] = 1;
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

void DFS1(int u , int father , int d = 0) {
    maxh = max(maxh , d); 
    for (auto edge : adj[u]) {
        int v , w; 
        tie(v , w) = edge;
        if (v != father && !check[v]) {
            DFS1(v , u , d + 1);
        }
    }
}

int find_centroid(int u , int father , int root) {
    for (auto edge : adj[u]) {
        int v , w; 
        tie(v , w) = edge;
        if (!check[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void calc(int u , int father , int length , int weight , bool status , bool type) {
    if (length > li || weight > wi) return;
    if (!status) {
        //cerr << length << " " << weight << " " << type << '\n';
        ans += BIT.get(li - length + 1 , wi - weight , type);
    }
    else {
        BIT.update(length + 1, weight, 1 , type);
    }
    for (auto edge : adj[u]) {
        int v , w; 
        tie(v , w) = edge;
        if (v != father && !check[v]) {
            calc(v , u , length + 1 , weight + w , status , type);
        }
    }
}

void centroid(int u , int father) {
    maxh = 0; 
    DFS(u , u); 
    u = find_centroid(u , u , u); 
    DFS1(u , u); 
    maxh++;
    BIT.init(maxh + 5);
    BIT.update(1 , 0 , 1 , 0);
    check[u] = 1;
    for (int status = 0 ; status < 2 ; status ++) {
        for (auto edge : adj[u]) {
            int v , w; tie(v , w) = edge;
            if (v != father && !check[v]) {
                calc(v , v , 1 , w , 0 , status);
                calc(v , v , 1 , w , 1 , status);
            }
        }   
        if (status == 0) {
            BIT.optimize();
            BIT.update(1 , 0 , 1 , 1);
        }
        // else {
        //     ans += BIT.get(li + 1, wi, status);
        // }
    }
    for (auto edge : adj[u]) {
        if (!check[edge.fi]) centroid(edge.fi , u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> li >> wi;
    for (int i = 2 ; i <= n ; i++) {
        int v , w; cin >> v >> w;
        adj[i].push_back(ii(v , w));
        adj[v].push_back(ii(i , w));
    }   
    centroid(1 , -1);
    cout << ans;
    return 0; 
}