#include <iostream>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> a[10000];

int main() {
	boost;

	int m , k; cin >> m >> k;

	for (int i = 0 ; i < k ; i++) {
		int u , v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}


	for (int i = 1 ; i <= m ; i++) {
		cout << i << ":";
		for (int j = 0 ; j < (int) a[i].size() ; j++) 
			cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}