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

int f[N];
bool vis[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int k; cin >> k;
    for (int i = 0 ; i <= k ;i ++) {
        f[i] = inf;
    }
    f[1] = 1;
    deque<int> q; q.push_back(1);
    while (!q.empty()) {
        int u = q.back(); 
        q.pop_back();
        int v = (u*10)%k;
        if (f[v] > f[u]) {
            f[v] = f[u];
            q.push_back(v);
        }
        v = (u + 1)%k; 
        if (f[v] > f[u] + 1) {
            f[v] = f[u] + 1;
            q.push_front(v);
        }
    }
    //for (int i = 1 ; i <= n ; i++) 
    for (int i = 1; i  < 20 ; i++) {
        cout << f[i] << " ";
    }
    return 0;
}