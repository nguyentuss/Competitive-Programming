#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e4 + 7)
#define ii pair<int ,int>
#define f first
#define s second

int n , m;
char v[MAX_N][12];
int sum[12][MAX_N];
char build[MAX_N][12];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("apples.inp","r",stdin);
	freopen("apples.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> v[i][j];
			build[i][j] = '1';
		}
	}
	for (int i = 1 ; i <= m ; i++) 
		v[n + 1][i] = '#';
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			if (v[j][i] == '#') sum[i][j] = 0;
			else if (v[j][i] == 'a') {
				sum[i][j] = sum[i][j - 1] + 1;
			}
			else sum[i][j] = sum[i][j - 1];
		}
	}
	vector<ii> pos;
	for (int i = 1 ; i <= n + 1 ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (v[i][j] == '#') {
				pos.push_back(ii(i , j));
			}
		}
	}
	for (auto e : pos) {
		int x = e.f , y = e.s;
		int apples = sum[y][x - 1];
		build[x][y] = '#';
		while (apples > 0) {
			build[--x][y] = 'a';
			apples--;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (build[i][j] == '1') cout << '.';
			else cout << build[i][j];
		}
		cout << '\n';
	}
	return 0;
}