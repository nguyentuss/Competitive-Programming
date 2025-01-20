#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	long long count = 0;
	long long n , x; cin >> n >> x;
	for (int i = 1 ; i <= n ; i++) {
		if (x % i == 0 && x <= i * n) count ++;
	}
	cout << count;
	return 0;
}