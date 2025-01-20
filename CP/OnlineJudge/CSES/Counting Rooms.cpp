#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int> 
#define int long long

const int N = 1e3 + 7;
const int inf = 1e18;

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    vector<vector<char>> a(n + 1 , vector<char>(m + 1));
    vector<vector<bool>> vis(n + 1 , vector<bool>(m + 1));
    queue<ii> q; 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.')  q.push(ii(i , j));
        }
    }

    auto inside = [&](int x , int y) -> bool {
        return (1 <= x && 1 <= y && x <= n && y <= m);
    };

    int cnt = 0;
    while (!q.empty()) {
        auto [x , y] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        queue<ii> pq;
        auto solve = [&](int x , int y) -> void {
            if (inside(x , y) && a[x][y] != '#' && !vis[x][y]) {
                vis[x][y] = true;
                pq.push(ii(x , y));
            }
        };
        cnt ++;
        pq.push(ii(x , y));
        vis[x][y] = true;
        while (!pq.empty()) {
            auto [x , y] = pq.front(); 
            pq.pop();
            solve(x + 1 , y);
            solve(x - 1 , y);
            solve(x , y + 1);
            solve(x , y - 1);
        }
    }
    cout << cnt;
    return 0;
}