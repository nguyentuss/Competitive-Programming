#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> a , b;

int main(){
	boost;

	int n; cin >> n;

	int x;
	for (int i = 0 ; i < 3 ;i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0 ; i < 3 ; i++) {
		cin >> x;
		b.push_back(x);
	}
	long long ans = 0;
	if (a[0] < b[1]) ans += a[0];
	if (a[0] >= b[1]) ans += b[1];
	//cout << ans << endl;
	if (a[1] < b[2]) ans += a[1];
	if (a[1] >= b[2]) ans += b[2];
	//cout << ans << endl;
	if (a[2] < b[0]) ans += a[2];
	if (a[2] >= b[0]) ans += b[0];
	//cout << ans << endl;
	cout << ans;

	return 0;
}