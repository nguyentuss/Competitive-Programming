#include <iostream>
using namespace std;
#define fast ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define ll long long
#define mod (ll) 1000000007

int main(){
	fast;
	freopen("wc1.inp","r",stdin);
	freopen("wc1.out","w",stdout);	
	ll t; cin >> t;
	while (t--){
		ll n , k ; cin >> n >> k;
			if (k == 1){
				cout << n << endl;
			}
			else {
				ll jump = k , dem = 0;
				while (jump <= n){
					ll sum = 0 , mul = 1;
					ll x = jump;
					while (x > 0){
						ll tam = x % 10;
						sum = sum + tam;
						mul = mul * tam;
						x /= 10;
					}
					if ((sum % k == 0) && (mul % k == 0) && (jump <= n)) {
						dem += 1;
					}
					jump += k;
				}
				cout << dem  << endl;
			}
			

	}
	return 0;
}