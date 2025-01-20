#include <bits/stdc++.h>

using namespace std;

struct edge {
	int x , y , z;
};

struct lit{
	double len;
	edge trace;
};

lit f[107][107][107];
int a[107] , b[107] , c[107];
vector <int> res;

void maximum(lit &a , lit b) {
	if (a.len < b.len) a = b;
}

void trace(int i , int j , int k) {
	int x = f[i][j][k].trace.x;
	int y = f[i][j][k].trace.y;
	int z = f[i][j][k].trace.z;
	if (x && y && z) trace(x , y , z);
	if (a[i] == b[j] && b[j] == c[k]) res.push_back(a[i]); 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n ; cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= n ; i++) cin >> b[i];
	for (int i = 1 ; i <= n ;i++) cin >> c[i];
	for (int i = 1 ; i <= n ;i ++) {
		for (int j = 1 ; j <= n ; j++) {
			for (int k = 1 ; k <= n ; k++) {
				maximum(f[i][j][k] , lit{f[i - 1][j][k].len , edge{i - 1 , j , k}});
				maximum(f[i][j][k] , lit{f[i][j - 1][k].len , edge{i , j - 1 , k}});
				maximum(f[i][j][k] , lit{f[i][j][k - 1].len , edge{i , j , k - 1}});
				if (a[i] == b[j] && b[j] == c[k]) {
					f[i][j][k] = lit{f[i - 1][j - 1][k - 1].len + (double) (log(a[i])) , edge{i - 1 , j - 1 , k - 1}};
				}
			}
		}
	}
	trace(n , n , n);
	cout << res.size() << '\n';
	for (auto e : res) cout << e << " ";
	return 0;
}