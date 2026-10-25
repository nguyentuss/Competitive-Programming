#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define ii pair<int ,int>
#define x first
#define y second

int m , n , X , Y;
int a[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	freopen("lienthong.inp","r",stdin);
	freopen("lienthong.out","w",stdout);
	cin >> n >> m >> X >> Y;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	queue<ii> q;
	if (a[X][Y] == 1) cout << 0;
	else {
		int ans = 1;
		q.push(ii(X , Y));
		vis[X][Y] = true;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0 ; i < 4 ; i ++) {
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (1 <= newx && newx <= n && 1 <= newy && newy <= m && a[newx][newy] == 0){
					if (vis[newx][newy] == false) {
						q.push(ii(newx , newy));
						vis[newx][newy] = true;
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}