#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("frienum.inp","r",stdin);
#define fo freopen("frienum.out","w",stdout);


int main() { 
	boost;
	fi;fo;

	int a , b; cin >> a >> b;
	string x , y;

	int ans = 0;
	for (int i = a ; i <= b ; i++) {
		x = to_string(i);
		y = x;	
		reverse(y.begin(),y.end());

		int x1 = atoi(x.c_str());
		int y1 = atoi(y.c_str());
		if (__gcd(x1,y1) == 1) ans ++;

	}
	cout << ans;

	return 0;
}