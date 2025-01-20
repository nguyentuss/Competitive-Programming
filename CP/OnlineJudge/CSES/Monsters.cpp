#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define ii pair<int , int>

const int N = 1e3 + 7;
const int inf = 50;

char a[N][N];
ii P[N][N];

main(){ncin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    queue<ii> q;
    vector<vector<int>> d(n , vector<int> (m , inf));
    vector<vector<bool>> vis(n , vector<bool> (m , false));
    ii start;
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'M') {
                q.push(ii(i , j));
                vis[i][j] = true;
                d[i][j] = 0;
            }
            if (a[i][j] == 'A') {
                start = ii(i , j);
            }
        }
    }
    vector<vector<int>> monster(n , vector<int> (m , inf));
    auto inside = [&](int x , int y) -> bool {
        return (0 <= x && 0 <= y && x < n && y < m);
    };
    auto solve = [&](int px , int py , int x , int y , int status) -> void {
        if (inside(x , y) && a[x][y] != '#' && !vis[x][y]) {
            if (!status) {
                q.push(ii(x , y));
                vis[x][y] = true;
                d[x][y] = d[px][py] + 1;
            }
            else {
                if ((d[px][py] + 1) < monster[x][y]) {
                    q.push(ii(x , y));
                    d[x][y] = d[px][py] + 1; 
                    P[x][y] = ii(px , py);
                    vis[x][y] = true;
                }
            }
        }
    };

    while (!q.empty()) {
        auto [x , y] = q.front(); 
        q.pop();
        solve(x , y , x + 1 , y , 0); 
        solve(x , y , x - 1, y , 0);
        solve(x , y , x , y + 1 , 0);
        solve(x , y , x , y - 1 , 0); 
    }   
    monster = d;
    d = vector<vector<int>>(n , vector<int>(m , inf)); 
    q.push(start); 
    vis = vector<vector<bool>>(n , vector<bool>(m , false)); 
    vis[start.first][start.second] = true;
    d[start.first][start.second] = 0;
    while (!q.empty()) {
        auto [x , y] = q.front(); 
        q.pop(); 
        solve(x , y , x + 1 , y , 1); 
        solve(x , y , x - 1, y , 1);
        solve(x , y , x , y + 1 , 1);
        solve(x , y , x , y - 1 , 1); 
    }       
    auto check = [&]() -> ii {
        for (int i = 0 ; i < n ; i++) {
            if (d[i][0] != inf) return ii(i , 0);
            if (d[i][m - 1] != inf) return ii(i , m - 1);
        }
        for (int i = 0 ; i < m ; i++) {
            if (d[0][i] != inf) return ii(0 , i);
            if (d[n - 1][i] != inf) return ii(n - 1 , i);
        }
        return ii(-1 , -1);
    };
    auto [x , y] = check();
    if (x == -1 && y == -1) cout << "NO";
    else {
        cout << "YES\n" << d[x][y] << '\n';
        vector<char> res;
        //cerr << x << " " << y << '\n';
        while (x != start.first || y != start.second) {
            auto [px , py] = P[x][y];
            if (x > px) res.push_back('D');
            if (x < px) res.push_back('U');
            if (y < py) res.push_back('L');
            if (y > py) res.push_back('R');
            x = px;
            y = py;
            //cerr << x << " " << y << '\n';u
        }
        reverse(res.begin() , res.end()); 
        for (auto x : res) cout << x;
    }
    return 0;
}