#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("solap.inp","r",stdin);
#define fo freopen("solap.out","w",stdout);

set <int> s;

int main () {
	boost;
	fi;fo;
	int n; cin >> n;
	int x;
	for (int i = 0 ; i < n; i++){
		cin >> x;
		s.insert(x);		
	}

	cout << (int) s.size();

	return 0;
}