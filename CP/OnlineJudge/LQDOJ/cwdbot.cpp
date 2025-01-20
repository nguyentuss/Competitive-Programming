#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("cwdbot.inp","r",stdin);
#define fo freopen("cwdbot.out","w",stdout);

int main(){
	boost;
	fi;fo;
	unsigned long long n; cin >> n;
	while (n >= 0) {
		if (n % 2 == 0) { 
			unsigned long long x = n / 2;
			if (x % 2 != 0) cout << (x/2)*(x/2+1);
			else cout << (x/2)*(x/2);
			return 0;
		}
		n--;
	}
	return 0;
}