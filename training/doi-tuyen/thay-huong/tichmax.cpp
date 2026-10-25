#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("tichmax.inp","r",stdin);
	freopen("tichmax.out","w",stdout);
	ll n ; cin >> n; ll ans = -1e18;
	vector <ll> a(n);
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	for (int i = 0 ; i < 3 ; i++)
	{
		ll pos1 , pos2 , pos3;
		pos1 = (n - 1 + i) % n;
		pos2 = (n - 2 + i) % n;
		pos3 = (n - 3 + i) % n;
		ll val = a[pos1] * a[pos2] * a[pos3];
		ans = max(ans,val);
	}
	cout << ans;
	return 0;
}