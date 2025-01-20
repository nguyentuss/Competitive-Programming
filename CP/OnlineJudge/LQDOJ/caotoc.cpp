#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("caotoc.inp","r",stdin);
#define fo freopen("caotoc.out","w",stdout);

typedef pair<int,int> ii;


int main() {
	boost;
	fi;fo;
	vector <ii> v;

	int n; cin >> n;

	int x , y;
	for (int i = 0 ; i < n ; i ++) {
		cin >> x >> y;
		v.push_back(ii(x,y));
	}

	sort(v.begin(),v.end());
	for (int i = 0 ; i < (int) v.size() ; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	int maximum = INT_MIN;
	int ans = 0;

	for (int i = 0 ; i < (int) v.size(); i++) {
		maximum = max(maximum,abs(v[i].second)); 
		if (v[i].first != v[i+1].first) {
			ans += maximum;
			maximum = INT_MIN;
		}
	}

	cout << ans;



	return 0;
}