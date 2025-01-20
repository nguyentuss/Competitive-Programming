#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll unsigned long long

ll arr[10000005],sum[10000005];

int main(){
	//boost;
	int n; cin >> n;

	sum[0] = 0;

	for (ll i = 1 ; i <= n ; i++){
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}

	ll ans = 0;

	for (ll i = 1 ; i <= n ; i++) {
		ans += arr[i]*(sum[n] - sum[i]);
	}

	cout << ans;


	return 0;
}