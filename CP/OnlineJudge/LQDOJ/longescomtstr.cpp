#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0);cin.tie(NULL);


int main() {

	boost;
	string a,b;

	cin >> a >> b;

	int m = a.size() , n = b.size();
	int F[m + 1][n + 1];
	for (int i = 0 ; i <= m ; i ++){
		for (int j = 0 ; j <= n ; j++) {
			if (i == 0 || j == 0) 
				F[i][j] = 0;
			else if (a[i - 1] == b[j-1]) 
				F[i][j] = F[i-1][j-1] + 1;
			else 
				F[i][j] = max(F[i-1][j],F[i][j-1]);
		}
	}

	string ans;
	for (int i = m , j = n ; i > 0 , j > 0 ; ) {
		if (a[i - 1] == b[j - 1]) {
			ans += a[i - 1];
			i --;
			j --;
		}
		else {
			if (F[i - 1][j] > F[i][j - 1]) i --;
			else j --;
		}
	}

	reverse(ans.begin() , ans.end());
	cout << ans;

	return 0;
}