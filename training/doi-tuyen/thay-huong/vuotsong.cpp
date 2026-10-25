#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("vuotsong.inp","r",stdin);
#define fo freopen("vuotsong.out","w",stdout);


int main() {
	boost;
	fi;fo;
	long long n,x,ans = 0; cin >> n;
	vector <int> v;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for (int i = 1 ; i < (int) v.size() ; i++)
		ans += v[i];
	ans += v[0]*(n-2);
	cout << ans;



	return 0;
}