#include <bits/stdc++.h>

using namespace std;

int n , ans = INT_MAX , total = 0 , totalbaby1, totalbaby2;
vector <int> x(21);
vector <int> v(21);

void write() {
	totalbaby1 = 0 , totalbaby2 = 0;
	for (int j = 1 ; j <= n; j++) 
		if (x[j] == 0) totalbaby1 += v[j];
	totalbaby2 = total - totalbaby1;
	ans = min(ans , abs(totalbaby1 - totalbaby2));
}

int backtr(int i) {
	for (int j = 0 ; j <= 1 ; j++){
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("chiakeo.inp","r",stdin);
	//freopen("chiakeo.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i];
		total += v[i];
	}
	backtr(1);
	cout << ans;
	return 0;
}