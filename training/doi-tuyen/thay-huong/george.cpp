#include <bits/stdc++.h>

using namespace std;

#define inf (int) (-1e9 + 7)
#define MAX_N (int) (5e3 + 7)

long long F[MAX_N][MAX_N];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("george.inp","r",stdin);
	freopen("george.out","w",stdout);
	int n , m , k , x;
	cin >> n >> m >> k;
	vector <int> v;
	v.push_back(inf);
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	vector <long long> sum(MAX_N);
	sum[0] = 0;
	for (int i = 1 ; i <= n ; i++) 
		sum[i] += sum[i - 1] + v[i];
	for (int i = m ; i <= n ; i++) {
		long long tmp = sum[i] - sum[i - m];
		for (int j = 1 ; j <= k ; j++) {
			F[i][j] = max(F[i - 1][j] , F[i - m][j - 1] + tmp);
		} 
	}
	cout << F[n][k];
	return 0;
}