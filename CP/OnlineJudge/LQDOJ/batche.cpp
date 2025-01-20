#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<int , int>
#define fi freopen("batche.inp","r",stdin);
#define fo freopen("batche.out","w",stdout);

vector <ii> v;

int main() {
	boost;
	fi;fo;

	int n , a , b; cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> a >> b;
		v.push_back(ii(a,b)); 
	}
	sort(v.begin() , v.end());


	int ans = 0 , minnum = INT_MAX;
	for (int i = 0 ; i < (int) v.size() ; i++) {
		ans = max(ans , v[i].second - v[i].first);
		if (v[i].second >= v[i+1].first && v[i].second <= v[i+1].second){
			minnum = min(minnum , v[i].first);
			//cout << abs(v[i + 1].second - minnum) << endl;
			ans = max(ans ,abs(v[i + 1].second - minnum));
		} 
		else minnum = INT_MAX;
	}

	cout << ans;
	return 0;
}