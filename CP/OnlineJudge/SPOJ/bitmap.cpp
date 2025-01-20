#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

struct coordidate{
	int x , y;
};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
	boost;
	int t; cin >> t;
	while (t--) {
		queue<coordidate> q;
		int n , m ; cin >> n >> m;
		int a[200][200];
		int dist[200][200];
		memset(dist , -1 , sizeof(dist));
		for (int i = 1 ; i <= n; i++) 
			for (int j = 1 ; j <= m ; j ++) {
				char str;
				cin >> str;
				a[i][j] = (int) str - '0';
			}

		for (int i = 1 ; i <= n ; i++) 
			for (int j = 1 ; j <= m ; j ++) 
				if (a[i][j] == 1) {
					q.push((coordidate) {i,j});
					dist[i][j] = 0;
				}
		int xx , yy;
		while (!q.empty()) {
			coordidate current = q.front();
			q.pop();
			for (int i = 0 ; i <= 3 ; i++){
				xx = current.x + dx[i];
				yy = current.y + dy[i];
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dist[xx][yy] == -1) {
					dist[xx][yy] = dist[current.x][current.y] + 1;
					q.push((coordidate) {xx,yy});
				} 
				
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) 
				cout << dist[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}