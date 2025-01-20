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
const int inf = 1e9 + 7;
const int MAX_N = 1e4 + 7;
const int MOD = 1e9 + 7;

int f[2][MAX_N][MAX_N];
int num[MAX_N];
vector<ii> adj[MAX_N];
int n , k , x;

// Solution : Knapsack on tree
// f[status][u][num] là tổng chi phí đường đi ngắn nhất chọn được
// num thằng phân biệt (kể cả u) trong subtree u có root là x
// với status 0 là chưa đi hết
//     status 1 là đi hết cuối đường
// Nhận xét tham lam là cách đi ngắn nhất là đi qua các cạnh nối đỉnh 2 lần
// và chỉ 1 lần cho cuối đường
// Formula : + f[0][u][num + new_num] = max(f[0][u][num + new_num] , f[0][v][new_num] + f[0][u][num] + 2*c);
//           + f[1][u][num + new_num] = max(f[1][u][num + new_num] , f[1][v][new_num] + f[0][u][num] + 2*c)
//           + f[1][u][num + new_num] = max(f[1][u][num + new_num] , f[0][v][new_num] + f[1][u][num]                                                                                                            + c); 

void DFS(int u , int father) {
    num[u] = 1;
    f[0][u][1] = f[1][u][1] = 0;
    for (auto edge : adj[u]) {
        int v , w;
        tie(v , w) = edge;
        if (v != father) {
            DFS(v , u);
            for (int i = num[u] ; i >= 0 ; i --) {
                for (int j = num[v] ; j >= 1 ; j--) {
                    f[0][u][i + j] = min(f[0][u][i + j] , f[0][u][i] + f[0][v][j] + 2*w);
                    f[1][u][i + j] = min(f[1][u][i + j] , f[1][u][i] + f[0][v][j] + 2*w);
                    f[1][u][i + j] = min(f[1][u][i + j] , f[0][u][i] + f[1][v][j] + w);
                }
            }
            num[u] += num[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> x;
    for (int i = 1 ; i < n ; i++) {
        int u , v , c; cin >> u >> v >> c;
        adj[u].push_back(ii(v , c)); 
        adj[v].push_back(ii(u , c));
    }
    for (int status = 0 ; status <= 1 ; status++) {
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= k ; j++) {
                f[status][i][j] = inf;
            }
        }
    }
    DFS(x , -1);
    cout << f[1][x][k];
    return 0;
}