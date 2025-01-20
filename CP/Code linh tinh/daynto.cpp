#include <iostream>

using namespace std;

bool check (long a) {
	for (int i = 2 ; i * i <= a ; i ++) 
		if (a % i == 0) {
			cout << "NO" << endl;
			return false;
		}
	cout << "YES" << endl;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	//freopen("daynto.inp","r",stdin);
	//freopen("daynto.out","w",stdout);

	long n , x; cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> x; 
		if (x <= 1) cout << "NO" << endl;
		else
			check(x);
	}
	return 0;
}