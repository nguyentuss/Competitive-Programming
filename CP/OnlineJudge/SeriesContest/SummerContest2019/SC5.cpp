#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		long long n , m , a , b; 
		cin >> n >> m >> a >> b;
		long long x1 , y1 , x2 , y2 , tmp = b;
		x1 = a / m;
		if (a % m) x1 ++;
		if (x1 % 2 != 0) {
			y1 = (a%m==0?m:a%m);
			b = max(0LL , b - (m - y1));
		}
		else {
			y1 = m - (a%m==0?m:a%m) + 1LL;
			b = max(0LL , b - y1 + 1LL);
		}		
		if (b == 0) {
			x2 = x1;
			if (x1 % 2 != 0) y2 = y1 + tmp;
			else y2 = y1 - tmp;
		}
		else {
			x2 = x1 + b/m;
			if (b % m) x2++;
			if (x2 % 2LL != 0) y2 = (b%m==0?m:b%m);
			else y2 = m - (b%m==0?m:b%m) + 1LL;
		}
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
		cout << (long long) (abs(x1 - x2) + abs(y1 - y2)) << '\n';
	}
	return 0;
}