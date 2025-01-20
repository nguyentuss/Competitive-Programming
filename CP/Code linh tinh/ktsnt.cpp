#include <iostream>

using namespace std;

bool check (long a) {
	for (int i = 2 ; i * i <= a ; i ++) 
		if (a % i == 0) return false;
	
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	freopen("ktsnt.inp","r",stdin);
	freopen("ktsnt.out","w",stdout);

	long n ; cin >> n;
	if (n <= 1) cout << 0 ;
	else
		cout << check(n);
	return 0;
}