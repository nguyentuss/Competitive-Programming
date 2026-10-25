#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <fstream>

using namespace std;

int n , x;
vector <int> v;
vector <int> temp;
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	freopen("daysoe.inp","r",stdin);
	freopen("daysoe.out","w",stdout);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	temp = v;
	sort(v.begin() , v.end());
	int maximum = -1 , choose = INT_MAX;
	int count = 0;
	for (int i = 0 ; i < (int) v.size() ; i++) {
		if (v[i] != v[i + 1]) {
			count ++;
			if (count > maximum) {
				maximum = count;
				choose = v[i];
			}
			count = 0;
		}
		else count ++;
	}

	for (int i = 0 ; i < (int) temp.size() ; i++) {
		if (temp[i] == choose) cout << i + 1 << " ";
	}

	return 0;
}