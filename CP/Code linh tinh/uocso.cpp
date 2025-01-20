#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("uocso.inp","r",stdin);
	freopen("uocso.out","w",stdout);
	int n ; cin >> n ;
	for (int i = 1; i <= n ; i ++) 
		if (n % i == 0) cout << i << " " ;
	return 0;
}