#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast")
#define inf (int) (1e9 + 7)
int ans = inf , i, j, sum, A[30][30], n, vt = 0;
bool check[100000]; 
vector <int> pl;

void init(){
	for (int i = 0 ; i <= 10000 ; i++) 
		check[i] = true;
}

void ql(int x , int counted){
	if (sum > ans) return;
	for (int j = 2 ; j <= n; j++){
		if (check[j]){
			check[j] = false;
			sum += A[x][j];
			if (counted==n){
				sum += A[j][1];
				ans = min(ans, sum);
				sum -= A[j][1];
			}
			else ql(j , counted + 1);
			sum -= A[x][j];
			check[j] = true;
		}
	}
}
int main(){
	 freopen("tsp.inp", "r", stdin);
	 freopen("tsp.out", "w", stdout);
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		  cin >> A[i][j];
	sum = 0;
	ql(1 , 2);
	cout << ans;
	return 0;
}