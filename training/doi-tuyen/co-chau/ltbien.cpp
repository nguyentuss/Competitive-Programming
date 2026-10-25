#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e2 + 7)
#define ii pair<int ,int>
#define x first
#define y second

int a[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int ans = 0;
int n , m;

void BFS(int i , int j) {
	queue<ii> q;
	int total = 1;
	vis[i][j] = true;
	q.push(ii(i , j));
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (1 <= newx && newx <= n && 1 <= newy && newy <= m && a[newx][newy] == 0) {
				if (!vis[newx][newy]) {
					q.push(ii(newx , newy));
					vis[newx][newy] = true;
					total ++;
				}
			}
		}
	}
	ans = max(ans , total);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("ltbien.inp","r",stdin);
	freopen("ltbien.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		if (a[i][1] == 0 && vis[i][1] == false) 
			BFS(i , 1);
		if (a[i][m] == 0 && vis[i][m] == false) 
			BFS(i , m);
	}
	for (int i = 1 ; i <= m ; i++) {
		if (a[1][i] == 0 && vis[1][i] == false) 
			BFS(1 , i);
		if (a[n][i] == 0 && vis[n][i] == false) 
			BFS(n , i); 
	}
	cout << ans;

	return 0;
}