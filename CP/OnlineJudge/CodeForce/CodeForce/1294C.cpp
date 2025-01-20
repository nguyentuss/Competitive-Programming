#include <bits/stdc++.h>

using namespace std;

int n , a , b , c , m;

bool isp(int n) {
	for (int i = 2 ; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		if (isp(n)){
            cout << "NO\n";
        }
        else{
		for (int i = 2 ; i * i <= n ; i++) {
			if (n % i == 0) {
				a = i;
				m = n / i;
				break;
			} 
		}
		bool k = false;
		for (int i = a + 1 ; i * i <= m; i ++) {
			if (m % i == 0) {
				b = i; c = m / i;
				if (b != c) {
					k = true;
					break;
				}
			}
		}
		if (k) {
			cout << "YES" << '\n';
			cout << a << " " << b << " " << c << '\n';
		}
		else cout << "NO" << '\n';
		}
	}
	return 0;
}