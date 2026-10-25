#include <bits/stdc++.h>

using namespace std;

void dfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    stack<pair<int, int>> stack;
    stack.push({x, y});
    
    while (!stack.empty()) {
        auto [cx, cy] = stack.top();
        stack.pop();
        
        if (cx < 0 || cx >= n || cy < 0 || cy >= m || visited[cx][cy] || grid[cx][cy] == 1) {
            continue;
        }
        
        visited[cx][cy] = true;
        
        stack.push({cx + 1, cy});
        stack.push({cx - 1, cy});
        stack.push({cx, cy + 1});
        stack.push({cx, cy - 1});
    }
}

int minRectanglesToCover(int n, int m, vector<vector<int>>& grid) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rectangles_count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                ++rectangles_count;
                dfs(i, j, n, m, grid, visited);
            }
        }
    }
    
    return rectangles_count;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    cout << minRectanglesToCover(n, m, grid) << endl;
    
    return 0;
}
