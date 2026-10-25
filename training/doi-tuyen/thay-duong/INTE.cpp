#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("INTE.inp","r",stdin);
#define fo freopen("INTE.out","w",stdout);

int main() {
	boost;
	fi; fo;

	int a , b , k;
	int ans = 0;
	cin >> a >> b >> k;

	for (int i = a ; i <= b ; i++) {
		int x = i;
		int dem = 1;
		vector <int> v;
		while (x > 0) {
			v.push_back(x%10);
			x /= 10;
		}
		for (int j = 0 ; j < (int) v.size() - 1 ; j++) {
				if (v[j] == v[j+1]) dem ++;
				else dem = 1 ;
				if (dem == k) {

					ans ++;
					break;
				}
		}
	}

	cout << ans;

	return 0;
}