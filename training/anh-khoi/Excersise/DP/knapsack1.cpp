#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("knapsack1.inp","r",stdin);
#define fo freopen("knapsack1.out","w",stdout);

long long a[1001],b[1001];
long long F[101][100007];

int main() {
	boost;
	//fi;fo;

	int n,w ; cin >> n >> w;

	for (int i = 1 ; i <= n; i++) 
		cin >> a[i] >> b[i];

	for (int i = 1 ; i <= n ;i ++) F[0][i] = 0;

	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= w ; j ++) {
			if (a[i] > j) F[i][j] = F[i-1][j];
			else F[i][j] = max(F[i-1][j],F[i-1][j-a[i]] + b[i]);
		}
	}

	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= w ; j ++) 
			cout << F[i][j] << " " ;
		cout << endl;
	}

	cout << F[n][w];


	return 0;
}