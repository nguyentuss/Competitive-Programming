#include <bits/stdc++.h>

using namespace std;

int n , ans = INT_MAX , total = 0 , total1, total2 , total3;
vector <int> x(21);
vector <int> v(21);

void write() {
	total1 = 0 , total2 = 0 , total3 = 0;
	for (int j = 1 ; j <= n; j++){ 
		if (x[j] == 0) total1 += v[j];
		else if (x[j] == 1) total2 += v[j];
		else if (x[j] == 2) total3 += v[j];
	}
	int maximum = INT_MIN , minimum = INT_MAX;
	maximum = max(maximum , max(total1 , max(total2 , total3)));
	minimum = min(minimum , min(total1 , min(total2 , total3)));
	ans = min(ans , maximum - minimum);
}

int backtr(int i) {
	for (int j = 0 ; j <= 2 ; j++){
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("chiaqua.inp","r",stdin);
	freopen("chiaqua.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i];
	}
	backtr(1);
	cout << ans;
	return 0;
}