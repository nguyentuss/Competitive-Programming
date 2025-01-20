#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t --){
		int n; cin >> n;
		vector <ll> a(n);
		for (int i = 0 ; i < n ; i++)
			cin >> a[i];
		sort(a.begin(),a.end());
		ll ans = -1e18 ; 
		for (int i = 0 ; i < 5 ; i ++){
			ll pos1 , pos2 , pos3 , pos4 , pos5;
			pos1 = (n - 1 + i) % n;
			pos2 = (n - 2 + i) % n;
			pos3 = (n - 3 + i) % n;
			pos4 = (n - 4 + i) % n;
			pos5 = (n - 5 + i) % n;
			ll val = a[pos1] * a[pos2] * a[pos3] * a[pos4] * a[pos5];
			ans = max(ans,val);
		}
		cout << ans << "\n";
	}
	return 0;
}