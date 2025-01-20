#include <bits/stdc++.h>

using namespace std;

bool v[1007][1007];
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> v[i][j];
		}
	}
	bitset<1007> r[1007] , c[1007];
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			bool chr = v[i][j]?1:0; 
			bool chc = v[j][i]?1:0;
			r[i][j] = chr;
			c[i][j] = chc;
		}
	}

	bitset<1007> temp;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			if (r[i][j]) {
				temp = c[i]&r[j];
				if (temp.count() > 0) {
					for (int k = 1 ; k <= n ; k ++) {
						if (temp[k]) {
							cout << i << " " << j << " " << k;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1;

	return 0;
}