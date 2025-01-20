#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v;

int main() {
	boost;

	int n , m , k ; cin >> n >> m >> k;

	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= m ; j ++) 
			v.push_back(i * j);

	sort(v.begin() , v.end());
	cout << v[k - 1];

	return 0;
}