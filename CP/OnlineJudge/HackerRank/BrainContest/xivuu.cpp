#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll n , firstnum = 1, dist = 1;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n > 1) {
		bool status = false;
		if (n % 2 == 1) status = true;
		n /= 2;
		dist *= 2;
		if (status) {
			firstnum += dist;
			//cout << firstnum << " " << dist << '\n';
		}
	}
	cout << firstnum;
	return 0;
}