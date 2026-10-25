#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("capso.inp","r",stdin);
#define fo freopen("capso.out","w",stdout);

vector <int> v;

int main () {
	boost;
	fi;fo;
	int n; cin >> n;
	int x;
	for (int i = 0 ; i < n; i++){
		cin >> x;
		v.push_back(x);	
	}

	sort(v.begin() , v.end());

	cout << (long long) max((long long) v[0] * v[1] , (long long) v[n - 1] * v[n - 2]);

	return 0;
}