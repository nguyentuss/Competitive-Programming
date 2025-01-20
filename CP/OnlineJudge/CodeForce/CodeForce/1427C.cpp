#include <bits/stdc++.h>

using namespace std; 

#define MAX_N (int) (1e5 + 7)

int f[MAX_N];
int x[MAX_N], y[MAX_N], t[MAX_N];
int f_max[MAX_N];

int main(){	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int ans = 0;
	int r , n; cin >> r >> n;
	for (int i = 1 ; i <= n ; i++) {
		f[i] = -1;
	}
	f[0] = 0;
	x[0] = 1 , y[0] = 1;
	for (int i = 1 ; i <= n ;i++) {
		cin >> t[i] >> x[i] >> y[i];	
		f_max[i] = f_max[i - 1];
		for (int j = i - 1 ; j >= 0 ; j--) {
			if (f[j] == -1) continue;
			if ((t[i] - t[j]) > (2*r - 2)) {
				f[i] = max(f[i] , f_max[j] + 1);
				f_max[i] = max(f_max[i] ,f[i]);
				break; 
			}
			if ((abs(x[i] - x[j]) + abs(y[i] - y[j])) <= (t[i] - t[j])) {
				f[i] = max(f[i] , f[j] + 1);
			}
			f_max[i] = max(f_max[i] , f[i]);
		}
		//cout << f[i] << " "; 
	}
	for (int i = 1 ; i <= n ; i++) {
		ans = max(ans , f_max[i]);
	}
	cout << ans;
	return 0;
}