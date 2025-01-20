#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;

	int t; cin >> t;
	while (t --) {
		double x , y; cin >> x >> y;
		double a = (double) x + y;
		//if (x == y) 
		double ans = sqrt(pow(a - x ,(double) 2.0F) + pow(0 - y , (double) 2.0F));
		ans *= sqrt(pow(0 - x,(double) 2.0F) + pow(a - y , (double) 2.0F));
		cout << fixed << ans << endl;
	}

	return 0;
}