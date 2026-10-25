#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("sinhnhat.inp","r",stdin);
#define fo freopen("sinhnhat.out","w",stdout);

map <int , int> m;
map <int , int>::iterator it;

int main () {
	boost;
	fi;fo;
	int n; cin >> n;
	int x;
	for (int i = 0 ; i < n; i++){
		cin >> x;
		m[x] ++;		
	}

	for (it = m.begin() ; it != m.end() ; it ++) 
		cout << it->first << " " << it -> second << endl;

	return 0;
}