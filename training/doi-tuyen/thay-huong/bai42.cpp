#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> x(21);

void write() {
	for (int i = 1 ; i <= n; i++) cout << x[i];
	cout << endl;
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
	//freopen("bai42.inp","r",stdin);
	//freopen("bai42.out","w",stdout);
	cin >> n;
	backtr(1);
	return 0;
}