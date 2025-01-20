#include <iostream>
#include <cmath>

using namespace std;
#define ll long long
#define max (ll) 1e6 +7
ll a[max] = {0} , x[max] = {0} , n ;
ll ans;

ll binarysearch(ll l , ll r){
	ll mid = (l+r)/2;
	ll sum = 0 , sum1 = 0, sum2 = 0;
	for (ll i = 1 ; i <= n ; i++){
		sum += abs((x[i] - mid))*a[i];
		sum1 += abs((x[i] - (mid - 1)))*a[i];
		sum2 += abs((x[i] - (mid + 1)))*a[i];
	}
	if (sum < sum1 && sum >= sum2) return binarysearch(mid+1,r);
	else 
		if (sum >= sum1 && sum < sum2) return binarysearch(l,mid-1);
	else
		if (sum <= sum1 && sum <= sum2) {
			ans = mid;
			return sum;
		}
	return 0;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("dankien.inp","r",stdin);
	freopen("dankien.out","w",stdout);
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (ll i = 1 ; i <= n ; i++)
		cin >> x[i];
	ll maxn = 1e9;
	ll res = binarysearch(1,maxn);
	cout << res << '\n';
	cout << ans;

	return 0;
}