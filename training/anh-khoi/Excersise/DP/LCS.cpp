#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	string a,b;

	cin >> a >> b;

	long long m = a.size() , n = b.size();
	long long F[m+1][n+1];
	for (int i = 0 ; i <= m ; i ++){
		for (int j = 0 ; j <= n ; j++) {
			if (i == 0 || j == 0) F[i][j] = 0;
			else if (a[i - 1] == b[j-1]) F[i][j] = F[i-1][j-1] + 1;
			else F[i][j] = max(F[i-1][j],F[i][j-1]);
		}
	}

	/*for (int i = 0 ; i <= m ; i++) {
		for (int j = 0 ; j <= n ; j++)
			cout << F[i][j] << " " ;
		cout << endl;
	}*/
	cout << F[m][n];

	return 0;
}