#include <iostream>
#include <vector>

using namespace std;


#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define INF (int) 1e6 + 7

vector <bool> visited(INF,false);
vector <bool> counted(INF,false);

int main() {
	boost;
	int n; cin >> n;

	visited[1] = true;

	for (int i = 2 ; i <= n ; i++) {
		if (!visited[i]) counted[i] = true;
		for (int j = 2 * i; j <= n ; j += i) 
			visited[j] = true;
	}

	int ans = 0;
	int a = 1 , b = INF;
	while (a <= b) {
		a ++;
		b = n - a;
		if (counted[a] && counted[b]) ans ++;
	}

	cout << ans;

	return 0;
}