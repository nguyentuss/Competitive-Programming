#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v;
int n , m;

bool check(int x, vector<int> &v) {
	long long total = 0;
	for (int i = 0; i < (int) v.size() ; i ++) {
		if (v[i] > x)
			total += v[i] - x;
		if (total >= m) return true;
	}
	//cout << total << endl;
	return false;
}

int main() {
	boost;
	//freopen("eko.inp","r",stdin);
	//freopen("eko.out","w",stdout);
	int temp, mid;
	int ans = -1;
	cin >> n >> m;
	for (int i = 0 ; i < n ; i ++) {
		cin >> temp;
		v.push_back(temp);
	}
	//sort(v.begin() , v.end());
	long long l = 1 , r = 1000000007;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid, v)) {
			ans = max(mid, ans);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;

	return 0;
}