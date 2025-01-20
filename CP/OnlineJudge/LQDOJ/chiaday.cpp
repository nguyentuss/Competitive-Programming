#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v;

int main(){ 
	boost;
	int n , x; cin >> n;
	long long t1 = 0 , t2 = 0;
	for (int i = 0 ; i < n ;i ++) {
		cin >> x;
		v.push_back(x);
		t2 += x;
	}


	int ans = INT_MAX;
	long long maximum = LLONG_MAX;
	for (int i = 0 ; i < n ; i++) {
		t1 += v[i];
		t2 -= v[i];
		//cout << t1 << " " << t2 << endl;
		if (abs(t1 - t2) < maximum && i != n - 1) {
			if (maximum == abs(t1 - t2)) ans = min(ans , i + 1);
			maximum = min(maximum , abs(t1 - t2));
			ans = i + 1;
		}
	}
	cout << ans;

	return 0;
}