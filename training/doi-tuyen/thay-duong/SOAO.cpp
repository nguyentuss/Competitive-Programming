#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("SOAO.inp","r",stdin);
#define fo freopen("SOAO.out","w",stdout);

int main() {
	boost;
	fi;fo;
	int x;
	vector<int> v;
	for (int i = 0 ; i < 9 ; i++) {
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0 ; i < 9 ; i++) {
		for (int j = i + 1 ; j < 9 ; j ++) 
			for (int k = j + 1 ; k < 9 ; k ++) 
				for (int h = k + 1 ; h < 9 ; h ++) 
					for (int e = h + 1 ; e < 9 ; e++)
						for (int f = e + 1 ; f < 9 ; f ++)
							for (int l = f + 1 ; l < 9 ; l ++) 
		if (v[i] + v[j] + v[k] + v[h] + v[e] + v[f] + v[l] == 100) {
			cout << v[i] << '\n' << v[j] << '\n' << v[k] << '\n' << v[h] << '\n' << v[e] << '\n' << v[f] << '\n' << v[l];
		}
	}


	return 0;
}