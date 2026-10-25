#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (507)

struct pos {
	int x , y; 
};

int a[MAX_N][MAX_N];
bool b[MAX_N][MAX_N];
vector<pos> v;
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
bool vis[MAX_N][MAX_N];
int n , m;

bool ktra(int x , int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

bool check(int c) {
	queue<pos> q;
	memset(vis , 0 , sizeof vis);
	q.push(v[0]);
	vis[v[0].x][v[0].y] = true;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int x = u.x + dx[i];
			int y = u.y + dy[i];	
			if (ktra(x , y) && !vis[x][y] && abs(a[u.x][u.y] - a[x][y]) <= c) {
				vis[x][y] = true;
				q.push({x , y});
			} 
		}
	}
	for (auto tm : v) if (!vis[tm.x][tm.y]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("voi.inp","r",stdin);
	freopen("voi.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> b[i][j];
			if (b[i][j]) v.push_back({i , j}); 
		}
	}
	int l = 0 ,  r = 1e9;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}