#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;

	long long n; cin >> n;

	long long ans = 0;
	for (long long i = 1 ; i <= n - 1 ; i++) {
		//cout << i << " " << n - i << endl;
		ans += max(0LL,(i - 1)/2 - max((i - (n - i)),0LL));
		//cout << ans << endl;
	}
	cout << ans;
	return 0;
}