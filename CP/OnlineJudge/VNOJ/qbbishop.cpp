#include <bits/stdc++.h>

using namespace std;

struct edge {
	int x , y;
};

int n , m , s , t , p , q;
vector<vector<bool>> a(300 , vector<bool> (300 , false));
vector<vector<int>> f(300 , vector<int> (300 , (int) (1e9 + 7)));
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int x , y;
	cin >> n >> m >> p >> q >> s >> t;
	for (int i = 1 ; i <= m ; i++) {
		cin >> x >> y;
		a[x][y] = true;
	}
	queue<edge> wai;
	wai.push((edge){p , q});
	f[p][q] = 0;
	while(!wai.empty()){
		edge u = wai.front();
		int w = f[u.x][u.y];
		wai.pop();
		for (int i = -1 ; i <= 1 ; i += 2) {
			for (int j = -1 ; j <= 1 ; j += 2) {
				edge v = u;
				while (1) {
					v.x += i , v.y += j;
					if (a[v.x][v.y]) break;
					if (v.x < 1 || v.x > n || v.y < 1 || v.y > n) break;
					if (f[v.x][v.y] > w + 1){
						f[v.x][v.y] = w + 1;
						wai.push(v);
					}
				}
			}
		}
	}
	if (f[s][t] == (int) (1e9 +7)) cout << -1;
	else cout << f[s][t];

	return 0;
}