#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int ans = 0 , n , m; vector <int> v;

int binarysearch(int x , int pos , vector <int> &v) {
	int l = 0 , r = pos - 1 , mid;
	int find = m - x;
	//cout << find << endl;
	while (l <= r) {
		mid = (l + r)/2;
		//cout << l << " " << r << " " << mid << endl;
		if (v[mid] == find) {
			ans ++;
			//cout << ans << endl;
			return 0;
		}
		else if (v[mid] < find) l = mid + 1;
		else if (v[mid] > find) r = mid - 1;
	}
	return -1;
}

int main() {
	boost;
	//freopen("input.inp","r",stdin);
	//freopen("output.out","w",stdout);
	int t , x ; cin >> t;
	for (int j = 1 ; j <= t ; j++) {
		cin >> n >> m;
		vector <int> v;
		ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end());
		for (int i = 0 ; i < (int) v.size() ; i++) {
			binarysearch(v[i] , i , v);
		}
		cout << ans << endl;
	}

	return 0;
}