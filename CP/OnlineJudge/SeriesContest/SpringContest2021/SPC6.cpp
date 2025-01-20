#include <iostream>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("SPC6.inp","r",stdin);
#define fo freopen("SPC6.out","w",stdout);

int main() {
	boost;
	fi;fo;

	int t; cin >> t;
	while (t --){
		long long n , m ; cin >> n >> m;
		char a[n+1][m+1];
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cout << n + m - 3;
	}

	return 0;
}