#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v;
long long maximum = LLONG_MIN;


int check(int x) {	
	int dem = 0;	
	for (int i = 2 ; i * i <= x ; i++) {
		while (x % i == 0) {
			dem ++;
			x /= i;
		} 
	}
	if (x > 1) dem ++;
	return dem;
}

int main(){
	boost;

	int n , x; cin >> n;
	long long total = 0;

	for (int i = 0 ; i < n; i++) {
		cin >> x;
		long long a = check(x);
		total += a;
		v.push_back(a);
		maximum = max(maximum , a);
	}

	cout << total - maximum;

	return 0;
}