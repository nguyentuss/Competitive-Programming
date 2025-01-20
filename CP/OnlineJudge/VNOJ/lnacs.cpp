#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	vector <int> a(1e3 + 7) , b(1e3 + 7);
	int n , m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= m ; i++) cin >> b[i];

	long long F[n+1][m+1];
	for (int i = 0 ; i <= n ; i ++){
		for (int j = 0 ; j <= m ; j++) {
			if (i == 0 || j == 0) F[i][j] = 0;
			else if (a[i] == b[j]) F[i][j] = F[max(i-2 , 0)][max(j-2 , 0)] + 1;
			else F[i][j] = max(F[i-1][j],F[i][j-1]);
		}
	}
	cout << F[n][m];

	return 0;
}