#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<int , int>

vector <int> a , b;
vector <ii> v;

int main(){
	boost;

	int n , x; cin >> n;
	
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		b.push_back(x);
	}
	for (int i = 0 ; i < n ; i++) 
		v.push_back(ii(a[i],b[i]));
	sort(v.begin() , v.end());

	int maximum = -1 , ans = 0;
	for (int i = 0 ; i < n; i++) {
		if (v[i].first == v[i + 1].first) maximum = max(maximum,max(v[i].second,v[i+1].second));
		else {
			//cout << maximum;
			maximum = max(maximum , v[i].second);
			ans += maximum;
			maximum = -1;
		}
	}
	cout << ans;

	return 0;
}

