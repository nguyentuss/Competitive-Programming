#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("ducln.inp","r",stdin);
	freopen("ducln.out","w",stdout);
	int n , a ; cin >> n;
	int x = 0;
	cin >> a;
	x = __gcd(x,a);
	for (int i = 2; i <= n ; i++){
		cin >> a;
		x = __gcd(x,a);
	}
	cout << x;
	return 0;
}