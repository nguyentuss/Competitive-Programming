#include <bits/stdc++.h>

using namespace std;

int n , m , r1 , c1 , r2 , c2;
char grid[507][507];
int vis[507][507];

bool dfs(int i, int j) {
    if (i == r2 && j == c2) return 1;
    if (i > n || j > m || i <= 0 || j <= 0 || vis[i][j] || grid[i][j] == 'X') return 0;
    vis[i][j] = 1;
    if (dfs(i + 1, j) || dfs(i - 1, j) || dfs(i, j + 1) || dfs(i, j - 1))
        return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ;i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    grid[r1][c1] = '.';
    if (dfs(r1 , c1)) {
        int cnt = 0;
        if (r2 - 1 >= 1 && grid[r2 - 1][c2] == '.') cnt++;
        if (r2 + 1 <= n && grid[r2 + 1][c2] == '.') cnt++;
        if (c2 - 1 >= 1 && grid[r2][c2 - 1]  ==  '.') cnt++;
        if (c2 + 1 <= m && grid[r2][c2 + 1] == '.') cnt++;
        if (r1 == r2 && c1 == c2) {
            cout <<  (cnt?"YES":"NO");
        }
        else {
            //cout << grid[r2][c2]=='X'||cnt>1 ?"YES":"NO";
            cout << (grid[r2][c2] == 'X' || cnt>1?"YES" : "NO") << endl;
        }
    }
    else cout << "NO";
    return 0;
}