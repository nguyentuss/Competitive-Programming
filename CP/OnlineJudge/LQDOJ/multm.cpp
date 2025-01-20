#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ll long long

ll n , p , x;

int main() {
	boost;
	cin >> n >> p;
	map <ll,ll> m;
	vector <ll> v;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
		m[x] ++; 
	}
	ll ans = 0;
	//sort (v.begin(),v.end());
	for (int i = 0 ; i < n ; i++){
		if (v[i] % p != 0) ans ++;
		else {
			if (m[v[i]/p] == 0) ans ++;
			else m[v[i]] --;
		}
		//cout << ans << endl;
	} 
	cout << ans;

	return 0;
}