#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("hcn.inp","r",stdin);
#define fo freopen("hcn.out","w",stdout);

int main(){
	boost;
	fi;fo;
	int t; cin >> t;
	while (t --) {
		vector <int> v;
		int x; 
		for (int i = 0 ; i < 4 ; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end());
		cout << min(v[0] , v[1]) * min(v[2] , v[3]) << endl;
	}

	return 0;
}