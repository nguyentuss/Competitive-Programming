#include <bits/stdc++.h>
using namespace std;

long b[101][101] = {0};
long smax = -1e8;

int main(){
	freopen ("bai12.inp","r",stdin);
	freopen ("bai12.out","w",stdout);
	int n , m , tam , d1 , c1 , d2 , c2; cin >> m >> n;
	for (int i = 1; i<=m ; i++)
		for (int j = 1 ; j<=n ; j++){
			cin >> tam;
			b[i][j] = tam + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
		}
	for (int x1 = 1; x1 <= m;x1++)
		for (int y1 = 1;y1<=n;y1++)
			for (int x2 = x1;x2<=m;x2++)
				for (int y2 = y1;y2<=n;y2++){
					int s = b[x2][y2] - b[x1-1][y2] - b[x2][y1-1] + b[x1-1][y1-1];
					if (s > smax){
						smax = s;
						d1 = x1;
						c1 = y1;
						d2 = x2;
						c2 = y2;
					}
				}
	cout << smax << endl;
	cout << d1 << " " << c1 << " " << d2 << " " << c2;

}