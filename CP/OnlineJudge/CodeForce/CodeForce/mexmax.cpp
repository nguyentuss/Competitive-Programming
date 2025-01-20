#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("mexmax.inp","r",stdin);
#define fo freopen("mexmax.out","w",stdout);

long long q , r , x , mod, mex = 0;
int counting[500000];

int main() {
	boost;
	fi;fo; 
	cin >> q >> r;
	memset(counting,0,sizeof(counting));

	for (int i = 0 ; i < q ; i ++) {
		cin >> x;
		mod = x % r;
		counting[mod] ++;
		while (true) {
			mod = mex % r;
			if (counting[mod] == 0) break;
			else {
				counting[mod] -- ;
				mex ++;
			}
		}
		cout << mex << endl;
	}


	return 0;
}