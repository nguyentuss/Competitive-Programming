#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100007)

int n;
int a[7][MAX_N];
int f[MAX_N][(1 << 5) + 7];
long long check[14] = {0 , 1 , 2 , 4 , 5 , 8 , 9 , 10 , 16 , 17 , 18 , 20 , 21};
string pl[14] = {"00000" , "00001" , "00010" , "00100" , "00101" , "01000" , "01001" , "01010" , "10000" , "10001" , "10010" , "10100" , "10101"};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("chono.inp","r",stdin);
	freopen("chono.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= 5 ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j]; 
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int mask1 = 0 ; mask1 < 13 ; mask1++) {
			for (int mask2 = 0 ; mask2 < 13 ; mask2++) {
				if (!(check[mask1] & check[mask2])){
					int sum = 0;
					for (int j = 1 ; j <= 5 ; j++){
						if ((check[mask1] & (1 << (j - 1)))) 
							sum += a[j][i];
					} 
					if (!(check[mask1] & check[mask2])) 
						f[i][check[mask1]] = max(f[i][check[mask1]] , f[i - 1][check[mask2]] + sum);
				}
			}
		}
	}
	int ans = INT_MIN;
	for (int mask = 0 ; mask < (1 << 5) ; mask++) {
		ans = max(ans , f[n][mask]);
	}
	cout << ans;
	return 0;
}