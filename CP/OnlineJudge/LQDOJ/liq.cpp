#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main() {

	int n ,x; 
	vector<int> a;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		a.push_back(x);
	} 
	int maximum ,  m;
	vector <int> d(n,1);
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < i ; j ++){
			if (a[i] > a[j]) {
				d[i] = max(d[i],d[j] + 1);
			}
		}
	}

	int ans = d[0];
	for (int i = 1 ; i < n; i++) ans = max(ans,d[i]);
	cout << ans;
	return 0;
}