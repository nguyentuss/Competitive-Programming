#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("boiso.inp","r",stdin);
	freopen("boiso.out","w",stdout);
	int b , n ; cin >> b >> n;
	for (int i = b ; i <= n ; i+= b) {
		cout << i << " " ;
	}
	return 0;
}