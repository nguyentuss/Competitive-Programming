#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const double inf = 1e9 + 7;
const int MAX_N = 5e2 + 7;
const int MOD = 1e9 + 7;
const double esp = 1e-9;

int n , m , q;
int a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
int c[MAX_N][MAX_N];
int d[MAX_N][MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> q;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1 ; i <= q ; i ++) {
		int x1 , y1 , x2 , y2 , val; cin >> x1 >> y1 >> x2 >> y2 >> val; 
		a[x1][y1] += val;
		a[x2 + 1][y1] -= val;
		a[x1][y2 + 1] -= val;
		a[x2 + 1][y2 + 1] += val;
	}
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= m ; j++) {
			b[i][j] = b[i - 1][j] + a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			d[i][j] = d[i][j - 1] + b[i][j];
		}
	}
	
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cout << d[i][j] + c[i][j] << " ";
		}
		cout << '\n';
	}
    return 0;
}