#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int v[1000007] , sum[1000007];

int main() {
	boost;
	int n; cin >> n;
	int ans = INT_MAX;
	sum[0] = 0;

	for (int i = 1 ; i <= n; i++) {
		cin >> v[i];
		//cout << v[i] << " ";
		if (v[i] == 0) sum[i] += sum[i-1] + 1;
		else {
			sum[i] = 0;
			if (sum[i-1] != 0)
			ans = min(ans,sum[i-1]);
		}
	}

	cout << ans;


	return 0;
}