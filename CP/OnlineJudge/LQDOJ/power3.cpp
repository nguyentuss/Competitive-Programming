#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long n , x;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

double myabs(double x)
{
    return ((x>=0)?x:(-x));
}

int main() {
	boost;
	cin >> n;
	while (n --) {
		cin >> x;

		double xo, xn=1, e=1e-18;
		do
	    {
	       xo=xn;
	       xn=(x/xo/xo+2.0*xo)/3.0;
	    }
	    while (myabs(xn-xo)>e);
		if (xn*xn*xn == x) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}