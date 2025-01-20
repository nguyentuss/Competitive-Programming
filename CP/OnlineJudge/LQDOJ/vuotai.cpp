#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <long long> v;

int main(){
	boost;

	int pos = 0;
	long long n , x , k; cin >> n >> k;
	long long maximum = LLONG_MIN , num = LLONG_MIN;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		if (maximum <= max(0LL , x - k) && num < x) {
			num = x;
			maximum = max(0LL , x - k);
			pos = i;
		}
		v.push_back(x);
	}
	long long ans = maximum;
	for (int i = 0 ; i < (int) v.size() ; i++) 
		if (i != pos) ans += v[i];
	cout << ans + 1;
	return 0;
}