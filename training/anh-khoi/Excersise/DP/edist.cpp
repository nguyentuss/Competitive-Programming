#include <iostream>
#include <cmath>
 
using namespace std;
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//freopen("edist.inp","r",stdin);
	//freopen("edist.out","w",stdout);
 
	int t;
	cin >> t;
	while (t --) {
		string a,b;
		long long F[2003][2003];
 
		cin >> a >> b;
 
		int m = a.size() , n = b.size();
		for (int i = 1 ; i <= m ; i ++) F[i][0] = i;
		for (int i = 1 ; i <= n ; i ++) F[0][i] = i;
		for (int i = 1 ; i <= m ; i ++){
			for (int j = 1 ; j <= n ; j++) {
				if (a[i-1] == b[j-1]) F[i][j] = F[i-1][j-1];
				else F[i][j] = min(F[i-1][j]+1,min(F[i][j-1]+1,F[i-1][j-1]+1));
			}
		}
 
		/*for (int i = 0 ; i <= m ; i++) {
			for (int j = 0 ; j <= n ; j ++) 
				cout << F[i][j] << " ";
			cout << endl;
		}*/
		cout << F[m][n] << endl;
	}
	return 0;
} 