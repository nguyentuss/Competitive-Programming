#include <bits/stdc++.h>

using namespace std;

int n , ans = 0;
vector <int> x(21);
void write() {
	for (int i = 1 ; i <= n - 1; i++) 
		if ((x[i] == 2 && x[i + 1] == 3) || (x[i] == 3 && x[i + 1] == 2)) 
			return;
	ans ++;
}

int backtr(int i) {
	for (int j = 1 ; j <= 3 ; j++){
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("ghepxau.inp","r",stdin);
	freopen("ghepxau.out","w",stdout);
	cin >> n;
	backtr(1);
	cout << ans;
	return 0;
}