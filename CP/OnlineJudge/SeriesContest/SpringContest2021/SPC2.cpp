#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("SPC2.inp","r",stdin);
#define fo freopen("SPC2.out","w",stdout);

int main() {
	boost;
	//fi;fo;
	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) 
			cout << i << " " << 1 << endl;
	}


	return 0;
}