#include <iostream>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int main() {
	boost;
	int n ; cin >> n ;
	vector <int> f(1e6);
	f[1] = 0;
	cout << f[1];
	return 0;
}