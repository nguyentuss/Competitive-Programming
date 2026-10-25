#include <bits/stdc++.h>

using namespace std;

#define esp (double) (0.0001)

struct pos {
	double x , y;
};
struct triangle {
	pos A;
	pos B;
	pos C;
}tri;

bool fEqual(double a, double b) {
  return (fabs(a - b) < esp) ? 1 : 0;
}

double area(pos A, pos B, pos C) {
   return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

double ABC;

bool checkpos(triangle tri , pos M) {
	double ABM = area(tri.A , tri.B , M);
	double ACM = area(tri.A , tri.C , M);
	double BCM = area(tri.B , tri.C , M);
	double d = (ACM + ABM + BCM) - ABC;
	if (d > 0) return 0;
	if (fEqual(ABM , 0) || fEqual(ACM , 0) || fEqual(BCM , 0)) return 1; 
	return 1;
}

pos a , b , c , m;
int n , ans = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cin >> n;
	tri.A = a , tri.B = b , tri.C = c;
	ABC = area(a , b , c);
	cout << fixed << setprecision(1) << ABC << '\n';
	for (int i = 1 ; i <= n ; i++) {
		cin >> m.x >> m.y;
		ans += checkpos(tri , m);
		//cout << ans;
	}
	cout << ans;
	return 0;
}