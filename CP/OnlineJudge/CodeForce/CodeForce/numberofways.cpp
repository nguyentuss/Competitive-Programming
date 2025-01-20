#include <iostream>

using namespace std;

#define ll long long

int a[500005] , ways[500005] = {0};

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);

	/*freopen("input.inp","r",stdin);	
	freopen("output.out","w",stdout);
	*/
	int n ; cin >> n;
	ll sum = 0;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 0;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	else {
		ll partsum = sum / 3 , prefixsum = 0 , suffixsum = 0 ;
		for (int i = 0 ; i < n  ; i++){
			ways[i] = ways[i-1];
			prefixsum += a[i];
			if (prefixsum == partsum) ways[i] ++;
		}
		for (int i = n - 1 ; i >=  0 ; i --){
			suffixsum += a[i];
			if (suffixsum == partsum) ans += ways[i-2];
		}

	}

	
	cout << ans;
	return 0;
}