#include <bits/stdc++.h>

using namespace std;

bool f[505][505];
long long sumc[505][505] , sumd[505][505];
int v[505][505];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("AC4.inp","r",stdin);
	freopen("AC4.out","w",stdout); 
	int t; cin>> t; 
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0 ; i <= 4; i++) {
			for(int j = 0 ; j <= 4; j++) {
				sumc[i][j] = sumd[i][j] = 0;
				f[i][j] = false;
			}
		}
		for (int i = 1; i <= 4 ; i++) {
			for (int j = 1 ; j <= 4 ; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 1 ; i <= 4 ; i++) {
			sumc[0][i] = sumd[i][0] = 0;	
		}
		for (int i = 1 ; i <= 4 ; i++) {
			for (int j = 1 ; j <= 4 ; j++) {
			sumd[i][j] = sumd[i][j - 1] + v[i][j];
			sumc[j][i] = sumc[j-1][i] + v[j][i];
			}
		}
		for (int i = 1 ; i <= 4 ; i++) {
			for (int j = 1 ; j <= 4 ; j++) {
				f[i][j] = false;
				if (!f[i][j - 1] && (sumc[i][j] % 2 == 0)) 
					f[i][j] = true;
				if (!f[i - 1][j] && (sumd[i][j] % 2 == 0))	 
					f[i][j] = true;
				//else f[i][j] = false;	
			}
		}
		if (f[4][4] == true) cout << "Bun" << '\n';
		else cout << "Dau" << '\n';
	}
	return 0;
}