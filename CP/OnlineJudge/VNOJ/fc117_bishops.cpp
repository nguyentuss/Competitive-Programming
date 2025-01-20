#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	ll x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2;
	cout << (((x1 + y1) % 2 == (x2 + y2) % 2) ? "yes" : "no");
	return 0;
}