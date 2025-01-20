#include <bits/stdc++.h>

using namespace std;

#define esp (double) (0.00001)

double p[13] , tmp , l , r;
int d;

double f(double x) {
    double res = 0.0;
    for (int i = d ; i >= 0 ; i--) {
    	res = res*x + p[i];
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> d;
	for (int i = 0 ; i <= d ; i++) cin >> p[i];
	l = -1e6 , r = 1e6;
	tmp = f(l);
	while (l <= r) {
		double mid = (l + r)/2;
		double x = f(mid);
		if (abs(x) < esp) {
			cout << trunc(mid*1000);
			return 0;
		} 
		else {
			if (x*tmp < 0.0) r = mid;
			else l = mid;
		}
	}
	return 0;
}