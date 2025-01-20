#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		ll a , b , c; cin >> a >> b >> c;
		ll maximum = max(a , max(b , c));
		if (a == b && b == c) cout << 1 << " " << 1 << " " << 1 << '\n';
		else if (maximum == a && maximum == b) cout << 1 << " " << 1 << " " << maximum - c + 1 << '\n';
		else if (maximum == b && maximum == c) cout << maximum - a + 1 << " " << 1 << " " << 1 << '\n';
		else if (maximum == a && maximum == c) cout << 1 << " " << maximum - b + 1 << " " << 1 << '\n';
		else {
			if (maximum == a) cout << 0 << " ";
			else cout << maximum - a + 1 << " ";
			if (maximum == b) cout << 0 << " ";
			else cout << maximum - b + 1 << " ";
			if (maximum == c) cout << 0 << " ";
			else cout << maximum - c + 1 << " "; 
			cout << '\n';
		}
	}
	return 0;
}