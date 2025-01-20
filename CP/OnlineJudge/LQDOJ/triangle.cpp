#include <iostream>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define INF (ll) 1e18;

ll calculator(ll huyen , ll canh1 , ll canh2) {
	ll ans = INF;
	if ((huyen < (canh1 + canh2)) && (huyen > abs(canh1 - canh2))) ans = min(ans ,(ll) 0);	
	else {
		if ((huyen < abs(canh1 - canh2)) && huyen < (canh1 + canh2)) ans = min(ans , (abs(canh1 - canh2) + 1) - huyen);
		if (huyen > (canh1 + canh2)) ans = min(ans ,  abs(huyen - (canh1 + canh2)) + 1);	
	}
	return ans;
}

int main() {
	boost;

	ll a , b , c; cin >> a >> b >> c;


	cout << min(calculator(c,a,b),min(calculator(a,c,b),calculator(b,a,c)));

	return 0;
}