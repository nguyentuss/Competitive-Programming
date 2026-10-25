#include <bits/stdc++.h>

using namespace std;

double xa , ya , xb , yb , xc , yc;

double calc(double x , double y) {
	return (ya - yb)*x + (xb - xa)*y + (xa*yb - xb*ya);
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		double x = calc(xc , yc); 
		double minx = min(xa , xb) , maxx = max(xa , xb);
		double miny = min(ya , yb) , maxy = max(ya , yb);
		if (x == 0 && minx <= xc && xc <= maxx && miny <= yc && yc <= maxy)
			cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}