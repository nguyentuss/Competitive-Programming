#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("bcnn.inp","r",stdin);
	freopen("bcnn.out","w",stdout);
	int a , b; cin >> a >> b;
	cout << (a*b) / __gcd(a,b);
	return 0;
}