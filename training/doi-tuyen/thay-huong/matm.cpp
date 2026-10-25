#include <bits/stdc++.h>

using namespace std;

int n , k , ans = 0;
vector <int> x(21);
vector <int> a(21) , b(21);

void write() {
	long long total = 0;
	for (int i = 1 ; i <= n; i++)
		total += a[i]*x[i];
	if (total == k) ans ++; 
}

int backtr(int i) {
	for (int j = 0 ; j <= b[i] ; j++) {
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("matm.inp","r",stdin);
	freopen("matm.out","w",stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (int i = 1 ; i <= n; i++) 
		cin >> b[i];
	backtr(1);
	cout << ans;
	return 0;
}