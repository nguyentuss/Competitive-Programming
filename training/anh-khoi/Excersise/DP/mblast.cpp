#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("mblast.inp","r",stdin);
#define fo freopen("mblast.out","w",stdout);

int F[3005][3005];

int main() {
	boost;
	fi;fo;
	string a, b;
	int k;
	cin >> a; cin >> b; cin >> k;
	int m = a.size(), n = b.size();

	for (int i = 1 ; i <= m ; i++) F[i][0] = k * i;
	for (int i = 1 ; i <= n ; i++) F[0][i] = k * i;

	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			F[i][j] = min(F[i-1][j]+k,min(F[i][j-1]+k,F[i-1][j-1] + abs((((int)a[i-1]-96) - ((int)b[j-1]-96)))));
		}
	} 
	for (int i = 0 ; i <= m ; i++) {
		for (int j = 0 ; j <= n ; j ++) 
			cout << F[i][j] << " " ;
		cout << endl;
	}
	cout << F[m][n];
	return 0;
}