#include <iostream>

using namespace std;

long dem = 0;

bool check (long a) {
	for (int i = 2 ; i * i <= a ; i ++) 
		if (a % i == 0) 
			return false;
	if (a > 1) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	freopen("demnto.inp","r",stdin);
	freopen("demnto.out","w",stdout);

	long n , x; cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> x; 
		if (check(x)) dem ++;
	}
	cout << dem;
	return 0;
}