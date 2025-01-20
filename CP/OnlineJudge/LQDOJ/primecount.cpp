#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int t ;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		int l , r; cin >> l >> r;
		vector <bool> sieve(r - l + 1 );
		for (int i = 2 ; i * i <= r ; i++) 
			for (int j = max(i * i , (l + i - 1)/i * i) ; j <= r ; j += i) 
				sieve[j - l] = true;
		if (1 >= l) sieve[1 - l] = true;
		int ans = 0;
		for (int i = l ; i <= r ; i++) 
			if (!sieve[i - l]) ans++;
		cout << ans << endl;
	}
	return 0;
}