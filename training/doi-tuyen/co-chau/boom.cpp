#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
// cái này là để di chuyển trái trên phải dưới á nha
bool vis[1007][1007];
int a[1007][1007];
int ans = 1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("boom.inp","r",stdin);
	freopen("boom.out","w",stdout);
	int n , m , x , y; cin >> n >> m >> x >> y;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
		}
	}
	queue <ii> q;
	q.push(ii(x , y));
	vis[x][y] = 1;
	while (q.empty() == false) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0 ; k < 4 ; k++) {
			int newi = i + dx[k];
			int newj = j + dy[k];
			// cái if này ktra cái tọa độ có nằm trong cái bảng kh
			if (newi < 1 || newj < 1 || newi > m || newj > n)  continue;
			if (vis[newi][newj] == false) {
				if (a[newi][newj] == 1) // nếu mà nó là bom thì cho vào queue
					q.push(ii(newi , newj));
				vis[newi][newj] = true;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}