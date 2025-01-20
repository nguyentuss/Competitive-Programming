#include <bits/stdc++.h>

using namespace std;

int n , k;
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n >> k;
		cin >> s;
		int len;
		if (n % 2 == 1) len = n / 2 + 1;
		else len = n / 2;
		int count = 0; 
		for (int i = 0 ; i < len ; i++) {
			if (s[i] != s[n - i - 1]) {
				count ++;
			}
		}
		cout << "Case #" << test << ": " << abs(count - k) << endl;
	}

	return 0;
}