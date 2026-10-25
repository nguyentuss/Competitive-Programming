#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n;
vector <int> v(MAX_N);
int P[MAX_N][100];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		P[i][0] = v[i];
	}
	for (int j = 1 ; (1 << j) <= n ; j++) {	
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
				P[i][j] = min(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);
		}
	}
	int q;
	cin >> q;
	int l , r;
	for (int i = 1 ; i <= q ;i++) {
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << min(P[l][k] , P[r - (1 << k) + 1][k]) << '\n';
	}
	return 0;
}