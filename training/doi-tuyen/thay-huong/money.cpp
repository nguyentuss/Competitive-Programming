#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#pragma GCC optimize("Ofast")

int n , s;
vector <int> v(23);
vector <int> x(23);
int counted = 0;

void write() {
	int total = 0;
	for (int i = 1 ; i <= n; i++) {
		total += x[i] * v[i];
	}
	if (total == s) counted ++; 
}

int backtr(int i) {
	for (int j = 0  ; j <= 1 ; j++) {
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	}
	return 0;
}

int main(){
	freopen("money.inp","r",stdin);
	freopen("money.out","w",stdout);
	cin >> n >> s;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	backtr(1);
	cout << counted;

	return 0;
}