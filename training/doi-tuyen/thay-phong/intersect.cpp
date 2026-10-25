	#include <bits/stdc++.h>

using namespace std;

double xa , ya , xb , yb , xc , yc , xd , yd ;
double a1 , b1 , c1 , a2 , b2 , c2 , D , dx , dy;

double calc(double x , double y , double xa , double ya , double xb , double yb) {
	return (ya - yb)*x + (xb - xa)*y + (xa*yb - xb*ya);
}

bool check(double xo , double yo , double xa , double ya , double xb , double yb) {
	return (min(xa , xb) <= xo && xo <= max(xa , xb)  && min(ya , yb) <= yo && yo <= max(ya , yb));
}

bool pro() {
	double x = calc(xa , ya , xc , yc , xd , yd); 
	if (x == 0 && check(xa , ya , xc , yc , xd , yd)) return 1;
	x = calc(xb , yb , xc , yc , xd , yd); 
	if (x == 0 && check(xb , yb , xc , yc , xd , yd)) return 1;
	x = calc(xc , yc , xa , ya , xb , yb); 
	if (x == 0 && check(xc , yc , xa , ya , xb , yb)) return 1;
	x = calc(xd , yd , xa , ya , xb , yb); 
	if (x == 0 && check(xd , yd , xa , ya , xb , yb)) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >>t;
	while (t--) {
		cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
		if (pro()) {
			cout << "YES" << '\n';
			continue;
		}
		a1 = yb - ya , b1 = xa - xb , c1 = ya*xb - xa*yb;
		a2 = yd - yc , b2 = xc - xd , c2 = yc*xd - xc*yd;
		D = a1*b2 - a2*b1 , dx = c2 * b1 - c1 *b2, dy = a2 * c1 - a1 * c2;
		if (D != 0 && check(dx/D , dy/D , xa , ya , xb , yb) && check(dx/D , dy/D , xc , yc , xd , yd)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}