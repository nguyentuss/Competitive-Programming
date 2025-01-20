#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;



vector <long long> v;

map <long long , long long> m;
map <long long , long long>::iterator it;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	long long n , x; cin >> n;
	for (int i = 1 ; i <= n; i ++) {
		cin >> x;
		v.push_back(x);
		m[x - i] ++;
	}
	int choose = -1;
	vector <int> tried;
	for (it = m.begin() ; it != m.end() ; it++) {
		if (it->second >= choose) {
				x = it->first;
				choose = it->second;
		} 
	}
	tried.push_back(x);
	for (it = m.begin() ; it != m.end() ; it++) {
		if (it -> second == choose) tried.push_back(it->first);
	}
	long long minimum = LLONG_MAX;
	long long ans = 0;
	for (int i = 0 ; i < (int) tried.size() ; i++) {
		ans = 0;
		for (int j = 0 ; j < n ; j++) {
			ans += abs(v[j] - tried[i] - (j + 1));
		}
		minimum = min(minimum , ans);
	}
	cout << minimum;
	return 0;
}