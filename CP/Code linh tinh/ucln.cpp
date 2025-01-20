#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("ucln.inp","r",stdin);
	freopen("ucln.out","w",stdout);
	int a ,b  ; cin >> a >> b ;
	cout << __gcd(a,b);
	return 0;
}