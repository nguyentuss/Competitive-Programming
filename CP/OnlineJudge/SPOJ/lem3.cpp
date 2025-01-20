#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define MAX_N (int) 20

int f[MAX_N][1 << MAX_N];
int cost[MAX_N][MAX_N];
int n;

bool checkbit(int &pos , int &mask) {
	if ((mask&(1 << pos)) == (1 << pos))
		return true;
	else return false;
}

void dp() {
	const int inf = 200000;
	for (int u = 0 ; u < n ; u++) 
		for (int mask = 0 ; mask < (1 << n) ; mask ++) 
			f[u][mask] = inf;
	for (int u = 0 ; u < n ; u++) 
		f[u][1 << u] = 0;
	for (int mask = 1 ; mask < (1 << n) ; mask ++) 
		for (int u = 0 ; u < n; u++) 
			if (checkbit(u , mask) == true)
				for (int v = 0 ; v < n ; v++) 
					if (v != u && checkbit(v , mask)) 
						f[u][mask] = min(f[u][mask] , f[v][mask ^ (1 << u)] + cost[v][u]); 
	int ans = inf;
	cout << f[0][5];
	/*for (int mask = 1 ; mask < (1 << n) ; mask ++) {
		cout << "(" << mask << " , " << f[0][mask] << ")	 ";
		if (mask % 10 == 0) cout << endl;
	}*/


	cout << f[1][(1 << n) - 1];
	for (int u = 0  ; u < n ; u++){
		// 
		ans = min(ans , f[u][(1 << n) - 1]);
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("lem3.inp","r",stdin);
	freopen("lem3.out","w",stdout);
	cin >> n;
	for (int i = 0 ; i < n ; i ++) 
		for (int j = 0 ; j < n ; j++) {
			cin >> cost[i][j];
		
		}
	dp();
	return 0;
}