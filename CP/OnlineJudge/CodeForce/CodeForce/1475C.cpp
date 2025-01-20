#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<int , int>

int main(){
	boost;

	int t; cin >> t;

	while (t --) {
		vector <int> men , women;
		map <int , int> ctmen , ctwomen;
		int a , b , k; cin >> a >> b >> k;
		int x ;
		for (int i = 0 ;i < k ; i++){
			cin >> x;
			men.push_back(x);
			ctmen[x] ++;
		}
		for (int i = 0 ; i < k ; i++) {
			cin >> x;
			women.push_back(x);
			ctwomen[x] ++;
		}
		long long ans = 0;
		for (int i = 0 ; i < k ; i++) {
			int num = k - (ctmen[men[i]] - 1) - (ctwomen[women[i]] - 1) - 1;
			ans += num;
		}
		cout << ans / 2 << endl;
	}

	return 0;
}